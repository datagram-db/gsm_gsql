package it.giacomobergami.datatypelang.compiler.parser.cp;

import it.giacomobergami.datatypelang.compiler.lexer.Token;

/**
 * Created by vasistas on 11/12/16.
 */
public class Terminal<K extends Enum> implements CP {

    @Override
    public boolean isTerminal() {
        return true;
    }

    @Override
    public boolean isNull() {
        return isVarepsiolon;
    }

    public Token<K> getTerminal() {
        return terminal;
    }

    private final Token<K> terminal;
    private final boolean isVarepsiolon;

    public Terminal(Token<K> value) {
        this.terminal = value;
        this.isVarepsiolon = false;
    }

    public Terminal() {
        this.terminal = null;
        this.isVarepsiolon = true;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Terminal)) return false;

        Terminal<?> terminal1 = (Terminal<?>) o;

        if (isVarepsiolon != terminal1.isVarepsiolon) return false;
        return terminal != null ? terminal.equals(terminal1.terminal) : terminal1.terminal == null;
    }

    @Override
    public int hashCode() {
        int result = terminal != null ? terminal.hashCode() : 0;
        result = 31 * result + (isVarepsiolon ? 1 : 0);
        return result;
    }
}

