package it.giacomobergami.datatypelang.representation.record;

import it.giacomobergami.datatypelang.representation.Kinds;
import it.giacomobergami.datatypelang.representation.Type;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * Defines a record as an element
 */
public class RecordType extends Type {
    public final String name;
    public final ArrayList<Field> fields;

    public RecordType(String name) {
        this.name = name;
        this.fields = new ArrayList<>();
    }

    public RecordType(String name, Field... t) {
        this(name);
        Collections.addAll(fields, t);
        Collections.sort(fields, (o1, o2) -> {
            boolean mut1 = o1.ofType.isMutable();
            boolean check = mut1 == o2.ofType.isMutable();
            return (check) ? 0 : (mut1 ? 1 : -1);
        });
    }

    public RecordType(String name, ArrayList<Field> fields) {
        this.name = name;
        this.fields = fields;
        Collections.sort(fields, (o1, o2) -> {
            boolean mut1 = o1.ofType.isMutable();
            boolean check = mut1 == o2.ofType.isMutable();
            return (check) ? 0 : (mut1 ? 1 : -1);
        });
    }

    public String getTypeName() {
        return name;
    }

    public boolean isMutable() {
        return fields.stream().anyMatch(x -> x.ofType.isMutable());
    }

    @Override
    public Kinds ofType() {
        return Kinds.Record;
    }

}
