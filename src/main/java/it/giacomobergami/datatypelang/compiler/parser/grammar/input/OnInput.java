package it.giacomobergami.datatypelang.compiler.parser.grammar.input;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public interface OnInput<T extends Enum> {
    boolean isEmpty();
    TableColumnEntry<T> asTableColumnValue();
    default boolean nonEmpty() {
        return !isEmpty();
    }
}
