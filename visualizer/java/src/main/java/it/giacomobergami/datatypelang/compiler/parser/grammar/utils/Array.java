package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

import org.apache.commons.lang3.ArrayUtils;

/**
 * Created by vasistas on 13/12/16.
 */
public class Array<T> {
    public final T[] array;
    public Array() {
        array = ArrayUtils.toArray();
    }
    public Array(T... elems) {
        array = elems;
    }
}
