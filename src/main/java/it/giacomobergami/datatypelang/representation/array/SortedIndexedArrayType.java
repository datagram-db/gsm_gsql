package it.giacomobergami.datatypelang.representation.array;

import it.giacomobergami.datatypelang.representation.Type;
import it.giacomobergami.datatypelang.representation.record.Field;
import it.giacomobergami.datatypelang.representation.record.RecordType;

/**
 * Created by vasistas on 04/12/16.
 */
public class SortedIndexedArrayType<R extends RecordType> extends ArrayType<R> {

    public final Field sortedBy, externallyIndexedBy;

    public SortedIndexedArrayType(R ofType, String name, String sortedBy, String externallyIndexedBy) {
        super(ofType, name, true);
        this.sortedBy = ofType.fields.stream().filter(x -> x.ofType.getTypeName().equals(sortedBy)).findFirst().get();
        this.externallyIndexedBy = ofType.fields.stream().filter(x -> x.ofType.getTypeName().equals(externallyIndexedBy)).findFirst().get();
    }

}
