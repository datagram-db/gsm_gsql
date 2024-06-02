package uk.ncl.giacomobergami;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;

import java.io.IOException;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.locks.ReentrantLock;
import java.util.stream.Collectors;

public class GraphRequest extends FormDataHandler {
    private static final Date maxDate = new Date(Long.MAX_VALUE);

    @Override
    public void handle(HttpExchange he, List<MultiPart> parts) throws IOException {
        Headers requestHeaders = he.getRequestHeaders();
        var entries = requestHeaders.entrySet();
        Date startDate = new Date();
        Date endDate = maxDate;
        for (var entry : entries) {
            if (entry.getKey().equals("start") && (!entry.getValue().isEmpty()))
                startDate = new Date(Date.parse(entry.getValue().get(0)));
            if (entry.getKey().equals("end") && (!entry.getValue().isEmpty()))
                endDate = new Date(Date.parse(entry.getValue().get(0)));
        }

        StringBuilder sb = new StringBuilder();
        var y = parts.stream()
                .map(x->x.value)
                .collect(Collectors.toList());


        try {
            extracted(startDate, endDate, sb, y);
        } catch (Exception e) {
            e.printStackTrace();
        }

        var result = sb.toString();
//        var result = asXMLGradoopResponse(vs, es, gs);
        byte[] response = result.getBytes();
        he.sendResponseHeaders(200, response.length);
        var os = he.getResponseBody();
        os.write(response);
        os.close();
    }

    public static ReentrantLock rl = new ReentrantLock(true);

    public static void extracted(Date startDate, Date endDate, StringBuilder sb, List<String> y) {
        rl.lock();
        try {
            StanfordGraph.reset();
            PropertyGraph.reset();
            //        List<GradoopGraph.Vertex> vs = new ArrayList<>();
//        List<GradoopGraph.Edge> es = new ArrayList<>();
//        List<GradoopGraph.Graph> gs = new ArrayList<>();
            for (Iterator<String> iterator = y.iterator(); iterator.hasNext(); ) {
                String part = iterator.next();
//            var result =
                StanfordGraph
                        .parse(part, startDate, endDate)
                        .asYAMLObjectCollection(sb);
                if (iterator.hasNext())
                    sb.append("~~\n");
//            vs.addAll(result.vertexList);
//            es.addAll(result.edgeList);
//            gs.add(result.header);
            }
        } finally {
            rl.unlock();
        }

    }
}
