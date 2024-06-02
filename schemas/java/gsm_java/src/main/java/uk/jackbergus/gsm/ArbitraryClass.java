package uk.jackbergus.gsm;

import java.util.ArrayList;
import java.util.List;

public class ArbitraryClass {

    public String stringField;
    public double doubleField;
    public List<String> additional_textual_content = new ArrayList<>();
    public List<ExternalReference> externalTables = new ArrayList<>();

    public static class ExternalReference {
        public  final String name;
        public final String surname;

        public ArbitraryClass loopback_reference = null;

        public ExternalReference(String name, String surname) {
            this.name = name;
            this.surname = surname;
        }
    }

}
