package it.giacomobergami.examples.datatypelang.types.array;

import it.giacomobergami.examples.datatypelang.types.Kinds;
import it.giacomobergami.examples.datatypelang.types.Type;

/**
 * Created by vasistas on 04/12/16.
 */
public class ArrayType<T extends Type> extends Type {

    public final String name;
    public final T ofType;
    public final boolean isExternal;
    public final Kinds kind;

    public ArrayType(T ofType, String name) {
        this.ofType = ofType;
        this.name = name;
        this.isExternal = false;
        kind = Kinds.ArrayInternal;
    }

    public ArrayType(T ofType, String name, boolean isExternal) {
        this.ofType = ofType;
        this.name = name;
        this.isExternal = isExternal;
        kind = isExternal ? Kinds.ArrayExternal : Kinds.ArrayInternal;
    }

    @Override
    public String getTypeName() {
        return name;
    }
    @Override
    public boolean isMutable() {
        return ofType.isMutable();
    }

    @Override
    public Kinds ofType() {
        return kind;
    }


    public boolean isExternal() {
        return isExternal;
    }

}
