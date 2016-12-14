package it.giacomobergami.datatypelang.compiler.parser;

import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.function.Consumer;
import java.util.function.Function;

/**
 * Defines a cell of a rule table. Whenever it is used to define some rules, the elimination rule is used.
 */
public class TableCase {

    private final int shiftInt;
    private final Rule reduce;
    private final boolean isAccept;

    public TableCase(int shift) {
        this.shiftInt = shift;
        reduce = null;
        isAccept = false;
    }

    public TableCase(Rule red) {
        this.reduce = red;
        this.shiftInt = -1;
        isAccept = false;
    }

    public TableCase() {
        this.shiftInt = -1;
        this.reduce = null;
        isAccept = true;
    }

    public <E extends Throwable> Opt<Boolean> eliminationRule2(Consumer<Integer> doShift, Function<Rule, Opt<Boolean>> doReduce) {
        if (isAccept)
            return Opt.of(true);
        else if (reduce == null) {
            doShift.accept(shiftInt);
            return Opt.of(false);
        } else {
            return (doReduce.apply(reduce));
        }
    }

    @Override
    public String toString() {
        if (isAccept) return "Accept!";
        else if (reduce==null) {
            return "S("+shiftInt+")";
        } else return "R("+reduce.toString()+")";
    }

    /**
     *
     * @param doShift
     * @param doReduce
     * @param <E>
     * @return - true if it has to accept and terminate
     *         - false if it has to continuate
     *         - err if it has an error
     */
    public <E extends Throwable> Opt<Boolean> eliminationRule(Consumer<Integer> doShift, Function<Rule, Boolean> doReduce) {
        if (isAccept)
            return Opt.of(true);
        else if (reduce == null) {
            doShift.accept(shiftInt);
            return Opt.of(false);
        } else {
            return doReduce.apply(reduce) ? Opt.of(false) : Opt.err();
        }
    }
}
