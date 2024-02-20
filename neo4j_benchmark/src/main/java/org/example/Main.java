package org.example;

import com.opencsv.CSVWriter;
import com.opencsv.bean.CsvBindByPosition;
import com.opencsv.bean.StatefulBeanToCsv;
import com.opencsv.bean.StatefulBeanToCsvBuilder;
import com.opencsv.exceptions.CsvDataTypeMismatchException;
import com.opencsv.exceptions.CsvRequiredFieldEmptyException;
import org.json.simple.JSONArray;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
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

import org.json.simple.JSONObject;


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
            writer.writeAll(Collections.singleton(new String[]{"Query", "Iterations", "Sentence Length", "Avg. Create (ms)", "Avg. Rewrite (ms)", "Avg. Total (ms)"}));
        }

        beanWriter.write(results);
        writer.close();
    }

    public static class CypherResult {
        @CsvBindByPosition(position = 0)
        private String query;

        @CsvBindByPosition(position = 1)
        private int iterations;

        @CsvBindByPosition(position = 2)
        private int sentenceLength;

        @CsvBindByPosition(position = 3)
        private float create;

        @CsvBindByPosition(position = 4)
        private float rewrite;

        @CsvBindByPosition(position = 5)
        private float total;

        CypherResult(String query, int iterations, int sentenceLength, float create, float rewrite, float total) {
            this.query = query;
            this.iterations = iterations;
            this.sentenceLength = sentenceLength;
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

    public static void createImportJson(Map<String, List<String>> params, Main database, JSONObject jsonObject, String sentence) {
        try (FileWriter file = new FileWriter("temp.json")) {
            file.write(getJsonArrayString(jsonObject, "nodes") + getJsonArrayString(jsonObject, "rels"));
            runTests(params, database, sentence);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (CsvRequiredFieldEmptyException | CsvDataTypeMismatchException e) {
            throw new RuntimeException(e);
        }
    }

    public static void getCypherSentence(Map<String, List<String>> params, Main database) {
        JSONParser parser = new JSONParser();

        InputStream inputStream = Main.class.getClassLoader().getResourceAsStream(params.get("db").getFirst());
        InputStreamReader streamReader = new InputStreamReader(inputStream, StandardCharsets.UTF_8);

        try (BufferedReader reader = new BufferedReader(streamReader);) {
            JSONArray jsonArray = (JSONArray) parser.parse(reader);

            for (int i = 0; i < jsonArray.toArray().length; i++) {
                JSONObject jsonObject = (JSONObject) jsonArray.get(i);
                createImportJson(params, database, (JSONObject) jsonObject.get("cypher"), jsonObject.get("first_sentence").toString());
            }
        } catch (IOException | ParseException e) {
            e.printStackTrace();
        }
    }

    public static void runTests(Map<String, List<String>> params, Main database, String sentence) throws IOException, CsvRequiredFieldEmptyException, CsvDataTypeMismatchException {
        int loopNo = Integer.parseInt(params.get("it").getFirst());
        if (loopNo == 0) {
            loopNo = 1;
        }

        float avgTime = 0;
        float avgCreateTime = 0;
        float avgRewriteTime = 0;
        for (int i = 0; i < loopNo; i++) {
            float createTime = database.runQuery(database.getQuery("queries/import.cypher")); // check for local file path
            float rewriteTime = database.runQuery(database.getQuery("queries/complexRewrite.cypher"));
            float totalTime = createTime + rewriteTime;
            avgTime += totalTime;
            avgCreateTime += createTime;
            avgRewriteTime += rewriteTime;
//            database.writeToCsv(new CypherResult(sentence, sentence.length(), createTime, rewriteTime, totalTime));
            System.out.println("Total execution time: " + totalTime + "ms");
            deleteGraph(database);
        }
        database.writeToCsv(new CypherResult(sentence, loopNo, sentence.length(), avgCreateTime / loopNo, avgRewriteTime/ loopNo, avgTime / loopNo));
        System.out.println("Average execution time " + avgTime / loopNo + "ms");
    }

    public static String getJsonArrayString(JSONObject jsonObject, String arrName) {
        String str = "";

        System.out.println(jsonObject);
        JSONArray msg = (JSONArray) jsonObject.get(arrName);
        Iterator iterator = msg.iterator();
        while (iterator.hasNext()) {
            str = str.concat(iterator.next().toString() + "\n");
        }

        return str;
    }

    public static void deleteGraph(Main database) throws IOException {
        database.runQuery(database.getQuery("queries/delete.cypher"));
        System.out.println("Cleared database");
    }

    public static void main(String... args) throws IOException {
        Map<String, List<String>> params = getArguments(args);

        try (var database = new Main("bolt://localhost:7687", "neo4j", "Neo4j!!!")) {
            getCypherSentence(params, database);
        }
    }
}