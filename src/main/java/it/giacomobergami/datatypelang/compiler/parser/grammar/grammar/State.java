package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.Item;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by vasistas on 12/12/16.
 */
public class State<K extends Enum> {

    boolean isReduce;
    Set<ItemWithLookahead<K>> elements;
    State(ItemWithLookahead<K> next) {
        elements = new HashSet<>();
        elements.add(next);
    }

    State(Set<ItemWithLookahead<K>> elements) {
        this.elements = elements;
    }

}
