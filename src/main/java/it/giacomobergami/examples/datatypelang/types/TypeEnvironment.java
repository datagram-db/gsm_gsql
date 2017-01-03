package it.giacomobergami.examples.datatypelang.types;

import it.giacomobergami.examples.datatypelang.types.array.ArrayType;
import it.giacomobergami.examples.datatypelang.types.array.SortedIndexedArrayType;
import it.giacomobergami.datatypelang.language.interpreter.JSONElem;
import it.giacomobergami.examples.datatypelang.types.record.Field;
import it.giacomobergami.examples.datatypelang.types.record.RecordType;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by vasistas on 04/12/16.
 */
public class TypeEnvironment {
    public final HashMap<String,Type> env;

    public TypeEnvironment() {
        this.env = new HashMap<>();
    }

    public  enum BasicNativeTypes {
        INT(false,"int"),
        UINT(false,"uint"),
        LONG(false,"long"),
        ULONG(false,"ulong"),
        SHORT(false,"short"),
        USHORT(false,"ushort"),
        STRING(true,"string"),
        ARRAY(true,"array");

        public final boolean isMutable;
        public final String name;
        BasicNativeTypes(boolean b,String name) {
            isMutable = b;
            this.name = name;
        }
    }

    public static class RecordCreator {

        public RecordCreator(TypeEnvironment father, String name) {
            this.name = name;
            this.father = father;
            this.fields = new ArrayList<>();
        }

        public RecordCreator addField(String name, String type) {
            fields.add(new Field(name,father.env.get(type)));
            return this;
        }

        public RecordCreator addFieldOfInternalArray(String name, Type ofType) {
            fields.add(new Field(name,new ArrayType<>(ofType,"array<"+ofType.getTypeName()+">",false)));
            return this;
        }

        public RecordCreator addFieldOfExternalArray(String name, Type ofType) {
            fields.add(new Field(name,new ArrayType<>(ofType,"array<"+ofType.getTypeName()+">",true)));
            return this;
        }

        public RecordCreator addFieldOfSortedIndexedArray(String name, RecordType ofType, String sortedBy, String externallyIndexedBy) {
            fields.add(new Field(name,new SortedIndexedArrayType<>(ofType,name,sortedBy,externallyIndexedBy)));
            return this;
        }

        public TypeEnvironment close() {
            father.env.put(this.name,new RecordType(this.name,fields));
            return father;
        }

        public final String name;
        public final TypeEnvironment father;
        public final ArrayList<Field> fields;


    }

    public TypeEnvironment declareEnvType(String name,JSONElem elem) {
        this.env.put(name,new NativeType(name,!elem.isMutable(),elem.getSize(),elem.getName()));
        return this;
    }

    public TypeEnvironment declareEnvType(String name, boolean isFixed, int memSize, String nativeType) {
        this.env.put(name,new NativeType(name, isFixed, memSize,nativeType));
        return this;
    }

    public RecordCreator declareRecord(String name) {
        return new RecordCreator(this,name);
    }

    public Type get(BasicNativeTypes t) {
        return env.get(t.name);
    }
    public Type get(String name) { return env.get(name); }

}
