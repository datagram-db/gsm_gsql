package it.giacomobergami.datatypelang.utils.funcs;

import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public interface ThrowableFunction<K,V,E extends Throwable> {
    V apply(K k) throws E;
}
