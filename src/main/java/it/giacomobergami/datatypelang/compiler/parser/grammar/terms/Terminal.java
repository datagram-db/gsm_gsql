package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;

/**
 * A terminal represents a regex exception through its regex
 */
public class Terminal<K extends Enum> implements TableColumnEntry<K> {


    @Override
    public boolean isTerminal() {
        return true;
    }
    @Override
    public boolean isNull() {
        return false;
    }

    @Override
    public String getValue() {
        return terminalCase.toString();
    }

    @Override
    public OnInput<K> toInput() {
        return new Token(terminalCase,null);
    }

    public String caso() {
        return terminalCase;
    }

    String terminalCase;

    @Override
    public String toString() {
        return terminalCase.toString();
    }

    public Terminal(String empty) {
        terminalCase = empty;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Terminal)) return false;

        Terminal<?> terminal = (Terminal<?>) o;

        return terminalCase != null ? terminalCase.equals(terminal.terminalCase) : terminal.terminalCase == null;
    }

    @Override
    public int hashCode() {
        int result = terminalCase != null ? terminalCase.hashCode() : 0;
        return result;
    }

    @Override
    public OnInput<K> asOnInput() {
        return new Token(terminalCase,null);
    }
}

