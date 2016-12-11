package it.giacomobergami.datatypelang.representation.compiler.utils;

import it.giacomobergami.datatypelang.utils.Opt;

import java.util.Iterator;
import java.util.Optional;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Determines whether the regex has matched or not with a given string
 */
public class WithValue implements Iterator<GroupMatcher> {

    Pattern pat;
    Matcher mat;

    WithValue(Pattern pat, String regex) {
        this.pat = pat;
        mat = pat.matcher(regex);
    }

    /**
     * Returns the match if it was at least one time match (then, the first time is returned, eventually)
     * @return
     */
    public Opt<GroupMatcher> ifPresentAtLeastOnce() {
        if (mat==null) return Opt.err(); else {
            Matcher toret = mat;
            this.mat = null;
            return toret.find() ? Opt.of(new GroupMatcher(toret)) : Opt.err();
        }
    }

    public GroupMatcher ifFirstPresent() throws NotPresentException {
        if (mat==null || (!mat.find())) throw new NotPresentException();
        return new GroupMatcher(mat);
    }

    public boolean onMatch() {
        if (mat==null) {
            return false;
        } else {
            boolean toret = mat.find();
            mat = null;
            return toret;
        }
    }


    @Override
    public boolean hasNext() {
        return mat.find();
    }

    @Override
    public GroupMatcher next() {
        return new GroupMatcher(mat);
    }
}
