package it.giacomobergami.datatypelang.compiler.parser.grammar;

import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;

/**
 * Created by vasistas on 11/12/16.
 */
public interface TableColumnEntry<K extends Enum> extends GrammarTerm<K> {
    default GrammarTerm<K> asGrammarTerm() {
        return this;
    }
    OnInput<K> asOnInput();

    @Override
    default TableColumnEntry<K> asTableColumnEntry() {
        return this;
    }
}
