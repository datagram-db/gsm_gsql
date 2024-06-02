package it.giacomobergami.datatypelang.utils.empties;

import java.util.Iterator;

/**
 * Created by vasistas on 11/12/16.
 */
public class EIt<K> implements Iterator<K> {
    @Override
    public boolean hasNext() {
        return false;
    }
    @Override
    public K next() {
        return null;
    }
}
