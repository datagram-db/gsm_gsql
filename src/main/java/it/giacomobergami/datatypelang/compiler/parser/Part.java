package it.giacomobergami.datatypelang.compiler.parser;

import it.giacomobergami.datatypelang.compiler.parser.cp.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.cp.Terminal;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public class Part<K extends Enum, NT extends NonTerminal, T extends Terminal<K>> {

    private final NT nonterminal;
    private final T terminal;

    public Part(T terminal) {
        this.terminal = terminal;
        this.nonterminal = null;
    }

    public Part(NT nonterminal) {
        this.nonterminal = nonterminal;
        this.terminal = null;
    }

    public boolean isNonTerminal() {
        return nonterminal!=null;
    }

    public Opt<String> getNT() {
        return isNonTerminal() ? Opt.of(nonterminal.getId()) : Opt.err();
    }

    public Opt<K> getT() {
        return isNonTerminal() ? Opt.err() : Opt.of(terminal.getTerminal().type);
    }


}
