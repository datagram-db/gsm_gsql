package it.giacomobergami.datatypelang.utils.regex;

import java.util.regex.Matcher;

/**
 * Matches a group within a regex
 */
public class GroupMatcher implements AutoCloseable {

    private final Matcher mat;

    public GroupMatcher(Matcher m) {
        mat = m;
    }

    public String getAllGroup() {
        return mat.group();
    }

    public String[] getGroups() {
        String array[] = new String[mat.groupCount()];
        for (int i=0; i<array.length;i++) array[i] = mat.group(i);
        return array;
    }

    public String fromGroupsGet(int i) {
        return mat.group(i);
    }

    public String fromGroupsGet(String i) {
        return mat.group(i);
    }

    @Override
    public void close() {    }
}
