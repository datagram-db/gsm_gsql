package it.giacomobergami.datatypelang.compiler.lexer;

import it.giacomobergami.datatypelang.compiler.lexer.example.TokenType;
import it.giacomobergami.datatypelang.compiler.parser.cp.Terminal;

import java.util.Iterator;

/**
 * Created by vasistas on 11/12/16.
 */
public class TerminalIterator<T extends Enum> implements Iterator<Terminal<T>> {

    Iterator<Terminal<T>> it;

    public TerminalIterator(Class<T> clazz, String input) {
        it = new Lexer<>(clazz).terminalIterator(input);
    }

    @Override
    public boolean hasNext() {
        return it.hasNext();
    }

    @Override
    public Terminal<T> next() {
        return it.hasNext() ? it.next() : new Terminal<>();
    }
}
