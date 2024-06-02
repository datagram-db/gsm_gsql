package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;


import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;

/**
 * Created by vasistas on 11/12/16.
 */
public class NonTerminal implements TableColumnEntry {

    public NonTerminal(String name) {
        this.name = name;
    }

    private String name;

    @Override
    public String toString() {
        return name;
    }

    @Override
    public boolean isTerminal() {
        return false;
    }

    @Override
    public boolean isNull() {
        return false;
    }

    @Override
    public String getValue() {
        return name;
    }

    @Override
    public OnInput toInput() {
        return null;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof NonTerminal)) return false;

        NonTerminal that = (NonTerminal) o;

        return name != null ? name.equals(that.name) : that.name == null;
    }

    @Override
    public int hashCode() {
        return name != null ? name.hashCode() : 0;
    }

    @Override
    public OnInput asOnInput() {
        return null;
    }
}
