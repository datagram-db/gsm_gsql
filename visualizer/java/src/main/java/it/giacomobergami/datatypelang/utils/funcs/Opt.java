package it.giacomobergami.datatypelang.utils.funcs;

import java.util.Optional;
import java.util.function.Function;
import java.util.function.Supplier;

/**
 * Created by vasistas on 11/12/16.
 */
public class Opt<T> {

    private final boolean isPresent;
    private final T val;
    private String errorMessage;
    private Opt() {
        isPresent = false;
        val = null;
        errorMessage = null;
    }

    protected Opt(T val) {
        isPresent = true;
        this.val = val;
        errorMessage = null;
    }

    public Opt(Optional<T> val) {
        isPresent = val.isPresent();
        this.val = isPresent ? val.get() : null;
        errorMessage = null;
    }

    public static <T> Opt<T> err() {
        return new Opt<>();
    }

    public static <T> Opt<T> err(String errorMessage) {
        Opt<T> toret= new Opt<>();
        toret.errorMessage = errorMessage;
        return toret;
    }

    public String error() {
        return errorMessage;
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

    public <J> Opt<J> castError() {
        Opt<J> err = Opt.err();
        if (isError()) err.errorMessage = this.errorMessage;
        return err;
    }
}
