package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items;

import com.sun.corba.se.impl.ior.EncapsulationUtility;
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
public class ItemWithLookahead implements IItem<ItemWithLookahead> {

    public void setLookaheadSymbols(OnInput[] lookaheadSymbols) {
        this.lookaheadSymbols = lookaheadSymbols;
    }

    public  OnInput[] lookaheadSymbols;
    public final Item orig;
    private final Grammar g;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[").append(orig.toString()).append(", ");
        for (OnInput x : lookaheadSymbols) sb.append(x).append(",");
        sb.append("]");
        return sb.toString();
    }

    private ItemWithLookahead(Grammar gram, NonTerminal nt, GrammarTerm[] elems, int pos, OnInput...lookaheads) {
        orig = new Item(nt, elems, pos);
        this.lookaheadSymbols = lookaheads;
        g = gram;
    }

    ItemWithLookahead(Grammar gram, Item orig, OnInput...lookaheads) {
        this.orig = orig;
        this.lookaheadSymbols = lookaheads;
        g = gram;
    }

    public static <K extends Enum > Opt<ItemWithLookahead> generate(Grammar gram, Rule r, int pos, OnInput...lookaheads) {
        return Item.generate(r.header(),r.tail(),pos).ifte(y-> Opt.of(y.extendWithLookaheads(gram,lookaheads)), Opt::err);
    }

    public static <K extends Enum > Opt<ItemWithLookahead> generate(Grammar gram, Rule r) {
        return Item.generate(r.header(),r.tail(),0).ifte(y-> Opt.of(y.extendWithLookaheads(gram, new Varepsilon<>())), Opt::err);
    }

    @Override
    public Iterator<ItemWithLookahead> iterator() {
        ItemWithLookahead content = this;
        return new Iterator<ItemWithLookahead>() {

            ItemWithLookahead self = content;

            @Override
            public boolean hasNext() {
                return self.orig.hasNextitemMove();
            }

            @Override
            public ItemWithLookahead next() {
                ItemWithLookahead toret = self;
                self = new ItemWithLookahead(g,self.orig.getNextItemMove(),self.lookaheadSymbols);
                return toret;
            }
        };
    }

    @Override
    public NonTerminal getHead() {
        return orig.head;
    }

    @Override
    public GrammarTerm[] getCore() {
        return orig.elems;
    }

    @Override
    public int getItemPos() {
        return orig.pos;
    }

    @Override
    public GrammarTerm[] getElementsNextToCore() {
        return Arrays
                .stream(lookaheadSymbols)
                .map(x -> this.g.firstsToLookaheadStream(this.g.first(orig.getElementsNextToCore(x.asTableColumnValue()))))
                .flatMap(x->x)
                .toArray(value ->  (GrammarTerm[]) Array.newInstance(GrammarTerm.class, value));
    }


    @Override
    public List<GrammarTerm> getElementsNextToCore(GrammarTerm withLookahead) {
        throw new RuntimeException("ERRROR: ItemWithLookahead provides the lookaheads itself");
    }

    @Override
    public boolean hasNextitemMove() {
        return orig.hasNextitemMove();
    }

    @Override
    public ItemWithLookahead getNextItemMove() {
        return hasNextitemMove() ? new ItemWithLookahead(g,orig.getNextItemMove(),lookaheadSymbols) : null;
    }

    public static Collection<ItemWithLookahead> moveForward(Collection<ItemWithLookahead> toMove) {
        return toMove.stream().map(x-> x.getNextItemMove()).collect(Collectors.toSet());
    }

    @Override
    public Opt<GrammarTerm> elementAtCurrentPosition() {
        return orig.elementAtCurrentPosition();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof ItemWithLookahead)) return false;

        ItemWithLookahead that = (ItemWithLookahead) o;

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

    public Iterable<GrammarTerm> getIterableLookaheadSymbols() {
        return () -> Arrays.stream(lookaheadSymbols).map(x->x.asGrammarTerm()).iterator();
    }

    public List<GrammarTerm> getListLookaheadSymbols() {
        return Arrays.stream(lookaheadSymbols).map(x->x.asGrammarTerm()).collect(Collectors.toList());
    }

    public ItemWithLookahead setLookaheadSymbols(Collection<GrammarTerm> value) {
        lookaheadSymbols = value.stream().filter(x->x.isInput()).map(x->x.toInput()).toArray((i)-> (OnInput[]) Array.newInstance(OnInput.class, i));
        return this;
    }
}
