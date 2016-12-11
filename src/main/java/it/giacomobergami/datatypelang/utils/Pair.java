package it.giacomobergami.datatypelang.utils;

/**
 * Created by vasistas on 11/12/16.
 */
public class Pair<K,V> {
    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }

    private final K key;
    private final V value;
}
