package it.giacomobergami.datatypelang.utils.funcs;

import java.util.Optional;

/**
 * Created by vasistas on 18/12/16.
 */
public class OptErr<T,K> extends Opt<T> {

    private K elem;
    public OptErr(Optional<T> val) {
        super(val);
    }

    public OptErr(K val) {
        super(Optional.empty());
        this.elem  = val;
    }

    public K errorElement(){
        return this.elem;
    }

    public static <T,K> OptErr<T,K> of2(T elem) {
        return new OptErr<T, K>(Optional.of(elem));
    }

}
