package it.giacomobergami.datatypelang.compiler.parser;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import com.sun.org.apache.xpath.internal.operations.Bool;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.OnStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.TypesafeTable;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Created by vasistas on 11/12/16.
 */
public class ParserTable<K extends Enum, NT extends NonTerminal> {

    TypesafeTable<K> table;
    Deque<Integer> stateStack;

    public ParserTable(Grammar<K> g) {
        table = new TypesafeTable(g);
        stateStack = new ArrayDeque<>();
    }

    public boolean recognize(TerminalIterator<K> terminals) {
        Deque<OnStack<K>> recognizedInput = new ArrayDeque<>();
        boolean cond = false;
        while (!cond) {
            //Return the next state position
            Integer s1 = stateStack.peek();

            //get the next terminal (or empty element, if it doesn't exist
            OnInput<K> w = terminals.next();

            // If the table contains the entry
            Opt<Boolean> b = table.get(s1,w.asTableColumnValue()).ifte(y -> y.eliminationRule2(
                    // a. If I have a shift operation, then… and save the terminal values,
                    shiftNo -> {
                        // a1. …push the state in the stack,
                        stateStack.push(shiftNo);
                        // a2. …and push the recognized text in the stack.
                        if (w instanceof Token) recognizedInput.push((Token<K>) w);
                    },

                    // b. if I have a reduce operation,
                    x -> {
                        // b1. …Apply the reduction: reduce the stack input
                        x.reduce(recognizedInput);
                        // b2. …Apply the reduction: backtrack to the previous state
                        for (int i = 0; i < x.tail().length; i++) stateStack.pop();
                        // b3. get the state where we have to restart from
                        Integer restartFrom = stateStack.peek();
                        // b4. checks if I can perform the goto action within the table
                        return table
                                .get(restartFrom, (TableColumnEntry<K>) x.header())
                                .ifte(
                                        z -> z.eliminationRule(stateStack::push, w1 -> false),
                                        () -> Opt.of(false)
                                     );
                    }),()->Opt.of(false));

            if (b.isError()) {
                return false;
            } else {
                cond = b.value();
            }
        }
        return true;
    }

}
