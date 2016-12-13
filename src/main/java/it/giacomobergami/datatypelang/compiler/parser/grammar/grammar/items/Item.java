package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.Iterator;

/**
 * Created by vasistas on 12/12/16.
 */
public class Item<K extends Enum> implements  IItem<K,Item<K>> {

    public final NonTerminal<K> head;
    public final GrammarTerm<K>[] elems;
    public final int pos;
    protected Item(NonTerminal<K> head, GrammarTerm<K>[] elems, int pos) {
        this.elems = elems;
        this.pos = pos;
        this.head = head;
    }

    public static <K extends Enum> Opt<Item<K>> generate(NonTerminal<K> head,GrammarTerm<K>[] elems, int pos) {
        return pos > 0 && elems.length >= pos ? Opt.of(new Item<K>(head,elems, pos)) : Opt.err();
    }

    public static <K extends Enum> Opt<Item<K>> generate(Rule<K> r, NonTerminal<K> A) {
        GrammarTerm<K>[] tl = r.tail();
        for (int i=0;i<tl.length;i++) {
            if (tl[i].equals(A)) {
                return generate(r.header(),tl,i);
            }
        }
        return Opt.err();
    }

    public static <K extends Enum> Opt<Item<K>> generate(Item<K> l, NonTerminal<K> A) {
        for (int i=l.pos+1;i<l.elems.length;i++) {
            if (l.elems[i].equals(A)) {
                return generate(l.head,l.elems,i);
            }
        }
        return Opt.err();
    }

    @Override
    public boolean hasNextitemMove() {
        return elems.length>0 && (pos<elems.length);
    }

    @Override
    public Item<K> getNextItemMove() {
        return hasNextitemMove() ? new Item<K>(head,elems,pos+1) : null;
    }

    @Override
    public Opt<GrammarTerm<K>> elementAtCurrentPosition() {
        return (pos<elems.length) ? Opt.of(elems[pos]) : Opt.err();
    }

    @Override
    public Iterator<Item<K>> iterator() {
        Item<K> self = this;
        return new Iterator<Item<K>>() {

            Item<K> current = self;

            @Override
            public boolean hasNext() {
                return current!=null && current.hasNextitemMove();
            }

            @Override
            public Item<K> next() {
                Item<K> toret = current;
                current = toret.hasNextitemMove() ? toret.getNextItemMove() : null;
                return toret;
            }
        };
    }

    @Override
    public NonTerminal<K> getHead() {
        return head;
    }

    @Override
    public GrammarTerm<K>[] getCore() {
        return this.elems;
    }

    @Override
    public int getItemPos() {
        return pos;
    }
}
