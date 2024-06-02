package it.giacomobergami.datatypelang.compiler.lexer;

import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;

import java.util.Iterator;
import java.util.stream.Stream;

/**
 * Created by vasistas on 11/12/16.
 */
public class TerminalIterator implements Iterator<OnInput> {

    Iterator<OnInput> it;

    public TerminalIterator(Stream<OnInput> onInputStream) {
        it = onInputStream.iterator();
    }

    @Override
    public boolean hasNext() {
        return it.hasNext();
    }

    @Override
    public OnInput next() {
        return it.hasNext() ? it.next() : new Varepsilon();
    }
}
