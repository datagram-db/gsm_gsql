package it.giacomobergami.datatypelang.compiler.parser.grammar.stack;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.Association;

import java.util.Arrays;
import java.util.List;

/**
 * Created by vasistas on 11/12/16.
 */
public class ReducedStack<K extends Enum> implements OnStack<K> {

    public final List<Association<K>> associations;
    public final Rule r;
    public ReducedStack(Rule nt, Association<K>... elems) {
        associations = Arrays.asList(elems);
        r = nt;
    }

}
