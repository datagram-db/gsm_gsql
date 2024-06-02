package uk.ncl.giacomobergami;

import edu.stanford.nlp.ling.CoreAnnotations;
import edu.stanford.nlp.ling.IndexedWord;
import edu.stanford.nlp.semgraph.SemanticGraph;
import edu.stanford.nlp.semgraph.SemanticGraphCoreAnnotations;
import edu.stanford.nlp.semgraph.SemanticGraphEdge;
import edu.stanford.nlp.util.CoreMap;
import org.apache.commons.lang3.tuple.Pair;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class StanfordGraph {

    private static AtomicInteger currentGraphId = new AtomicInteger(0);
    public static PropertyGraph parse(String text, Date start, Date end) {
        PropertyGraph graph = new PropertyGraph(currentGraphId.getAndIncrement(), start, end);
//        text = text;
        List<CoreMap> sentences = StanfordPipeline.annotate(text).get(CoreAnnotations.SentencesAnnotation.class);
        for(CoreMap sentence: sentences) {
            visit(graph, sentence.get(SemanticGraphCoreAnnotations.CollapsedCCProcessedDependenciesAnnotation.class));
//            int prevMaxVertex = graph.maxVertexId();
        }
        return graph;
    }


    private static void visit(PropertyGraph graph, SemanticGraph semanticGraph) {
        Set<Integer> visitedVertices = new HashSet<>();
        Set<Integer> negations = new HashSet<>();
        {
            Collection<IndexedWord> rootNodes = semanticGraph.getRoots();
            for (IndexedWord w : rootNodes) {
                vertex(graph, w, semanticGraph, visitedVertices, true, negations);
            }
        }
    }

    private static boolean vertex(PropertyGraph graph, IndexedWord v, SemanticGraph semanticGraph, Set<Integer> visitedVertices, boolean isRoot, Set<Integer> negations) {
        if (graph == null)
            System.err.println("ERROR!");
        String value = v.value();
        String tag = v.tag();
        boolean isNegation = false;

        String stemmed = v.lemma();
        String nonWord = v.originalText();
        int begin = v.beginPosition();
        int end = v.endPosition();
        int index = v.get(CoreAnnotations.IndexAnnotation.class);
        visitedVertices.add(index);

        boolean hasWord = (!value.equals(tag));
        var vertexIndex = graph.newVertex(index);
        if (vertexIndex == null)
            System.err.println("ERROR!");

        boolean isPassive = false;
        if (tag.equals("VBN")) {
            for (SemanticGraphEdge e :
                    semanticGraph.outgoingEdgeList(v)) {
                if (e.getRelation().getShortName().contains("aux")) {
                    isPassive = true;
                    break;
                }
            }
        }

        if (tag.equals("DT")) {
            tag = "det";
        } else if (tag.equals("EX")) {
            tag = "∃";
        } else if (tag.equals("JJ")) {
        } else if (tag.equals("JJR") || tag.equals("RBR")) {
            tag = "cmp";
        } else if (tag.equals("JJS") || tag.equals("RBS")) {
            tag = "aggregation";
        } else if (tag.equals("NNS")) {
            tag = "noun";
            vertexIndex.update("specification","common");
            vertexIndex.update("number","plural");
        } else if (tag.equals("NN")) {
            tag = "noun";
            vertexIndex.update("specification","common");
            vertexIndex.update("number","singular");
        } else if (tag.equals("NNP")) {
            tag = "noun";
            vertexIndex.update("specification","proper");
            vertexIndex.update("number","singular");
        } else if (tag.equals("NNPS")) {
            tag = "noun";
            vertexIndex.update("specification","proper");
            vertexIndex.update("number","plural");
        } else if (tag.equals("WDT")) {
            tag = "var";
        } else if (tag.startsWith("VB")) {
            tag = "verb";
        }
        if (stemmed.equals("not") || stemmed.equals("no")) {
            value = stemmed;
            tag = "NEG";
            isNegation = true;
            negations.add(index);
        }
        Pair<String, String> cp = QuerySemantics.extended_semantics.resolve(tag, hasWord ? value : nonWord);
        tag = cp.getKey();
        value = cp.getValue();
//        if (value.contains("eaten"))
//            System.out.println("DEBUG");
        vertexIndex.addLabel(tag);
        if (isRoot) vertexIndex.addLabel("root");
        vertexIndex.addValue(value);
//        vertexIndex.update("value",value);
        if (!value.equals(stemmed)) vertexIndex.update("lemma",stemmed);
        vertexIndex.update("pos", index+"");
        vertexIndex.update("begin", begin+"");
        vertexIndex.update("end", end+"");

        for (SemanticGraphEdge e :
                semanticGraph.outgoingEdgeList(v)) {
            edge(graph, index, e, semanticGraph, visitedVertices, negations, isPassive);
        }
        return isNegation;
    }

    private static void edge(PropertyGraph graph, int srcId, SemanticGraphEdge edge, SemanticGraph semanticGraph, Set<Integer> visitedVertices, Set<Integer> negations, boolean isPassive) {
        Integer targetId = edge.getTarget().get(CoreAnnotations.IndexAnnotation.class);
        //Checking if it has a case
        String role = GetEdgeType.getInstance().apply(edge).toString();

        //Getting Specific
//        String shortName = edge.getRelation().getShortName();
//        String[] ar = shortName.split(":");
//        String specific = null;
//        if (ar.length==2) {
//            specific = ar[1];
//        } else
//            specific = edge.getRelation().getSpecific();
//        if (specific != null)
//            edgeIndex.update("specification",specific);

        if (!visitedVertices.contains(targetId)) {
            vertex(graph, edge.getTarget(), semanticGraph, visitedVertices, false, negations);
        }

        var edgeIndex = graph.newEdge(srcId, targetId);
        if (negations.contains(targetId))
            edgeIndex.addLabel("neg");
//        if (specific != null)
//            edgeIndex.addLabel(role+":"+specific);
        else {
            var R = role.replace(":", "_");
            if (isPassive && (R.equals("nsubj") || R.equals("csubj") || R.equals("aux"))) {
                R = R+"pass";
            }
            edgeIndex.addLabel(R);
        }
    }

    public static void reset() {
        currentGraphId.set(0);
    }
}
