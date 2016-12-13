package it.giacomobergami.datatypelang.compiler.parser.grammar.stack;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public class Token<T extends Enum> implements OnStack<T>, OnInput<T> {

    public final T type;
    public String data;
    public final Terminal<T> term;

    public Token(T type, String data) {
        this.type = type;
        this.data = data;
        this.term = new Terminal<T>(type);
    }

    @Override
    public String toString() {
        return String.format("(%s %s)", type.name(), data);
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public TableColumnEntry<T> asTableColumnValue() {
        return term;
    }
}
