package it.giacomobergami.datatypelang.compiler.parser.cp;

/**
 * Created by vasistas on 11/12/16.
 */
public class NonTerminal implements CP {
    @Override
    public boolean isTerminal() {
        return false;
    }

    @Override
    public boolean isNull() {
        return false;
    }

    public String getId() {
        return id;
    }

    private final String id;

    public NonTerminal(String value) {
        this.id = value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof NonTerminal)) return false;

        NonTerminal that = (NonTerminal) o;

        return id != null ? id.equals(that.id) : that.id == null;
    }

    @Override
    public int hashCode() {
        return id != null ? id.hashCode() : 0;
    }
}
