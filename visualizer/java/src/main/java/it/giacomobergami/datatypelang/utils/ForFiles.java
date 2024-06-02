package it.giacomobergami.datatypelang.utils;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Iterator;
import java.util.Spliterator;
import java.util.Spliterators;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

/**
 * Created by vasistas on 06/12/16.
 */
public class ForFiles {

    public static String toString(String name) {
        try {
            return new String(java.nio.file.Files.readAllBytes(Paths.get(name)));
        } catch (IOException e) {
            return "";
        }
    }

    public static String toString(File f) {
        try {
            return new String(Files.readAllBytes(f.toPath()));
        } catch (IOException e) {
            return "";
        }
    }


}
