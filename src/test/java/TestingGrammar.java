import it.giacomobergami.datatypelang.compiler.Configuration;
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
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.utils.data.Pair;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import java.io.File;
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

    public static NonTerminal nt(String NT) {
        return new NonTerminal(NT);
    }

    public static Terminal t(String t) {
        return new Terminal(t);
    }

    static ArrayList<Rule> hsr = new ArrayList<>();
    public static void addRule(NonTerminal nt, GrammarTerm... t) {
        hsr.add(new Rule(nt,t));
    }
    public static void addRule(NonTerminal nt) {
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

    public static ArrayList<Rule> createRules1() {
        addRule(nt("SP"),nt("S"));
        addRule(nt("S"),nt("S"),t("col"),nt("A"));
        addRule(nt("S"), nt("A"));
        addRule(nt("A"),nt("E"));
        addRule(nt("A"),t("id"),t("eq"),nt("E"));
        addRule(nt("E"),nt("E"),t("plus"),t("id"));
        addRule(nt("E"),t("id"));

        return hsr;
    }

    public static void checkingEquality(List<Rule> r) {
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

    public static Grammar createGrammar(NonTerminal firstRule, Collection<Rule> c) {
        if (c==null || c.isEmpty())
            throw new RuntimeException("Error: the provided set of rules is empty");
        Opt<Grammar> gram = Grammar.generateGrammar(firstRule,c);
        if (gram.isError())
            throw new RuntimeException("Error: the generated grammar cannot find the first rule");
        return gram.value();
    }

    public static Pair<Grammar,Lexer> internalTest() {
        System.out.println("Creating the rules…");
        ArrayList<Rule> r = createRules1();
        System.out.println(r);
        System.out.println("1. Testing rules equality…");
        checkingEquality(r);
        System.out.println("Creating a grammar");
        it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar gram = createGrammar(nt("SP"),r);
        System.out.println("Testing the first and follow sets");
        for (NonTerminal x : gram.getAllNonTerminals()) {
            //if (x.getValue().equals("S"))
            System.out.println(x+"--->"+gram.first(x));
        }
        System.out.println("Creating a lexer…");
        Lexer l = new Lexer(terminalToRegex());
        System.out.println("Tokening \"2=2;8=5+3\"");
        Iterable<OnInput> ret = () -> l.lex("2=2;8=5+3");
        ret.forEach(System.out::println);
        System.out.println("Using the Parser for the generated tokens");
        return new Pair<>(gram,l);
    }

    public static Pair<Grammar,Lexer> deduceFromPair() {
        return Grammar.parseGrammarFromFile(new File("typetest/typeslang.txt").getAbsoluteFile().toPath());
    }
    public static String inputFromFile(String path) {
        return ForFiles.toString(path);
    }

    public static void main(String args[]) {
        Configuration configuration = new Configuration(new File("typetest/typeslang.txt").getAbsoluteFile());
        ANTerm result = configuration.parseInput(new File("typetest/input.txt").getAbsoluteFile());
        if (result!=null)
            System.out.println("…Everything went smoothly! :=D ");
        else
            throw new RuntimeException("Error: input not recognized");


        configuration.compileRulesToJavaClasses("test.package");
    }



}
