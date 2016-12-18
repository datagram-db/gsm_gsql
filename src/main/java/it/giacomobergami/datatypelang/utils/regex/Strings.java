package it.giacomobergami.datatypelang.utils.regex;

import java.util.regex.Matcher;

/**
 * Created by vasistas on 18/12/16.
 */
public class Strings {

    public static String unquote(String snippet) {
        String tmp = snippet.substring(1,snippet.length()-1);
        return tmp.replaceAll(Matcher.quoteReplacement("\\\\\""),"\"");
    }

}
