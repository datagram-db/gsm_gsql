package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.Iterator;

/**
 * Created by vasistas on 12/12/16.
 */
public class ItemWithLookahead<K extends Enum> implements IItem<K,ItemWithLookahead<K>> {

    public final OnInput<K>[] lookaheadSymbols;
    Item<K> orig;
    private ItemWithLookahead(NonTerminal<K> nt, GrammarTerm<K>[] elems, int pos, OnInput<K>...lookaheads) {
        orig = new Item<K>(nt, elems, pos);
        this.lookaheadSymbols = lookaheads;
    }

    private ItemWithLookahead(Item<K> orig, OnInput<K>...lookaheads) {
        this.orig = orig;
        this.lookaheadSymbols = lookaheads;
    }

    public static <K extends Enum >Opt<ItemWithLookahead<K>>generate(Rule<K> r, int pos, OnInput<K>...lookaheads) {
        return Item.generate(r.header(),r.tail(),pos).ifte(y-> Opt.of(new ItemWithLookahead<>(y,lookaheads)), Opt::err);
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
                self = new ItemWithLookahead<K>(self.orig.getNextItemMove(),self.lookaheadSymbols);
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
    public boolean hasNextitemMove() {
        return orig.hasNextitemMove();
    }

    @Override
    public ItemWithLookahead<K> getNextItemMove() {
        return hasNextitemMove() ? new ItemWithLookahead<K>(orig.getNextItemMove(),lookaheadSymbols) : null;
    }

    @Override
    public Opt<GrammarTerm<K>> elementAtCurrentPosition() {
        return orig.elementAtCurrentPosition();
    }
}
