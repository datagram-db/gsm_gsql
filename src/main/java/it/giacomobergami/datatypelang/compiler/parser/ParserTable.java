package it.giacomobergami.datatypelang.compiler.parser;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.cp.CP;
import it.giacomobergami.datatypelang.compiler.parser.cp.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.cp.Terminal;
import it.giacomobergami.datatypelang.utils.funcs.OnExcpt;

import java.util.Stack;
import java.util.function.Consumer;

/**
 * Created by vasistas on 11/12/16.
 */
public class ParserTable<K extends Enum, NT extends NonTerminal, T extends Terminal<K>> {

    Table<Integer,CP,TableCase> table;
    Stack<Integer> pila;

    public class TableCase {

        private final int shiftInt;
        private final Reduce<K,NT,T> reduce;

        public TableCase(int shift) {
            this.shiftInt = shift;
            reduce = null;
        }

        public TableCase(Reduce<K,NT,T> red) {
            this.reduce = red;
            this.shiftInt = -1;
        }

        public <E extends Throwable> boolean  cases(Consumer<Integer> doShift, Consumer<Reduce<K,NT,T>> doReduce){
            if (reduce==null) {
                doShift.accept(shiftInt);
                return true;
            } else {
/*                ThrowableFunction<Reduce<K, NT, T>, Boolean, E> exo = knttReduce -> {
                    doReduce.accept(knttReduce);
                    return true;
                };
                Function<Reduce<K, NT, T>, Boolean> fal = x -> false;*/
                Boolean toret =  new OnExcpt<>(reduce).as(null,null);
            }
        }

    }

    public ParserTable() {
        table  = HashBasedTable.create();
    }

    public void recognize(TerminalIterator<K> terminals) {
        while (true) {
               Integer s1 = pila.peek();
               Terminal<K> w = terminals.next();
               if (this.table.contains(s1,w)) {
                   this.table.get(s1,w).cases(pila::push, x->{
                       for (int i=0; i<x.elements.length; i++) pila.pop();
                       Integer n = pila.peek();
                       if (table.contains(n,x.head)) {
                           TableCase t = table.get(n, x.head);
                       }
                   });

               }

        }
    }

}
