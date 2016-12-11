package it.giacomobergami.datatypelang.utils.funcs;

import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public class OnExcpt<X,K,E extends Throwable> {

    private final X env;
    public OnExcpt(X e) {
        this.env = e;
    }

    public K as(ThrowableFunction<X,K,E> sup, Function<X,K> def) {
        K toret = null;
        try {
            return sup.apply(env);
        } catch (Throwable throwable) {
            return def.apply(env);
        }
    }

}
