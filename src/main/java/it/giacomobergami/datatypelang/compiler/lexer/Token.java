package it.giacomobergami.datatypelang.compiler.lexer;

/**
 * Created by vasistas on 11/12/16.
 */
public class Token<T extends Enum> {

    public final T type;
    public final String data;
    public final boolean notEmpty;
    public boolean isNotEmpty() {
        return notEmpty;
    }

    public Token(T type, String data) {
        this.type = type;
        this.data = data;
        notEmpty = true;
    }

    public Token() {
        type = null;
        data = null;
        notEmpty = false;
    }

    @Override
    public String toString() {
        return String.format("(%s %s)", type.name(), data);
    }
}
