package it.giacomobergami.datatypelang.compiler.parser.grammar;

import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;

/**
 * Created by vasistas on 11/12/16.
 */
public interface TableColumnEntry extends GrammarTerm {
    default GrammarTerm asGrammarTerm() {
        return this;
    }
    OnInput asOnInput();

    @Override
    default TableColumnEntry asTableColumnEntry() {
        return this;
    }
}
