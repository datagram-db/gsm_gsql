package it.giacomobergami.datatypelang.representation;

/**
 * Created by vasistas on 04/12/16.
 */
public abstract class Type {
    public abstract String getTypeName();
    public abstract boolean isMutable();
    public abstract Kinds ofType();

    @Override
    public String toString() {
        return getTypeName();
    }
}
