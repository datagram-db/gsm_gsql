package uk.ncl.giacomobergami;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.dataformat.csv.CsvMapper;
import com.fasterxml.jackson.dataformat.csv.CsvSchema;
import com.fasterxml.jackson.dataformat.xml.XmlMapper;

import java.io.IOException;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.List;

@Deprecated
public class GradoopGraph {
    private final static CsvSchema schema = CsvSchema.emptySchema()
            .withColumnSeparator(';'); // instead of comma
    private final static CsvMapper CSV_MAPPER = new CsvMapper();
    private final static XmlMapper xmlMapper = new XmlMapper();
    final Graph header;

    List<Vertex> vertexList;
    List<Edge> edgeList;

    public GradoopGraph(Graph graph) {
        header = graph;
        vertexList = new ArrayList<>();
        edgeList = new ArrayList<>();
    }

    public static class GradoopXMLOut {
        public String vertexFile;
        public String edgeFile;
        public String headers;

        public GradoopXMLOut(String vertexFile, String edgeFile, String headers) {
            this.vertexFile = vertexFile;
            this.edgeFile = edgeFile;
            this.headers = headers;
        }
    }

//    public String edgeList()  {
//        try (StringWriter strW = new StringWriter()) {
//            var w = CSV_MAPPER.writerWithSchemaFor(Edge.class).writeValues(strW);
//            edgeList.forEach( x -> {
//                try {
//                    w.write(x);
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            });
//            w.close();
//            var s = strW.toString();
//            return s;
//        } catch (IOException e) {
//            e.printStackTrace();
//            return "";
//        }
//    }

    public static <T> String serialiseCollection(Class<T> clazz,
                                                 Iterable<T> ls) {
        try (StringWriter strW = new StringWriter()) {
            CsvSchema schema = CSV_MAPPER
                    .typedSchemaFor(clazz)
                    .withHeader()
                    .withColumnReordering(true);
            var w = CSV_MAPPER
                    .writerFor(clazz)
                    .withSchema(schema)
                    .writeValues(strW);
            ls.forEach( x -> {
                try {
                    w.write(x);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
            w.close();
            var s = strW.toString();
            return s;
        } catch (IOException e) {
            e.printStackTrace();
            return "";
        }
    }

//    public String vertexList()  {
//        try (StringWriter strW = new StringWriter()) {
//            var w = CSV_MAPPER.writerWithSchemaFor(Vertex.class).writeValues(strW);
//            vertexList.forEach( x -> {
//                try {
//                    w.write(x);
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            });
//            w.close();
//            var s = strW.toString();
//            return s;
//        } catch (IOException e) {
//            e.printStackTrace();
//            return "";
//        }
//    }

    public void addVertex(Vertex v) {
        vertexList.add(v);
    }

    public void addEdge(Edge e) {
        edgeList.add(e);
    }


    public static String asXMLGradoopResponse(List<Vertex> v, List<Edge> e, List<Graph> g) {
        try {
            return xmlMapper.writeValueAsString(new GradoopXMLOut(serialiseCollection(Vertex.class, v),
                    serialiseCollection(Edge.class, e),
                    serialiseCollection(Graph.class, g)));
        } catch (JsonProcessingException ex) {
            ex.printStackTrace();
            return "";
        }
    }

//    @JsonPropertyOrder({ "id", "srcId", "trgId", "label", "properties", "graphs", "tx", "val"})
    public static class Edge  {
    public long id;
    public long srcId;
    public long trgId;
    public String label;
    public String properties;
    public String graphs;
    public String tx;
    public String val;


        public Edge(long id, long srcId, long trgId, String label, String properties, String graphs, String tx, String val) {
            this.id = id;
            this.label = label;
            this.properties = properties;
            this.graphs = graphs;
            this.tx = tx;
            this.val = val;
            this.srcId = srcId;
            this.trgId = trgId;
        }
    }

    public static class Graph {
        public long id;
        public String label;
        public String properties;
        public String tx;
        public String val;

        public Graph(long id, String label, String properties, String tx, String val) {
            this.id = id;
            this.label = label;
            this.properties = properties;
            this.tx = tx;
            this.val = val;
        }
    }

//    @JsonPropertyOrder({ "id", "label", "properties", "graphs", "tx", "val"})
    public static class Vertex {
    public long id;
    public String label;
    public String properties;
    public String graphs;
    public String tx;
    public String val;

        public Vertex(long id, String label, String properties, String graphs, String tx, String val) {
            this.id = id;
            this.label = label;
            this.properties = properties;
            this.graphs = graphs;
            this.tx = tx;
            this.val = val;
        }
    }
}
