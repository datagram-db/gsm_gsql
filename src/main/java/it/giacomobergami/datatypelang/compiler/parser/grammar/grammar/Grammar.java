package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.Iterables;
import com.google.common.collect.Multimap;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.Item;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;
import it.giacomobergami.datatypelang.utils.funcs.Opt;
import org.apache.commons.lang3.ArrayUtils;

import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Created by vasistas on 12/12/16.
 */
public class Grammar<K extends Enum> {

    private final NonTerminal<K> starter;
    private final Multimap<NonTerminal<K>,Rule<K>> map;
    public final Rule<K>[] rules;
    private Set<Terminal<K>> terminals;
    private Set<NonTerminal<K>> nullables;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Rule<K> x : rules) sb.append(x.toString()).append(",");
        return sb.toString();
    }

    private Multimap<ItemWithLookahead<K>,GrammarTerm<K>> mapFromLookahead(ItemWithLookahead<K> first) {
        Multimap<ItemWithLookahead<K>,GrammarTerm<K>> stateElementsMap = HashMultimap.create();
        stateElementsMap.putAll(first,first.getLookaheadSymbols());
        if (first != null) {
            // A -> αxβ
            Opt<GrammarTerm<K>> x = first.elementAtCurrentPosition();

            // The first element has been already visited, so I just return the actual state.
            // MEMO: In this case I should generate  a reduce operation
            // Otherwise, I have to check the elements stored within the element
            if (first.getItemPos() != first.getCore().length && !x.isError()) {
                GrammarTerm<K> t = x.value();

                // If, otherwise, it is a terminal,
                // I only have a shift operation. I do not have to visit the other elements
                //return stateElementsMap;
                if (!t.isTerminal()) {

                    NonTerminal<K> nt = (NonTerminal<K>)t;
                    Set<ItemWithLookahead<K>> state = new HashSet<>();
                    state.add(first);

                    GrammarTerm<K>[] l = first.getElementsNextToCore();

                    for (Rule<K> y : map.get(nt)) {
                        ItemWithLookahead<K> item = y.asLookaheadItem(this);
                        for (GrammarTerm<K> z : l) stateElementsMap.put(item,z);

                        //Check recursively if the current expanded item starts with a NT, and hence it has to be expanded
                        Opt<GrammarTerm<K>> nt2 = item.elementAtCurrentPosition();
                        if (nt2.ifte(z->!z.isTerminal(),()->false)) {
                            stateElementsMap.putAll(mapFromLookahead(item));
                        }
                    }

                }



            }

        }
        return stateElementsMap;
    }

    /**
     * Generates an LR(1) state from the state definition
     * @param No
     * @param first
     * @return
     */
    public State<K> stateFromLookahead(int No, ItemWithLookahead<K> first) {
        return new State<K>(No,mapFromLookahead(first).asMap().entrySet().stream().map(x->x.getKey().setLookaheadSymbols(x.getValue())).collect(Collectors.toSet()));
    }


    private Grammar(NonTerminal<K> starter,Rule<K>... rules) {
        this.starter = starter;
        map = HashMultimap.create();
        for (Rule x : rules) map.put(x.header(),x);
        this.rules = rules;
        terminals = null;
        nullables = null;
    }

    private Grammar(NonTerminal<K> starter,Collection<Rule<K>> rules) {
        this.starter = starter;
        map = HashMultimap.create();
        this.rules = Iterables.toArray(rules,Rule.class);
        rules.forEach(x -> map.put(x.header(), x));
        terminals = null;
        nullables = null;
    }

    public static <K extends Enum> Opt<Grammar<K>> generateGrammar(NonTerminal<K> starter, Rule<K>... rules) {
        boolean hasStarter = false;
        for (Rule x : rules) if (starter.equals(x.header())) {
            hasStarter = true;
            break;
        }
        return hasStarter ? Opt.of(new Grammar<K>(starter, rules)) : Opt.err();
    }

    public static <K extends Enum> Opt<Grammar<K>> generateGrammar(NonTerminal<K> starter, Collection<Rule<K>> rules) {
        boolean hasStarter = false;
        for (Rule x : rules) if (starter.equals(x.header())) {
            hasStarter = true;
            break;
        }
        return hasStarter ? Opt.of(new Grammar<K>(starter, rules)) : Opt.err();
    }

    /**
     * Collects all the headers from the rules
     * @return
     */
    public Set<NonTerminal<K>> getAllNonTerminals() {
        return map.keySet();
    }

    /**
     * Collects all the terminals from all the rules
     * @return
     */
    public Set<Terminal<K>> getAllTerminals() {
        if (terminals == null)
            terminals = map.values().stream()
                    .map(x-> Arrays.stream(x.tail()))
                    .flatMap(x->x)
                    .filter(GrammarTerm::isTerminal)
                    .map(x->((Terminal<K>)x)).collect(Collectors.toSet());
        return terminals;
    }

    public Set<NonTerminal<K>> nullables() {
        if (nullables==null) {
            nullables = new HashSet<>();
            Arrays.stream(rules)
                    .filter(x -> x.tail().length == 0)
                    .map(Rule::header)
                    .forEach(nullables::add);
            for (Rule<K> x : rules) {
                boolean toadd = true;
                boolean thereIsNonTerminal = false;
                for (GrammarTerm<K> y : x.tail()) {
                    if (y instanceof NonTerminal) {
                        thereIsNonTerminal = true;
                        if (!nullables.contains(y)) {
                            toadd = false;
                            break;
                        }
                    }
                }
                if (toadd && thereIsNonTerminal)
                    nullables.add(x.header());
            }
        }
        return nullables;
    }

    private Set<TableColumnEntry<K>> first(GrammarTerm<K> x) {
        Set<TableColumnEntry<K>> hs = new HashSet<>();
        if (x.isTerminal() && (!x.isNull())) {
            hs.add((TableColumnEntry<K>)x);
            return hs;
        } else {
            nullables();
            map.get((NonTerminal<K>) x).forEach(y -> {
                StringBuilder sb = new StringBuilder();
                //System.out.println("@@"+y);
                GrammarTerm<K>[] tl = y.tail();
                if (!tl[0].equals(x)) //Add the element, but do not get trapped in a loop. I'm already visiting x
                    hs.addAll(first(tl[0]));
                for (int i = 1; i < tl.length; i++) {
                    boolean allNullable = true;
                    for (int j = 0; j < i; j++) {
                        if (!nullables.contains(tl[j])) {
                            allNullable = false;
                            break;
                        }
                    }
                    if (allNullable) {
                        hs.addAll(first(tl[i]));
                    }

                }
            });
            if (nullables.contains(x)) {
                hs.add(new Varepsilon<>());
            }
            return hs;
        }
    }

    public Set<TableColumnEntry<K>> first(Rule<K> r) {
        return first(r.tail());
    }

    public Set<TableColumnEntry<K>> first(NonTerminal<K> nt) {
        return map.get(nt).stream().map(x->first(x.tail()).stream()).flatMap(x->x).collect(Collectors.toSet());
    }

    private Set<TableColumnEntry<K>> first(GrammarTerm<K>... x) {
        return first(0,x);
    }

    public Set<TableColumnEntry<K>> first(List<GrammarTerm<K>> x) {
        return first(0,x);
    }

    public Set<TableColumnEntry<K>> first(Item<K> lh) {
        return first((lh.pos),lh.elems);
    }

    private Set<TableColumnEntry<K>> first(int pos, List<GrammarTerm<K>> x) {
        Set<TableColumnEntry<K>> hs = new HashSet<>();
        if (x.size()==0||pos>=x.size()) {
            hs.add(new Varepsilon<>());
            return hs;
        } else {
            nullables();
            GrammarTerm<K> fst = x.get(pos);
            if (nullables.contains(fst)) {
                hs.addAll(first(x));
                hs.remove(new Varepsilon<K>());
                hs.addAll(first(pos+1,x));
                return hs;
            } else {
                return first(fst);
            }
        }
    }

    private Set<TableColumnEntry<K>> first(int pos, GrammarTerm<K>... x) {
        Set<TableColumnEntry<K>> hs = new HashSet<>();
        if (x.length==0||pos>=x.length) {
            hs.add(new Varepsilon<>());
            return hs;
        } else {
            nullables();
            GrammarTerm<K> fst = x[pos];
            if (nullables.contains(fst)) {
                hs.addAll(first(fst));
                hs.remove(new Varepsilon<K>());
                hs.addAll(first(pos+1,x));
                return hs;
            } else {
                return first(fst);
            }
        }
    }

    public OnInput<K>[] firstsToLookahead(Collection<TableColumnEntry<K>> coll) {
        return coll.stream().filter(TableColumnEntry::isInput).map(TableColumnEntry::asOnInput).toArray(value -> (OnInput<K>[])Array.newInstance(OnInput.class, value));
    }

    public Stream<GrammarTerm<K>> firstsToLookaheadStream(Collection<TableColumnEntry<K>> coll) {
        return coll.stream().filter(TableColumnEntry::isInput).map(TableColumnEntry::asGrammarTerm);
    }

    public Set<TableColumnEntry<K>> follow(NonTerminal<K> x) {
        Set<TableColumnEntry<K>> hs = new HashSet<>();
        if (x.equals(this.starter)) {
            hs.add(new Varepsilon<K>());
        }
        for (Rule<K> y : rules) {
            Opt<Item<K>> opt = Item.generate(y, x);
            if (!opt.isError()) {
                Item<K> lh = opt.value();
                do {
                    Set<TableColumnEntry<K>> betaFirst = first(lh);
                    hs.addAll(betaFirst);
                    hs.remove(new Varepsilon<K>());
                    if (lh.pos==lh.elems.length || betaFirst.contains(new Varepsilon<K>())) {
                        hs.addAll(follow(y.header()));
                    }
                } while (lh!=null);
            }
        }
        return hs;
    }

    public ItemWithLookahead<K> startItem() {
        return ItemWithLookahead.generate(this,map.get(this.starter).stream().findFirst().get()).value();
    }
}
