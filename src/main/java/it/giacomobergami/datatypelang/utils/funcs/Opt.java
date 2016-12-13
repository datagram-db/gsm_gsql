package it.giacomobergami.datatypelang.utils.funcs;

import java.util.function.Function;
import java.util.function.Supplier;

/**
 * Created by vasistas on 11/12/16.
 */
public class Opt<T> {

    private final boolean isPresent;
    private final T val;
    private Opt() {
        isPresent = false;
        val = null;
    }

    private Opt(T val) {
        isPresent = true;
        this.val = val;
    }

    public static <T> Opt<T> err() {
        return new Opt<>();
    }

    public static <T> Opt<T> of(T v) {
        return new Opt<>(v);
    }

    public <K> K ifte(Function<T,K> ifTrue, Supplier<K> ifFalse) {
        return isPresent ? ifTrue.apply(val) : ifFalse.get();
    }

    public boolean isError() {
        return !isPresent;
    }

    public T value() {
        return val;
    }
}
