package it.giacomobergami.datatypelang.representation.compiler.utils;

import java.util.regex.Pattern;

/**
 * Initial regex statement
 */
public class Match {

    Pattern pat;
    private Match(String pattern) {
        pat = Pattern.compile(pattern);
    }

    public static Match regex(String pat) {
        return new Match(pat);
    }

    public WithValue with(String value) {
        return new WithValue(pat,value);
    }

    public Iterable<GroupMatcher> allWith(String value) {
        return () -> new WithValue(pat,value);
    }



}
