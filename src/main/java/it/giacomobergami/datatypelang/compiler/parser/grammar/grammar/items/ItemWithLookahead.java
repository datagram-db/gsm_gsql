package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.GlobalCounter;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by vasistas on 12/12/16.
 */
public class ItemWithLookahead<K extends Enum> implements IItem<K,ItemWithLookahead<K>> {

    public void setLookaheadSymbols(OnInput<K>[] lookaheadSymbols) {
        this.lookaheadSymbols = lookaheadSymbols;
    }

    public  OnInput<K>[] lookaheadSymbols;
    private final Item<K> orig;
    private final Grammar<K> g;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[").append(orig.toString()).append(", ");
        for (OnInput<K> x : lookaheadSymbols) sb.append(x).append(",");
        sb.append("]");
        return sb.toString();
    }

    private ItemWithLookahead(Grammar<K> gram, NonTerminal<K> nt, GrammarTerm<K>[] elems, int pos, OnInput<K>...lookaheads) {
        orig = new Item<K>(nt, elems, pos);
        this.lookaheadSymbols = lookaheads;
        g = gram;
    }

    ItemWithLookahead(Grammar<K> gram, Item<K> orig, OnInput<K>...lookaheads) {
        this.orig = orig;
        this.lookaheadSymbols = lookaheads;
        g = gram;
    }

    public static <K extends Enum > Opt<ItemWithLookahead<K>> generate(Grammar<K> gram, Rule<K> r, int pos, OnInput<K>...lookaheads) {
        return Item.generate(r.header(),r.tail(),pos).ifte(y-> Opt.of(y.extendWithLookaheads(gram,lookaheads)), Opt::err);
    }

    public static <K extends Enum > Opt<ItemWithLookahead<K>> generate(Grammar<K> gram, Rule<K> r) {
        return Item.generate(r.header(),r.tail(),0).ifte(y-> Opt.of(y.extendWithLookaheads(gram, new Varepsilon<>())), Opt::err);
    }

    @Override
    public Iterator<ItemWithLookahead<K>> iterator() {
        ItemWithLookahead<K> content = this;
        return new Iterator<ItemWithLookahead<K>>() {

            ItemWithLookahead<K> self = content;

            @Override
            public boolean hasNext() {
                return self.orig.hasNextitemMove();
            }

            @Override
            public ItemWithLookahead<K> next() {
                ItemWithLookahead<K> toret = self;
                self = new ItemWithLookahead<K>(g,self.orig.getNextItemMove(),self.lookaheadSymbols);
                return toret;
            }
        };
    }

    @Override
    public NonTerminal<K> getHead() {
        return orig.head;
    }

    @Override
    public GrammarTerm<K>[] getCore() {
        return orig.elems;
    }

    @Override
    public int getItemPos() {
        return orig.pos;
    }

    @Override
    public GrammarTerm<K>[] getElementsNextToCore() {
        return Arrays
                .stream(lookaheadSymbols)
                .map(x -> this.g.firstsToLookaheadStream(this.g.first(orig.getElementsNextToCore(x.asTableColumnValue()))))
                .flatMap(x->x)
                .toArray(value ->  (GrammarTerm<K>[]) Array.newInstance(GrammarTerm.class, value));
    }


    @Override
    public List<GrammarTerm<K>> getElementsNextToCore(GrammarTerm<K> withLookahead) {
        throw new RuntimeException("ERRROR: ItemWithLookahead provides the lookaheads itself");
    }

    @Override
    public boolean hasNextitemMove() {
        return orig.hasNextitemMove();
    }

    @Override
    public ItemWithLookahead<K> getNextItemMove() {
        return hasNextitemMove() ? new ItemWithLookahead<K>(g,orig.getNextItemMove(),lookaheadSymbols) : null;
    }

    @Override
    public Opt<GrammarTerm<K>> elementAtCurrentPosition() {
        return orig.elementAtCurrentPosition();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ItemWithLookahead)) return false;

        ItemWithLookahead<?> that = (ItemWithLookahead<?>) o;

        // Probably incorrect - comparing Object[] arrays with Arrays.equals
        if (!Arrays.equals(lookaheadSymbols, that.lookaheadSymbols)) return false;
        return orig != null ? orig.equals(that.orig) : that.orig == null;
    }

    @Override
    public int hashCode() {
        int result = Arrays.hashCode(lookaheadSymbols);
        result = 31 * result + (orig != null ? orig.hashCode() : 0);
        return result;
    }

    public Iterable<GrammarTerm<K>> getIterableLookaheadSymbols() {
        return () -> Arrays.stream(lookaheadSymbols).map(x->x.asGrammarTerm()).iterator();
    }

    public List<GrammarTerm<K>> getListLookaheadSymbols() {
        return Arrays.stream(lookaheadSymbols).map(x->x.asGrammarTerm()).collect(Collectors.toList());
    }

    public ItemWithLookahead<K> setLookaheadSymbols(Collection<GrammarTerm<K>> value) {
        lookaheadSymbols = value.stream().filter(x->x.isInput()).map(x->x.toInput()).toArray((i)-> (OnInput<K>[]) Array.newInstance(OnInput.class, i));
        return this;
    }
}
