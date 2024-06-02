package uk.ncl.giacomobergami;

import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import org.apache.commons.lang3.tuple.ImmutablePair;
import org.apache.commons.lang3.tuple.Pair;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class QuerySemantics {
    private JsonObject obj;
    public static final QuerySemantics extended_semantics = new QuerySemantics();
    private QuerySemantics() {
        JsonParser parser = new JsonParser();
        ClassLoader classLoader = getClass().getClassLoader();
        File file = new File(classLoader.getResource("groups.json").getFile());
        try {
            obj = parser.parse(new FileReader(file)).getAsJsonObject();
        } catch (FileNotFoundException e) {
            obj = null;
        }
    }

    public Pair<String,String> resolve(String tag, String value) {
//        if (obj.has(tag)) {
//            JsonElement k = obj.get(tag);
//            if (k.isJsonObject()) {
//                JsonObject ta = k.getAsJsonObject();
//                if (ta.has(value)) {
//                    JsonArray arr = ta.get(value).getAsJsonArray();
//                    return new ImmutablePair<>(arr.get(0).getAsString(),arr.get(1).getAsString());
//                }
//            }
//        }
        return new ImmutablePair<>(tag,value);
    }

}
