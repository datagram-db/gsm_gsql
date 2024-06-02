package it.giacomobergami.datatypelang.utils.funcs;

import java.util.Spliterator;
import java.util.Spliterators;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

/**
 * Created by vasistas on 11/12/16.
 */
public class ToStream {

    public static <T> Stream<T> from(Iterable<T> it) {
        return StreamSupport.stream(Spliterators.spliteratorUnknownSize(it.iterator(), Spliterator.NONNULL), false);
    }
}
