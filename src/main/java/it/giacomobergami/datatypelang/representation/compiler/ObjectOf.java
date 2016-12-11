package it.giacomobergami.datatypelang.representation.compiler;

import it.giacomobergami.datatypelang.representation.Type;

/**
 * Created by vasistas on 06/12/16.
 */
interface ObjectOf<T extends Type> {
    void sizeof(T obj);
}
