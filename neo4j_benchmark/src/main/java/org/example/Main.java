package org.example;

import com.opencsv.CSVWriter;
import com.opencsv.bean.CsvBindByPosition;
import com.opencsv.bean.StatefulBeanToCsv;
import com.opencsv.bean.StatefulBeanToCsvBuilder;
import com.opencsv.exceptions.CsvDataTypeMismatchException;
import com.opencsv.exceptions.CsvRequiredFieldEmptyException;
import org.neo4j.driver.AuthTokens;
import org.neo4j.driver.Driver;
import org.neo4j.driver.GraphDatabase;
import org.neo4j.driver.Query;
import org.neo4j.driver.summary.ResultSummary;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.concurrent.TimeUnit;


public class Main implements AutoCloseable {
    private final Driver driver;

    public Main(String uri, String user, String password) {
        driver = GraphDatabase.driver(uri, AuthTokens.basic(user, password));
    }

    @Override
    public void close() throws RuntimeException {
        driver.close();
    }

    public long benchmark(ResultSummary result) {
        return result.resultAvailableAfter(TimeUnit.MILLISECONDS);
    }

    public long runQuery(String queryString) {
        try (var session = driver.session()) {
            var runQuery = session.executeWrite(tx -> {
                var query = new Query(queryString);
                return tx.run(query).consume();
            });

            return benchmark(runQuery);
        }
    }

    public String getQuery(String filePath) throws IOException {
        String query = "";

        InputStream inputStream = Main.class.getClassLoader().getResourceAsStream(filePath);
        InputStreamReader streamReader = new InputStreamReader(inputStream, StandardCharsets.UTF_8);
        BufferedReader reader = new BufferedReader(streamReader);
        for (String line; (line = reader.readLine()) != null;) {
            query = query.concat(" " + line);
        }
        return query;
    }

    public void writeToCsv(CypherResult cypherResult) throws IOException, CsvRequiredFieldEmptyException, CsvDataTypeMismatchException {
        String csv = "results.csv";
        CSVWriter writer = new CSVWriter(new FileWriter(csv, true));



        StatefulBeanToCsvBuilder<CypherResult> builder = new StatefulBeanToCsvBuilder<>(writer);
        StatefulBeanToCsv<CypherResult> beanWriter = builder.build();

        List<CypherResult> results = new ArrayList<>();
        results.add(cypherResult);

        // If file doesn't exist create the header
        List<String> fileStream = Files.readAllLines(Paths.get(csv));
        int noOfLines = fileStream.size();
        if (noOfLines == 0) {
            writer.writeAll(Collections.singleton(new String[]{"Query", "Create (ms)", "Rewrite (ms)", "Total (ms)"}));
        }

        beanWriter.write(results);
        writer.close();
    }

    public static class CypherResult {
        @CsvBindByPosition(position = 0)
        private String query;

        @CsvBindByPosition(position = 1)
        private long create;

        @CsvBindByPosition(position = 2)
        private long rewrite;

        @CsvBindByPosition(position = 3)
        private long total;

        CypherResult(String query, long create, long rewrite, long total) {
            this.query = query;
            this.create = create;
            this.rewrite = rewrite;
            this.total = total;
        }
    }

    public static Map<String, List<String>> getArguments(String[] args) {
        final Map<String, List<String>> params = new HashMap<>();

        List<String> options = null;
        for (int i = 0; i < args.length; i++) {
            final String a = args[i];

            if (a.charAt(0) == '-') {
                if (a.length() < 2) {
                    System.err.println("Error at argument " + a);
                    return params;
                }

                options = new ArrayList<>();
                params.put(a.substring(1), options);
            }
            else if (options != null) {
                options.add(a);
            }
            else {
                System.err.println("Illegal parameter usage");
                return params;
            }
        }

        return params;
    }

    public static void runQueries(Map<String, List<String>> params, Main database) throws CsvRequiredFieldEmptyException, CsvDataTypeMismatchException, IOException {
        int loopNo = Integer.parseInt(params.get("it").getFirst());
        if (loopNo == 0) {
            loopNo = 1;
        }

        String queryType = params.get("query").getFirst();

        float avgTime = 0;
        for (int i = 0; i < loopNo; i++) {
//            long createTime = database.runQuery(database.getQuery("queries/" + queryType + "Create.cypher"));
            long createTime = database.runQuery(database.getQuery("queries/" + queryType + "Import.cypher"));
            long rewriteTime = database.runQuery(database.getQuery("queries/" + queryType + "Rewrite.cypher"));
            long totalTime = createTime + rewriteTime;
            avgTime += totalTime;
            database.writeToCsv(new CypherResult(queryType, createTime, rewriteTime, totalTime));
            System.out.println("Total execution time: " + totalTime + "ms");
            deleteGraph(database);
        }
        System.out.println("Average execution time " + avgTime / loopNo + "ms");
    }

    public static void deleteGraph(Main database) throws IOException {
        database.runQuery(database.getQuery("queries/delete.cypher"));
        System.out.println("Cleared database");
    }

    public static void main(String... args) throws IOException {
        Map<String, List<String>> params = getArguments(args);

        try (var database = new Main("bolt://localhost:7687", "neo4j", "Neo4j!!!")) {
            runQueries(params, database);

//            boolean loop = true;
//            boolean logging = true;
//
//            while (loop) {
//                Scanner myObj = new Scanner(System.in);  // Create a Scanner object
//                System.out.println("Pick a query:");
//                System.out.println("(1) Non-recursive (Alice and Bob play cricket)");
//                System.out.println("(2) Recursive (Matt and Tray believe that either Alice and Bob and Carl play cricket or Carl and Dan will not have a way to amuse themselves)");
//                System.out.println("(3) Clear graph");
//                System.out.println("(4) Toggle logging (" + logging + ")");
//                System.out.println("(q) Quit");
//
//                String input = myObj.nextLine();  // Read user input
//                switch (input) {
//                    case "1":
//                        int loopNo = Integer.parseInt(params.get("it").getFirst());
//                        if (loopNo == 0) {
//                            loopNo = 1;
//                        }
//
//                        for (int i = 0; i < loopNo; i++) {
//                            long simpleCreateTime = database.runQuery(database.getQuery("queries/simpleCreate.cypher"));
//                            long simpleRewriteTime = database.runQuery(database.getQuery("queries/simpleRewrite.cypher"));
//                            long simpleTotal = simpleCreateTime + simpleRewriteTime;
//                            if (logging) {
//                                database.writeToCsv(new CypherResult("Simple", simpleCreateTime, simpleRewriteTime, simpleTotal));
//                            }
//                            System.out.println("Total execution time: " + simpleTotal + "ms");
//                            deleteGraph(database);
//                        }
//
//                        break;
//                    case "2":
//                        long complexCreateTime = database.runQuery(database.getQuery("queries/complexCreate.cypher"));
//                        long complexRewriteTime = database.runQuery(database.getQuery("queries/complexRewrite.cypher"));
//                        long complexTotal = complexCreateTime + complexRewriteTime;
//                        if (logging) {
//                            database.writeToCsv(new CypherResult("Complex", complexCreateTime, complexRewriteTime, complexTotal));
//                        }
//                        System.out.println("Total execution time: " + complexTotal + "ms");
//                        break;
//                    case "3":
//                        deleteGraph(database);
//                        break;
//                    case "4":
//                        logging = !logging;
//                        break;
//                    case "q":
//                        loop = false;
//                        break;
//                }
//            }
        } catch (CsvRequiredFieldEmptyException | CsvDataTypeMismatchException e) {
            throw new RuntimeException(e);
        }
    }
}