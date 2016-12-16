package it.giacomobergami.datatypelang.compiler;

import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.State;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.TypesafeTable;
import it.giacomobergami.datatypelang.utils.ForFiles;

import java.io.File;
import java.util.*;
import java.util.function.Predicate;

/**
 * Created by vasistas on 16/12/16.
 */
public class Configuration {

    Grammar grammar;
    Lexer lexer;
    Predicate<OnInput> pred;
    TypesafeTable tst;

    public Configuration(File file) {
        LinkedHashMap<String,String> terminalWithRegex = new LinkedHashMap<>();
        HashMap<String,String> convertedToName = new HashMap<>();
        String fileStirng = ForFiles.toString(file);
        String rows[] = fileStirng.split("\n");
        ArrayList<Rule> ruleList = new ArrayList<>();
        NonTerminal firstRule = null;
        pred = OnInput::nonEmpty;

        int automatic = 0;

        int phase = 0;
        boolean justStarted = true;

        for (String row : rows) {
            if (phase == 0) {
                if (justStarted) {
                    if (row.equals("terminals:")) {
                        justStarted = false;
                    };
                } else {
                    if (row.length()==0) {
                        justStarted = true;
                        phase++;
                    } else {
                        if (row.contains("\t")) {
                            String name = row.substring(0,row.indexOf('\t'));
                            String regex = row.substring(row.indexOf('\t')+1);
                            terminalWithRegex.put(name,regex);
                        } else {
                            String thisRow = row.trim();
                            String auto = "auto"+(automatic++);
                            terminalWithRegex.put(auto,"\\Q"+thisRow+"\\E");
                            convertedToName.put(thisRow,auto);
                        }
                    }
                }
            } else if (phase == 1) {
                if (justStarted) {
                    if (row.equals("rules:")) {
                        justStarted = false;
                    }
                } else {
                    if (row.equals(".")) {
                        justStarted = true;
                        phase++;
                    } else {
                        NonTerminal headOfRule;
                        String head = row.substring(0,row.indexOf("->")).trim();
                        headOfRule = new NonTerminal(head);
                        if (head.startsWith("!")) {
                            head = head.substring(1);
                            headOfRule = new NonTerminal(head);
                            firstRule = headOfRule;
                        }
                        GrammarTerm[] rules = Arrays.stream(row.substring(row.indexOf("->")+2).trim().split("\\s+")).map(x-> {
                            if (terminalWithRegex.containsKey(x))
                                return new Terminal(x);
                            else if (convertedToName.containsKey(x))
                                return new Terminal(convertedToName.get(x));
                            return new NonTerminal(x);
                        }).toArray((i) -> new GrammarTerm[i]);
                        ruleList.add(new Rule(headOfRule,rules));
                    }
                }
            } else if (phase == 2) {
                if (row.startsWith("trail: ")) {
                    pred = new Predicate<OnInput>() {
                        Set<String> h = new HashSet<>(Arrays.asList(row.replaceFirst("trail: ", "").split(",")));
                        @Override
                        public boolean test(OnInput onInput) {
                            return onInput.nonEmpty() && (!h.contains(onInput.getType()));
                        }
                    };
                }
            }
        }
        if (phase<2) {
            throw new RuntimeException("Error, the grammar compiler was stuck at phase "+phase);
        }
        grammar = new Grammar(firstRule,ruleList.toArray(new Rule[ruleList.size()]));
        lexer = new Lexer(terminalWithRegex);
        tst = null;
    }

    public Iterable<OnInput> readFromInputFile(String s) {
        return () -> lexer.lex(ForFiles.toString(s),pred);
    }

    public Iterable<OnInput> readFromInputFile(File f) {
        return () -> lexer.lex(ForFiles.toString(f),pred);
    }

    public  TypesafeTable generateParser() {
        if (tst==null) {
            int idx = 0;
            ItemWithLookahead starter = grammar.startItem();
            System.out.println(starter);
            State s1 = grammar.stateFromLookahead(idx++, starter);
            tst = new TypesafeTable();
            s1.initTypesafeTable(grammar, tst);
        }
        return tst;
    }

    public ANTerm parseInput(File f) {
        return generateParser().recognize(grammar,(TerminalIterator) readFromInputFile(f).iterator());
    }

    public void compileRulesToJavaClasses(String s) {
        grammar.compileRulesToJavaClasses(s);
    }
}
