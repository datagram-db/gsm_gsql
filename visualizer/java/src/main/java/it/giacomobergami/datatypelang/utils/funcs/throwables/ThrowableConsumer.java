package it.giacomobergami.datatypelang.utils.funcs.throwables;

import it.giacomobergami.datatypelang.utils.funcs.OnExcpt;
import it.giacomobergami.datatypelang.utils.funcs.Truth;

import java.util.Objects;
import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public interface ThrowableConsumer<T,E extends Throwable> {

    /**
     * Performs this operation on the given argument.
     *
     * @param t the input argument
     */
    void accept(T t) throws E;
}