package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ANTerm)) return false;

        ANTerm<?> anTerm = (ANTerm<?>) o;

        if (nonterm != null ? !nonterm.equals(anTerm.nonterm) : anTerm.nonterm != null) return false;
        return rs != null ? rs.equals(anTerm.rs) : anTerm.rs == null;
    }

    @Override
    public int hashCode() {
        int result = nonterm != null ? nonterm.hashCode() : 0;
        result = 31 * result + (rs != null ? rs.hashCode() : 0);
        return result;
    }

    @Override
    public GrammarTerm<T> getGrammarMatchedElement() {
        return nonterm;
    }

    @Override
    public boolean hasSubtree() {
        return true;
    }

    @Override
    public String getUnderlyingString() {
        StringBuilder sb = new StringBuilder();
        rs.associations.forEach(sb::append);
        return sb.toString();
    }

    @Override
    public Opt<ReducedStack<T>> getSubTree() {
        return Opt.of(rs);
    }
}
