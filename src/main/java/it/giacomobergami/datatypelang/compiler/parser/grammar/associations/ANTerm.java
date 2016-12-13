package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;

/**
 * Created by vasistas on 11/12/16.
 */
public class ANTerm<T extends Enum> extends Association<T> {

    NonTerminal<T> nonterm;
    ReducedStack<T> rs;
    public ANTerm(NonTerminal<T> nt, ReducedStack<T> term) {
        nonterm = nt;
        rs = term;
    }
}
