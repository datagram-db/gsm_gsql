package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import com.github.mrebhan.crogamp.cli.TableList;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.Multimap;
import com.sun.org.apache.xalan.internal.xsltc.compiler.util.MultiHashtable;
import it.giacomobergami.datatypelang.compiler.parser.TableCase;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.Item;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.GlobalCounter;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.TypesafeTable;
import it.giacomobergami.datatypelang.utils.data.Pair;

import java.util.*;

/**
 * Created by vasistas on 12/12/16.
 */
public class State<K extends Enum> {

    boolean isReduce;
    Set<ItemWithLookahead<K>> elements;
    int stateNo;
    public Multimap<GrammarTerm<K>,ItemWithLookahead<K>> map;

    public void initTypesafeTable(Grammar<K> g, TypesafeTable<K> tst) {
        if (tst.insertAndCheck(this)==-1) {
            System.err.println(this);
            if (this.isReduce) {
                elements.stream().filter(x->x.elementAtCurrentPosition().isError()).forEach(last -> {
                    for (OnInput<K> y : last.lookaheadSymbols)
                        if (last.getHead().equals(g.getStarter()))
                            tst.set(stateNo,y.asTableColumnValue());
                        else
                            tst.set(stateNo, y.asTableColumnValue(),  new Rule(last.getHead(), last.getCore()));
                });
            }
            map.asMap().entrySet().stream()
                        .map(x -> new Pair<>(x.getKey(), g.stateFromLookaheads(GlobalCounter.i.assign(), ItemWithLookahead.moveForward(x.getValue()))    ))
                        .forEach(x -> {
                            State<K> currElement = x.getValue();
                            currElement.initTypesafeTable(g, tst);
                            tst.set(stateNo, x.getKey().asTableColumnEntry(), tst.get(currElement));
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
        });
        isReduce = elements.stream().anyMatch(x->x.elementAtCurrentPosition().isError());
        this.elements = elements;
        stateNo = no;
    }

    @Override
    public String toString() {
        String[] header = new String[]{"Item","lookaheads"};
        TableList tl = new TableList(header.length,header).withUnicode(true);
        for (ItemWithLookahead<K> x : elements) {
            tl.addRow(x.orig.toString(), Arrays.toString(x.lookaheadSymbols));
        }
        return "State N°"+stateNo+".\n"+tl.toString();
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
