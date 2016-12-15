import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.State;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.TypesafeTable;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.util.*;

/**
 * Created by vasistas on 13/12/16.
 */
public class TestingGrammar {

    public enum termine {
        COMMA(";"), ID("\\d"), EQUAL("="), PLUS("\\+");

        public final String pattern;

        @Override
        public String toString() {
            return pattern;
        }

        termine(String pattern) {
            this.pattern = pattern;
        }
    }

    public static NonTerminal<termine> nt(String NT) {
        return new NonTerminal<>(NT);
    }

    public static Terminal<termine> t(String t) {
        return new Terminal(t);
    }

    static ArrayList<Rule<termine>> hsr = new ArrayList<>();
    public static void addRule(NonTerminal<termine> nt, GrammarTerm<termine>... t) {
        hsr.add(new Rule(nt,t));
    }
    public static void addRule(NonTerminal<termine> nt) {
        hsr.add(new Rule(nt));
    }

    public static Map<String,String> terminalToRegex() {
        HashMap<String,String> toret = new HashMap<>();
        toret.put("col",";");
        toret.put("id","\\d+");
        toret.put("eq","=");
        toret.put("plus","\\+");
        return toret;
    }

    public static ArrayList<Rule<termine>> createRules1() {
        addRule(nt("SP"),nt("S"));
        addRule(nt("S"),nt("S"),t("col"),nt("A"));
        addRule(nt("S"), nt("A"));
        addRule(nt("A"),nt("E"));
        addRule(nt("A"),t("id"),t("eq"),nt("E"));
        addRule(nt("E"),nt("E"),t("plus"),t("id"));
        addRule(nt("E"),t("id"));
        return hsr;
    }

    public static void checkingEquality(List<Rule<termine>> r) {
        for (int i=0; i<r.size(); i++)
            for (int j=0; j<r.size(); j++)
                if (i==j) {
                    if (!r.get(i).equals(r.get(j))) {
                        throw new RuntimeException("Error: equal elements seems to be different");
                    }
                } else {
                    if (r.get(i).equals(r.get(j))) {
                        throw new RuntimeException("Error: different elements seems to be equal");
                    }
                }
    }

    public static Grammar<termine> createGrammar(NonTerminal<termine> firstRule, Collection<Rule<termine>> c) {
        if (c==null || c.isEmpty())
            throw new RuntimeException("Error: the provided set of rules is empty");
        Opt<Grammar<termine>> gram = Grammar.generateGrammar(firstRule,c);
        if (gram.isError())
            throw new RuntimeException("Error: the generated grammar cannot find the first rule");
        return gram.value();
    }

    public static void main(String args[]) {
        System.out.println("Creating the rules…");
        ArrayList<Rule<termine>> r = createRules1();
        System.out.println(r);
        System.out.println("1. Testing rules equality…");
        checkingEquality(r);
        System.out.println("Creating a grammar");
        Grammar<termine> gram = createGrammar(nt("SP"),r);
        System.out.println("Testing the first and follow sets");
        for (NonTerminal<termine> x : gram.getAllNonTerminals()) {
            //if (x.getValue().equals("S"))
            System.out.println(x+"--->"+gram.first(x));
        }
        int idx = 0;
        System.out.println("Generating the first state");
        ItemWithLookahead<termine> starter = gram.startItem();
        System.out.println(starter);
        State<termine> s1 = gram.stateFromLookahead(idx++,starter);
        TypesafeTable<termine> tst = new TypesafeTable<>();
        s1.initTypesafeTable(gram,tst);

        System.out.println("StatesNo="+tst.numberOfStates()+" vs. "+tst.statesNumber());
        System.out.println(tst);
        System.out.println(tst.table);

        System.out.println("Creating a lexer…");
        Lexer l = new Lexer(terminalToRegex());
        System.out.println("Tokening \"2=2;8=5+3\"");
        Iterable<OnInput<termine>> ret = () -> l.lex("2=2;8=5+3");
        ret.forEach(System.out::println);
        System.out.println("Using the Parser for the generated tokens");
        ANTerm<termine> result = tst.recognize(gram,(TerminalIterator<termine>) ret.iterator());


        System.out.println("…Everything went smoothly! :=D");
    }

}
