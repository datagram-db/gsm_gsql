package it.giacomobergami.datatypelang.compiler.parser.grammar;

import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.Association;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.OnStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.AbstractRule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.IRule;

import java.util.Deque;

/**
 * Implements both the reduce operation and allows to initialize the contents with given values
 */
public class Rule<K extends Enum> implements IRule<GrammarTerm<K>,NonTerminal<K>> {

    AbstractRule<GrammarTerm<K>,NonTerminal<K>> actual;

    public Rule(NonTerminal<K> name, GrammarTerm<K>... terms) {
        actual = new AbstractRule<>(name, terms);
    }

    @Override
    public NonTerminal<K> header() {
        return actual.A;
    }

    @Override
    public GrammarTerm<K>[] tail() {
        return actual.alpha;
    }

    public void reduce(Deque<OnStack<K>> estack) {
        //Inserting the elements in the stack-reverse order
        Association<K> toR[] = new Association[actual.alpha.length];
        for (int i=actual.alpha.length-1; i>=0; i--) {
            toR[i] = Association.assoc(actual.alpha[i],estack.pop());
        }
        estack.push(new ReducedStack<>(this,toR));
    }

    @Override
    public String toString() {
        return actual.toString();
    }

    public ItemWithLookahead<K> asLookaheadItem(Grammar<K> g) {
        return ItemWithLookahead.generate(g,this).value();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Rule)) return false;

        Rule<?> rule = (Rule<?>) o;

        return actual != null ? actual.equals(rule.actual) : rule.actual == null;
    }

    @Override
    public int hashCode() {
        return actual != null ? actual.hashCode() : 0;
    }
}
