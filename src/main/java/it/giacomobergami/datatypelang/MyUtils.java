package it.giacomobergami.datatypelang;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.StringWriter;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Created by vasistas on 06/12/16.
 */
public class MyUtils {

    public static String fileToString(String name) {
        try {
            return new String(Files.readAllBytes(Paths.get(name)));
        } catch (IOException e) {
            return "";
        }
    }

}
