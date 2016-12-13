package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import com.google.common.collect.HashMultimap;
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

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by vasistas on 12/12/16.
 */
public class Grammar<K extends Enum> {

    private final NonTerminal<K> starter;
    private final Multimap<NonTerminal<K>,Rule> map;
    public final Rule<K>[] rules;
    private Set<Terminal<K>> terminals;
    private Set<NonTerminal<K>> nullables;



    public State<K> fromLookahead(int No, ItemWithLookahead<K> next) {
        if (next==null)
            return null;
        else {
            // A -> αxβ
            Opt<GrammarTerm<K>> x = next.elementAtCurrentPosition();

            // The next element has been already visited, so I just return the actual state.
            // In this case I should generate a reduce operation
            if (next.getItemPos()==next.getCore().length || x.isError()) {
                return new State<K>(next);
            }
            // Otherwise, I have to check the elements stored within the element
            else {
                GrammarTerm<K> t = x.value();
                if (t.isTerminal()) {
                    // In this case I only have a shift operation. I do not have to visit the other elements
                    return new State<K>(next);
                } else {
                    Set<GrammarTerm<K>> state = new HashSet<>();
                    state.add(t);
                    int size;
                    do {
                        //
                        size = state.size();

                        //Now, if there have been some insertions, then I
                    } while (size!=state.size());
                }
            }
        }
    }

    private Grammar(NonTerminal<K> starter,Rule<K>... rules) {
        this.starter = starter;
        map = HashMultimap.create();
        for (Rule x : rules) map.put(x.header(),x);
        this.rules = rules;
        terminals = null;
        nullables = null;
    }

    public static <K extends Enum> Opt<Grammar<K>> generate(NonTerminal<K> starter, Rule<K>... rules) {
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
                for (GrammarTerm<K> y : x.tail()) {
                    if (y instanceof NonTerminal) {
                        if (!nullables.contains(y)) {
                            toadd = false;
                            continue;
                        }
                    }
                }
                if (toadd) nullables.add(x.header());
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
                GrammarTerm<K>[] tl = y.tail();
                for (int i = 0; i < tl.length; i++) {
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

    public Set<TableColumnEntry<K>> first(GrammarTerm<K>... x) {
        return first(0,x);
    }

    public Set<TableColumnEntry<K>> first(Item<K> lh) {
        return first((lh.pos),lh.elems);
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
                hs.addAll(first(x));
                hs.remove(new Varepsilon<K>());
                hs.addAll(first(pos+1,x));
                return hs;
            } else {
                return first(fst);
            }
        }
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

}
