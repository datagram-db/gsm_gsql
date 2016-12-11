package it.giacomobergami.datatypelang.representation.record;

import it.giacomobergami.datatypelang.representation.Type;

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
