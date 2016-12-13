package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;

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
        return isVarepsiolon;
    }

    @Override
    public String getValue() {
        return terminalCase.toString();
    }

    public K caso() {
        return terminalCase;
    }

    K terminalCase;
    private final boolean isVarepsiolon;

    public Terminal(K empty) {
        terminalCase = empty;
        this.isVarepsiolon = false;
    }

    public Terminal() {
        terminalCase = null;
        this.isVarepsiolon = true;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Terminal)) return false;

        Terminal<?> terminal = (Terminal<?>) o;

        if (isVarepsiolon != terminal.isVarepsiolon) return false;
        return terminalCase != null ? terminalCase.equals(terminal.terminalCase) : terminal.terminalCase == null;
    }

    @Override
    public int hashCode() {
        int result = terminalCase != null ? terminalCase.hashCode() : 0;
        result = 31 * result + (isVarepsiolon ? 1 : 0);
        return result;
    }

    @Override
    public GrammarTerm<K> asGrammarTerm() {
        return this;
    }
}

