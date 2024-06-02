package uk.ncl.giacomobergami;

import org.apache.commons.lang3.tuple.ImmutablePair;
import org.apache.commons.lang3.tuple.Pair;
import org.json.simple.JSONArray;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

public class PropertyGraph {

    private final JSONArray graphId;

    private static AtomicInteger incrementalVertexId = new AtomicInteger(0);
    private static AtomicInteger incrementalEdgeID = new AtomicInteger(0);

    private static final Map<Pair<Integer, Integer>, Integer> graph_vertex_to_vertex_id = new ConcurrentHashMap<>();
    private static final Map<Pair<Integer, Pair<Integer, Integer>>, Integer> graph_edge_to_edge_id = new ConcurrentHashMap<>();

    private final JSONArray tx_val;
    private HashMap<Integer, Vertex> vertices;
    private HashMap<Pair<Integer, Integer>, Vertex> edges;

    public static void reset() {
        incrementalVertexId.set(0);
        incrementalEdgeID.set(0);
        graph_vertex_to_vertex_id.clear();
        graph_edge_to_edge_id.clear();
    }

//    @Deprecated
//    public GradoopGraph.Graph asGradoopGraphHeader() {
//        return new GradoopGraph.Graph((Integer)graphId.get(0),
//                "Sentence-"+graphId.get(0),
//                new JSONObject().toJSONString(),
//                tx_val.toJSONString(),
//                tx_val.toJSONString()
//                );
//    }

//    @Deprecated
//    public GradoopGraph.Vertex asGradoopVertex(Vertex localV) {
//        return new GradoopGraph.Vertex(localV.id,
//                localV.labels.toJSONString(),
//                localV.properties.toJSONString(),
//                graphId.toJSONString(),
//                tx_val.toJSONString(),
//                tx_val.toJSONString()
//                );
//    }

//    @Deprecated
//    public GradoopGraph.Edge asGradoopEdge(int src, int dst) {
//        var cp = new ImmutablePair<>(src, dst);
//        var cp2 = new ImmutablePair<>((Integer)graphId.get(0), (Pair<Integer,Integer>)cp);
//        var edgeId = graph_edge_to_edge_id.get(cp2);
//        var localV = edges.get(cp);
////        var edgeId = ecounter.get(cp);
//        if (localV == null) return null;
//        return new GradoopGraph.Edge(edgeId,
//                src,
//                dst,
//                localV.labels.toJSONString(),
//                localV.properties.toJSONString(),
//                graphId.toJSONString(),
//                tx_val.toJSONString(),
//                tx_val.toJSONString()
//                );
//    }

//    @Deprecated
//    public GradoopGraph asGradoopGraph() {
//        var g = new GradoopGraph(asGradoopGraphHeader());
//        for (var v : vertices.values())
//            g.addVertex(asGradoopVertex(v));
//        for (var cp : edges.keySet())
//            g.addEdge(asGradoopEdge(cp.getKey(), cp.getValue()));
//        return g;
//    }

    public void asYAMLObjectCollection(StringBuilder os) {
        HashMap<Integer, YAMLObject> map = new HashMap<>();
        for (var x : vertices.values()) {
            map.put((int)x.id, new YAMLObject(x));
        }
        for (var e :edges.entrySet()) {
            String start = vertices.get(e.getKey().getKey()).xi.get(0);
            long startId = vertices.get(e.getKey().getKey()).id;
            String rel = e.getValue().labels.get(0);
            String end = vertices.get(e.getKey().getValue()).xi.get(0);
            long endId = vertices.get(e.getKey().getValue()).id;
//            String output = String.format("(%s, %s)--[%s]->(%s, %s)\n", startId, start, rel, endId, end);
//            os.append(output);
//            System.out.println(output);
//            System.out.println(vertices.get(e.getKey().getKey()).xi.get(0)+"--["+e.getValue().labels.get(0)+"]->"+vertices.get(e.getKey().getValue()).xi.get(0));
            if (!e.getValue().xi.isEmpty())
                System.exit(1);
            if (!e.getValue().properties.isEmpty())
                System.exit(2);
            if (e.getValue().labels.size()==0)
                System.exit(3);
            var ref = map.get(e.getKey().getKey()).phi;
            var contL = e.getValue().labels.get(0);
            List<YAMLObject.Content> cl;
            if (!ref.containsKey(contL)) {
                cl = new ArrayList<>();
                ref.put(contL, cl);
            } else {
                cl = ref.get(contL);
            }
            cl.add(new YAMLObject.Content(1.0, e.getKey().getValue().longValue()));
        }
        ConvertingMap mappe = new ConvertingMap();
//        os.append("§");
        map.values().forEach(x -> os.append(x.toString(mappe)));
    }


    public PropertyGraph(int graphId, Date start, Date end) {
        this.graphId = new JSONArray();
//        ecounter = new HashMap<>();
        this.graphId.add(graphId);
        tx_val = new JSONArray();
        tx_val.add(start.toString());
        tx_val.add(end.toString());
        vertices = new HashMap<>();
        edges = new HashMap<>();
    }

    public Vertex newVertex(int i) {
        var cp2 = new ImmutablePair<>((Integer) graphId.get(0), i);
        if (!graph_vertex_to_vertex_id.containsKey(cp2)) {
            var index = graph_vertex_to_vertex_id.computeIfAbsent(cp2, x -> incrementalVertexId.getAndIncrement());
            var newAlloc = new Vertex(index);
//            maxInt = Math.max(maxInt, index);
            vertices.putIfAbsent(index, newAlloc);
            return newAlloc;
        } else {
            return vertices.get(graph_vertex_to_vertex_id.get(cp2));
        }
    }

    public Vertex newEdge(int srcId, int targetId) {
        int finalSrc;
        int finalDst;
        {
            var srcCp = new ImmutablePair<>((Integer) graphId.get(0), srcId);
            if (!graph_vertex_to_vertex_id.containsKey(srcCp)) return null;
            finalSrc =graph_vertex_to_vertex_id.get(srcCp);
        }
        {
            var dstCp = new ImmutablePair<>((Integer) graphId.get(0), targetId);
            if (!graph_vertex_to_vertex_id.containsKey(dstCp)) return null;
            finalDst =graph_vertex_to_vertex_id.get(dstCp);
        }
        var cp = new ImmutablePair<>(srcId, targetId);
        var cp2 = new ImmutablePair<>((Integer)graphId.get(0), (Pair<Integer,Integer>)cp);
        var cp3 = new ImmutablePair<>(finalSrc, finalDst);
        if (!graph_edge_to_edge_id.containsKey(cp2)) {
            var edgeCount = graph_edge_to_edge_id.computeIfAbsent(cp2, x -> incrementalEdgeID.getAndIncrement());
            var newAlloc = new Vertex(edgeCount);
            edges.put(cp3, newAlloc);
            return newAlloc;
        } else {
            return edges.get(cp3);
        }
    }

    public static class Vertex {
        long id;
        Map<String, String> properties;
        List<String>  labels;
        List<String> xi;

        public Vertex(long id) {
            this.id = id;
            properties = new HashMap<>();
            labels = new ArrayList<>();
            xi = new ArrayList<>();
        }

        public void addValue(String x) {
            xi.add(x);
        }

        public void update(String specification, String common) {
            properties.put(specification, common);
        }


        public void addLabel(String tag) {
            labels.add(tag);
//            labels = new ArrayList<>(new HashSet<>(labels));
        }
    }

}
