package it.giacomobergami.examples.DTL.types;

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
