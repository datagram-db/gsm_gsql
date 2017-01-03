package it.giacomobergami.examples.datatypelang.types;

/**
 * Provides the in memory representation of the datatype
 */
public class NativeType extends Type {
    public final String name;
    public final boolean isFixed;
    public final int memSize;
    public final String nativeType;

    public NativeType(String name, boolean isFixed, int memSize, String nativeType) {
        this.name = name;
        this.isFixed = isFixed;
        this.memSize = memSize;
        this.nativeType = nativeType;
    }

    public String getTypeName() {
        return name;
    }

    public boolean isMutable() {
        return !isFixed;
    }

    @Override
    public Kinds ofType() {
        return Kinds.Native;
    }

    public String getNativeTypeName() {
        return nativeType;
    }
}
