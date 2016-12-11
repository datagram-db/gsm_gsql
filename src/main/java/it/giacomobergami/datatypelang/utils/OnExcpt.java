package it.giacomobergami.datatypelang.utils;

import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public class OnExcpt<X,K> {

    private final X env;
    public OnExcpt(X e) {
        this.env = e;
    }

    public <E extends Throwable> K as(ThrowableFunction<X,K,E> sup, Function<X,K> def) {
        try {
            return sup.apply(env);
        } catch (Throwable throwable) {
            return def.apply(env);
        }
    }

    public static void main(String args[]) {
        System.out.println(new OnExcpt<String,String>("ciao").as(s -> {
            throw new RuntimeException();
        }, x -> "cicco"));
    }

}
