package it.giacomobergami.datatypelang.utils;

import java.util.Iterator;

/**
 * Created by vasistas on 11/12/16.
 */
public class EIl<K> implements Iterable<K> {
    @Override
    public Iterator<K> iterator() {
        return new EIt<>();
    }
}
