package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;


import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;

/**
 * Created by vasistas on 11/12/16.
 */
public class NonTerminal<K extends Enum> implements TableColumnEntry<K> {

    public NonTerminal(String name) {
        this.name = name;
    }

    private String name;

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
    public GrammarTerm<K> asGrammarTerm() {
        return this;
    }
}
