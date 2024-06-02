package it.giacomobergami.datatypelang.utils;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Spliterator;
import java.util.Spliterators;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

/**
 * Created by vasistas on 11/12/16.
 */
public class Streams {
    public static <T> Stream<T> toStream(Iterable<T> it) {
        return StreamSupport.stream(Spliterators.spliteratorUnknownSize(it.iterator(), Spliterator.ORDERED), false);
    }

    public static <T> Stream<T> toStream(Iterator<T> it) {
        return StreamSupport.stream(Spliterators.spliteratorUnknownSize(it, Spliterator.ORDERED), false);
    }

    public static <T> Stream<T> toStream(T[] array) {
        return Arrays.stream(array);
    }
}
