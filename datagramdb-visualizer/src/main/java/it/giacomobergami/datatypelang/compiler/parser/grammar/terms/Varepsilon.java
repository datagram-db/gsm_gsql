package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;

/**
 * This class is used both as a $ for the table (no input is read)
 * and hence as a \Varepsilon asTableColumnValue from the input. Is both an input element and a grammar term,
 * since the table is defined on grammar terms
 */
public class Varepsilon<K extends Enum> implements OnInput, TableColumnEntry {
    @Override
    public boolean isEmpty() {
        return true;
    }

    @Override
    public TableColumnEntry asTableColumnValue() {
        return this;
    }

    @Override
    public String getType() {
        return null;
    }

    @Override
    public GrammarTerm asGrammarTerm() {
        return this;
    }

    @Override
    public boolean isTerminal() {
        return true;
    }
    @Override
    public boolean isNull() {
        return true;
    }
    @Override
    public String getValue() {
        return null;
    }

    @Override
    public OnInput toInput() {
        return this;
    }

    @Override
    public OnInput asOnInput() {
        return this;
    }


    @Override
    public String toString() {
        return "$";
    }

    @Override
    public int hashCode() {
        return 0;
    }

    @Override
    public boolean equals(Object o) {
        return o instanceof Varepsilon;
    }
}
