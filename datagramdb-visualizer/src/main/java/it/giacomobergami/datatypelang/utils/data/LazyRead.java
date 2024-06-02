package it.giacomobergami.datatypelang.utils.data;

import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.function.Supplier;

/**
 * Created by vasistas on 17/12/16.
 */
public class LazyRead {

    public LazyRead(TerminalIterator tit) {
        this.tit = tit;
        value = Opt.err();
    }

    TerminalIterator tit;
    Opt<OnInput> value;


    public OnInput digest() {
        if (value.isError()) {
            return tit.next();
        } else {
            OnInput val = value.value();
            value = Opt.err();
            return val;
        }
    }

    public OnInput peek() {
        return value.ifte(x -> x, () -> {
            OnInput toret = tit.next();
            value = Opt.of(toret);
            return toret;
        });
    }

    public void flush() {
        if (value.isError()) {
            tit.next();
        } else value = Opt.err();
    }


}
