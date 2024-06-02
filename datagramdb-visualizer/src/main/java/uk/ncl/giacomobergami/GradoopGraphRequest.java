package uk.ncl.giacomobergami;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import java.io.IOException;
import java.io.InputStream;
import java.util.Date;

@Deprecated
public class GradoopGraphRequest implements HttpHandler {

    private static final Date maxDate = new Date(Long.MAX_VALUE);

    @Override
    public void handle(HttpExchange he) throws IOException {
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
        int contentLength = Integer.parseInt(requestHeaders.getFirst("Content-length"));
//        System.out.println(""+requestHeaders.getFirst("Content-length"));
        InputStream is = he.getRequestBody();
        byte[] data = new byte[contentLength];
//        int length =
                is.read(data);
//        Headers responseHeaders = he.getResponseHeaders();
//        he.sendResponseHeaders(HttpURLConnection.HTTP_OK, contentLength);
//        OutputStream os = he.getResponseBody();
//        os.write(data);
//        he.close();
//        var result = StanfordGraph.parse(new String(data), startDate, endDate)
//                .asGradoopGraph()
//                .asXMLGradoopResponse();
//        byte[] response = result.getBytes();
//        he.sendResponseHeaders(200, response.length);
//        var os = he.getResponseBody();
//        os.write(response);
//        os.close();
    }
}
