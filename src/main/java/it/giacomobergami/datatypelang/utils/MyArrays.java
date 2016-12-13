package it.giacomobergami.datatypelang.utils;

import java.util.Collection;

/**
 * Created by vasistas on 11/12/16.
 */
public class MyArrays {

    public static <T> boolean arrayIsInAll(T[] elems, Collection<T> c) {
        for (T x : elems) if (!c.contains(x)) return false;
        return true;
    }

}
