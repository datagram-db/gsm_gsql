package it.giacomobergami.examples.DTL.types.record;

import it.giacomobergami.examples.DTL.types.Type;

/**
 * Defines a field within a record
 */
public class Field {
    public Field(String declaration, Type ofType) {
        this.declaration = declaration;
        this.ofType = ofType;
        this.mutable = ofType.isMutable();
        this.fixed = !this.mutable;
    }

    public final String declaration;
    public final Type ofType;
    public final boolean mutable;
    public final boolean fixed;
}
