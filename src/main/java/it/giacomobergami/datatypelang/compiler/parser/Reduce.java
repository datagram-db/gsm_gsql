package it.giacomobergami.datatypelang.compiler.parser;

import it.giacomobergami.datatypelang.compiler.parser.cp.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.cp.Terminal;

import java.util.ArrayList;

/**
 * Created by vasistas on 11/12/16.
 */
public class Reduce<K extends Enum, NT extends NonTerminal, T extends Terminal<K>> {

    public final NT head;
    public final Part<K,NT,T>[] elements;
    public Reduce(NT nonTerminal, Part<K,NT,T>...chunks) {
        this.head = nonTerminal;
        this.elements = chunks;
    }

    public static class Builder<K extends Enum, NT extends NonTerminal, T extends Terminal<K>> {

        public Builder(NT head) {
            this.head = head;
            this.elems = new ArrayList<>();
        }

        public Builder add(NT nonterm) {
            this.elems.add(new Part<>(nonterm));
            return this;
        }

        public Builder add(T term) {
            this.elems.add(new Part<>(term));
            return this;
        }

        public Reduce<K,NT,T> gen() {
            Part<K,NT,T>[] e = new Part[elems.size()];
            return new Reduce<K, NT, T>(head,elems.toArray(e));
        }

        public final NT head;
        public final ArrayList<Part<K,NT,T>> elems;

    }

}
