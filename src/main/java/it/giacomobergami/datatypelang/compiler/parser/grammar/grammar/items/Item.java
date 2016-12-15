package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.Array;
import it.giacomobergami.datatypelang.utils.funcs.Opt;
import org.apache.commons.lang3.ArrayUtils;

import java.util.*;

/**
 * Created by vasistas on 12/12/16.
 */
public class Item<K extends Enum> implements  IItem<K,Item<K>> {

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Item)) return false;

        Item<?> item = (Item<?>) o;

        if (pos != item.pos) return false;
        if (head != null ? !head.equals(item.head) : item.head != null) return false;
        // Probably incorrect - comparing Object[] arrays with Arrays.equals
        return Arrays.equals(elems, item.elems);
    }

    @Override
    public int hashCode() {
        int result = head != null ? head.hashCode() : 0;
        result = 31 * result + Arrays.hashCode(elems);
        result = 31 * result + pos;
        return result;
    }

    public final NonTerminal<K> head;
    public final GrammarTerm<K>[] elems;
    public final int pos;

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(head).append(" -> ");
        for (int i=0; i<=elems.length; i++) {
            if (i==pos) sb.append(".");
            if (i<elems.length) sb.append(elems[i]);
        }
        return sb.toString();
    }

    protected Item(NonTerminal<K> head, GrammarTerm<K>[] elems, int pos) {
        this.elems = elems;
        this.pos = pos;
        this.head = head;
    }

    public static <K extends Enum> Opt<Item<K>> generate(NonTerminal<K> head,GrammarTerm<K>[] elems, int pos) {
        return pos >= 0 && elems.length > pos ? Opt.of(new Item<K>(head,elems, pos)) : Opt.err();
    }

    public ItemWithLookahead<K> extendWithLookaheads(Grammar<K> gram, OnInput<K>...lookaheads) {
        return new ItemWithLookahead(gram,this,lookaheads);
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

    @Override
    public GrammarTerm<K>[] getElementsNextToCore() {
        ArrayList<GrammarTerm<K>> al = new ArrayList<>();
        if (pos==elems.length)
            return (GrammarTerm<K>[]) new Object[0];
        else {
            return  ArrayUtils.subarray(elems, pos + 1, elems.length - 1);
        }
    }

    @Override
    public List<GrammarTerm<K>> getElementsNextToCore(GrammarTerm<K> withLookahead) {
        ArrayList<GrammarTerm<K>> k = new ArrayList<>();
        if (pos==elems.length)
            return k;
        else {
            for (GrammarTerm<K> x : elems) {
                k.add(x.asTableColumnEntry());
            }
            k.add(withLookahead.asTableColumnEntry());
            return k;
        }
    }
}
