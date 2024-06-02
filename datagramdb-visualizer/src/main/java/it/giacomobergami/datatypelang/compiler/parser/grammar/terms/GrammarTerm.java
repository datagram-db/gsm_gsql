package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;


import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;

/**
 * Created by vasistas on 11/12/16.
 */
public interface GrammarTerm {
    boolean isTerminal();
    boolean isNull();
    default boolean isNotNull() {
        return !isNull();
    }
    String getValue();
    default boolean isInput() {
        return isNull() || isTerminal();
    }
    TableColumnEntry asTableColumnEntry();

    OnInput toInput();
}
