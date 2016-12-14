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
        //System.err.println("Creating node: "+this+"\nˆˆˆˆˆˆˆ");
        if (tst.insertAndCheck(this)==-1) {
            if (this.isReduce) {
                for (ItemWithLookahead<K> last : elements) {

                    for (OnInput<K> y : last.lookaheadSymbols)
                        if (last.getHead().equals(g.getStarter()))
                            tst.set(stateNo,y.asTableColumnValue());
                        else
                            tst.set(stateNo, y.asTableColumnValue(),  new Rule(last.getHead(), last.getCore()));
                    break;
                }
            } else
                map.asMap().entrySet().stream().map(x -> new Pair<>(x.getKey(), g.stateFromLookaheads(GlobalCounter.i.assign(), ItemWithLookahead.moveForward(x.getValue()))    )).forEach(x -> {
                    x.getValue().initTypesafeTable(g, tst);
                    tst.set(stateNo, x.getKey().asTableColumnEntry(), tst.get(x.getValue()));
                });
        }
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
            if (elements.size()==1 && x.elementAtCurrentPosition().isError())
                isReduce=true;
            else
                isReduce=false;
        });
        this.elements = elements;
        stateNo = no;
    }

    @Override
    public String toString() {
        return "State N°"+stateNo+".\n"+elements.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof State)) return false;

        State<?> state = (State<?>) o;

        if (isReduce != state.isReduce) return false;
        if (elements != null ? !elements.equals(state.elements) : state.elements != null) return false;
        return map != null ? map.equals(state.map) : state.map == null;
    }

    @Override
    public int hashCode() {
        int result = (isReduce ? 1 : 0);
        result = 31 * result + (elements != null ? elements.hashCode() : 0);
        result = 31 * result + (map != null ? map.hashCode() : 0);
        return result;
    }

    public int getNumber() {
        return stateNo;
    }
}
