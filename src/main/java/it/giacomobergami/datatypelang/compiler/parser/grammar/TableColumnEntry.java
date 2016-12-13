package it.giacomobergami.datatypelang.compiler.parser.grammar;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;

/**
 * Created by vasistas on 11/12/16.
 */
public interface TableColumnEntry<K extends Enum> extends GrammarTerm<K> {
    GrammarTerm<K> asGrammarTerm();
}
