package it.giacomobergami.datatypelang.representation.compiler;

/**
 * Created by vasistas on 06/12/16.
 */
public class JSONElem {

    private String name;
    private boolean mutable;
    private int size;

    public JSONElem() {

    }

    public JSONElem(String name, boolean mutable, int size) {
        this.name = name;
        this.mutable = mutable;
        this.size = size;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isMutable() {
        return mutable;
    }

    public void setMutable(boolean mutable) {
        this.mutable = mutable;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }
}
