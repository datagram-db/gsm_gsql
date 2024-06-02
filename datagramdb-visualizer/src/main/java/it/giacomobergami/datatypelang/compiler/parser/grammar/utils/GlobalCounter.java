package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

public class GlobalCounter {
    public static GlobalCounter i = new GlobalCounter();

    private volatile int next = 1;

    private GlobalCounter() {
        // prevent external instantiation of a singleton.
    }

    public synchronized int assign() {
        return next++;
    }
}