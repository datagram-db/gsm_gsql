package uk.ncl.giacomobergami;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import org.apache.commons.fileupload.MultipartStream;
import org.apache.commons.lang3.StringEscapeUtils;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;

import java.io.*;
import java.nio.charset.Charset;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

// Source: https://gist.github.com/JensWalter/0f19780d131d903879a2
public abstract class FormDataHandler implements HttpHandler {

    private String escape(String raw) {
//        return StringEscapeUtils.unescapeJava(raw);
////        return JSONObject.escape(raw);
        String escaped = raw.substring(1, raw.length()-1);
        escaped = escaped.replace("\\\\", "\\");
        escaped = escaped.replace("\\\"", "\"");
        escaped = escaped.replace("\\b", "\b");
        escaped = escaped.replace("\\f", "\f");
        escaped = escaped.replace("\\n", "\n");
        escaped = escaped.replace("\\r", "\r");
        escaped = escaped.replace("\\t", "\t");
        // TODO: escape other non-printing characters using uXXXX notation
        return escaped;
    }

    @Override
    public void handle(HttpExchange httpExchange) throws IOException {
        Headers headers = httpExchange.getRequestHeaders();
        String contentType = headers.getFirst("Content-Type");
        if(contentType.startsWith("multipart/form-data")){

//            byte[] boundary = "--AaB03x".getBytes();


            //found form data
            int contentLength = Integer.parseInt(headers.getFirst("Content-length"));
            String boundary = contentType.substring(contentType.indexOf("boundary=")+9);
            InputStream is = httpExchange.getRequestBody();
            byte[] data = new byte[contentLength];
//        int length =
            is.read(data);

            var s = new String(data);

            ByteArrayInputStream content = new ByteArrayInputStream(s.getBytes());
            MultipartStream multipartStream =
                    new MultipartStream(content, boundary.getBytes());

            var list = new ArrayList<MultiPart>();
            boolean nextPart = multipartStream.skipPreamble();
//            String header2 = multipartStream.readHeaders();
            while (nextPart) {
                MultiPart p = new MultiPart();
                String header = multipartStream.readHeaders();
                String headers2[] = header.split(";");
                Map<String, String> map = new HashMap<>();
                for (int i = 1; i<headers2.length; i++) {
                    var kv = headers2[i].strip();
                    int splitIdx = kv.indexOf('=');
                    String key = kv.substring(0, splitIdx);
                    String value = escape(kv.substring(splitIdx+1));
                    map.put(key, value);
                }
                OutputStream output = new OutputStream() {
                    private StringBuilder string = new StringBuilder();

                    @Override
                    public void write(int b) throws IOException {
                        this.string.append((char) b );
                    }

                    //Netbeans IDE automatically overrides this toString()
                    public String toString() {
                        return this.string.toString();
                    }
                };
                multipartStream.readBodyData(output);
                nextPart = multipartStream.readBoundary();
                p.value = output.toString();
                p.filename = map.get("filename");
                p.name = map.get("name");
                list.add(p);
            }


            handle(httpExchange,list);
        }else{
            //if no form data is present, still call handle method
            handle(httpExchange,null);
        }
    }

    public abstract void handle(HttpExchange httpExchange,List<MultiPart> parts) throws IOException;

    public static class MultiPart {
//        public PartType type;
//        public String contentType;
        public String name;
        public String filename;
        public String value;
//        public byte[] bytes;
    }

//    public enum PartType{
//        TEXT,FILE
//    }
}
