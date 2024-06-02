package it.giacomobergami.examples.DTL.types.record;

import it.giacomobergami.examples.DTL.types.Kinds;
import it.giacomobergami.examples.DTL.types.Type;

import java.util.ArrayList;
import java.util.Collections;

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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof RecordType)) return false;

        RecordType that = (RecordType) o;

        if (name != null ? !name.equals(that.name) : that.name != null) return false;
        return fields != null ? fields.equals(that.fields) : that.fields == null;
    }

    @Override
    public int hashCode() {
        int result = name != null ? name.hashCode() : 0;
        result = 31 * result + (fields != null ? fields.hashCode() : 0);
        return result;
    }
}
