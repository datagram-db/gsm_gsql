package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * This class is used both as a $ for the table (no input is read)
 * and hence as a \Varepsilon asTableColumnValue from the input. Is both an input element and a grammar term,
 * since the table is defined on grammar terms
 */
public class Varepsilon<K extends Enum> implements OnInput<K>, TableColumnEntry<K> {
    @Override
    public boolean isEmpty() {
        return true;
    }

    @Override
    public TableColumnEntry<K> asTableColumnValue() {
        return this;
    }

    @Override
    public boolean isTerminal() {
        return true;
    }
    @Override
    public boolean isNull() {
        return false;
    }
    @Override
    public String getValue() {
        return null;
    }

    @Override
    public GrammarTerm<K> asGrammarTerm() {
        return null;
    }
}
