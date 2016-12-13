package it.giacomobergami.datatypelang.compiler.lexer;

import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;

import java.util.Iterator;
import java.util.stream.Stream;

/**
 * Created by vasistas on 11/12/16.
 */
public class TerminalIterator<T extends Enum> implements Iterator<OnInput<T>> {

    Iterator<OnInput<T>> it;

    public TerminalIterator(Stream<OnInput<T>> onInputStream) {
        it = onInputStream.iterator();
    }

    @Override
    public boolean hasNext() {
        return it.hasNext();
    }

    @Override
    public OnInput<T> next() {
        return it.hasNext() ? it.next() : new Varepsilon<T>();
    }
}
