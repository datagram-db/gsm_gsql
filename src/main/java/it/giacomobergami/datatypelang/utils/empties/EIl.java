package it.giacomobergami.datatypelang.utils.empties;

import it.giacomobergami.datatypelang.utils.empties.EIt;

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
