package it.giacomobergami.datatypelang.utils.funcs;


        import it.giacomobergami.datatypelang.utils.funcs.throwables.ThrowableFunction;

        import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public class OnExcpt<X,K> {

    private final X env;
    public OnExcpt(X e) {
        this.env = e;
    }

    public  K as(ThrowableFunction<X,K,?> sup, Function<X,K> def) {
        try {
            return sup.apply(env);
        } catch (Throwable throwable) {
            return def.apply(env);
        }
    }

}