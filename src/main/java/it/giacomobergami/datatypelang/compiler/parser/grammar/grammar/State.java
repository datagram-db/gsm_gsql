package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.Multimap;
import com.sun.org.apache.xalan.internal.xsltc.compiler.util.MultiHashtable;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.Item;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.GlobalCounter;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.TypesafeTable;
import it.giacomobergami.datatypelang.utils.data.Pair;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by vasistas on 12/12/16.
 */
public class State<K extends Enum> {

    boolean isReduce;
    Set<ItemWithLookahead<K>> elements;
    int stateNo;
    public Multimap<GrammarTerm<K>,ItemWithLookahead<K>> map;

    public void initTypesafeTable(Grammar<K> g, TypesafeTable<K> tst) {
        if (this.isReduce) {
            for (ItemWithLookahead<K> last : elements) {
                for (OnInput<K> y : last.lookaheadSymbols)
                    tst.set(stateNo,y.asTableColumnValue(),new Rule(last.getHead(),last.getCore()));
                break;
            }
        } else
        map.asMap().entrySet().stream().map(x->new Pair<>(x.getKey(),g.stateFromLookaheads(GlobalCounter.i.assign(),x.getValue()))).forEach(x->{
            tst.set(stateNo,x.getKey().asTableColumnEntry(),x.getValue().stateNo);
            x.getValue().initTypesafeTable(g,tst);
        });
    }

    State(int no,ItemWithLookahead<K> next) {
        map = HashMultimap.create();
        elements = new HashSet<>();
        elements.add(next);
        if (!next.elementAtCurrentPosition().isError())
            map.put(next.elementAtCurrentPosition().value(),next);
        stateNo = no;
        isReduce = (next.elementAtCurrentPosition().isError());
    }

    State(int no,Set<ItemWithLookahead<K>> elements) {
        map = HashMultimap.create();
        elements.forEach(x -> {
            if (!x.elementAtCurrentPosition().isError())
                map.put(x.elementAtCurrentPosition().value(),x);
            if (elements.size()==1 && x.elementAtCurrentPosition().isError()) isReduce=true;
        });
        this.elements = elements;
        stateNo = no;
    }

    @Override
    public String toString() {
        return "State N°"+stateNo+".\n"+elements.toString();
    }

}
