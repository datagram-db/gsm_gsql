package it.giacomobergami.datatypelang.utils;

import it.giacomobergami.datatypelang.utils.Pair;

import java.util.HashSet;
import java.util.Set;
import java.util.function.*;
import java.util.stream.Collector;

/**
 * Created by vasistas on 11/12/16.
 */
public abstract class Accum<X,K> implements Function<Pair<X,K>,K>, BiConsumer<K,X>, Supplier<K>, Collector<X,K,K> {

    private K v;
    public Accum(K val) {
        v = val;
    }

    @Override
    public K get() {
        return v; // I always provide the update value
    }

    @Override
    public Supplier<K> supplier() {
        return this;    //Indirectly calls the get() method. The most update v is returned
    }

    @Override
    public void accept(K k, X x) {
        v = apply(new Pair<>(x, v)); // Ignore the k value. Uses the X value
    }

    @Override
    public BiConsumer<K, X> accumulator() {
        return this; // Calls the accept function
    }

    @Override
    public BinaryOperator<K> combiner() {
        return (k, k2) -> k2;
    }

    @Override
    public Function<K, K> finisher() {
        return x -> v;  // Returns the last element, that is the most recent one
    }

    @Override
    public Set<Characteristics> characteristics() {
        return new HashSet<>();
    }
}
