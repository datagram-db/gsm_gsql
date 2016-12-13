package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * Defines both rules and associated-rules
 */
public class AbstractRule<Type, RuleHeadType extends Type> implements IRule<Type, RuleHeadType> {

    public final RuleHeadType A;
    public final Type[] alpha;
    public AbstractRule(RuleHeadType nonTerminal, Type...chunks) {
        this.A = nonTerminal;
        this.alpha = chunks;
    }

    @Override
    public RuleHeadType header() {
        return A;
    }

    @Override
    public Type[] tail() {
        return alpha;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(A.toString()).append(" -> ");
        Arrays.stream(alpha).forEach(Type::toString);
        return sb.toString();
    }


    public static class Builder<Type, RuleHeadType extends Type> {

        public Builder(RuleHeadType head, Class<Type> clazz) {
            this.head = head;
            this.elems = new ArrayList<>();
            this.clazz = clazz;
        }

        public AbstractRule.Builder<Type,RuleHeadType> add(Type nonterm) {
            this.elems.add((nonterm));
            return this;
        }

        public AbstractRule gen() {
            Type[] e = (Type[]) Array.newInstance(clazz, elems.size());;
            return new AbstractRule(head,elems.toArray(e));
        }

        public final Class<Type> clazz;
        public final RuleHeadType head;
        public final ArrayList<Type> elems;

    }


}
