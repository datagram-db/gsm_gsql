package it.giacomobergami.datatypelang.utils.regex;

import java.util.regex.Pattern;

/**
 * Initial regex statement
 */
public class Match {

    Pattern pat;
    private Match(String pattern) {
        pat = Pattern.compile(pattern);
    }
    private Match(Pattern pat) {
        this.pat = pat;
    }

    public static Match patterns(Pattern pat) {
        return new Match(pat);
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
