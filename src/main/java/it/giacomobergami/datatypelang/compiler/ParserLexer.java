package it.giacomobergami.datatypelang.compiler;

import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XMLAst;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.State;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.StackVisitor;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Parser;
import it.giacomobergami.datatypelang.gui.MultiTaskEditor;
import it.giacomobergami.datatypelang.gui.editor.KeywordStyledDocument;
import it.giacomobergami.datatypelang.gui.styles.StyleCollection;
import it.giacomobergami.datatypelang.gui.styles.myStyle;
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.utils.data.LazyRead;
import it.giacomobergami.datatypelang.utils.funcs.OptErr;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import java.awt.*;
import java.io.File;
import java.util.*;
import java.util.function.Predicate;

/**
 * Created by vasistas on 16/12/16.
 */
public class ParserLexer {

    Grammar grammar;
    Lexer lexer;
    Predicate<OnInput> pred;
    Parser tst;
    StyleCollection sc;
    MultiTaskEditor mte;


    public ParserLexer(File grammarFile) {
        Style error = myStyle.CONTEXT.addStyle("__ERROR__", null);
        StyleConstants.setForeground(error, new Color(255,0,0));
        StyleConstants.setBold(error, true);
        StyleConstants.setUnderline(error,true);

        LinkedHashMap<String,String> terminalWithRegex = new LinkedHashMap<>();
        HashMap<String,String> convertedToName = new HashMap<>();
        String fileStirng = ForFiles.toString(grammarFile);
        String rows[] = fileStirng.split("\n");
        ArrayList<Rule> ruleList = new ArrayList<>();
        NonTerminal firstRule = null;
        pred = OnInput::nonEmpty;
        sc = new StyleCollection(error);

        int automatic = 0;

        int phase = 0;
        boolean justStarted = true;
        boolean isHilight = false;

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
                } else if (row.startsWith("highlight:")||isHilight) {
                    isHilight = true;
                    if (row.trim().length()==0) {
                        isHilight=false;
                    } else if (!row.startsWith("highlight:")) {
                        String name = row.substring(0,row.indexOf('[')).trim();

                        //Colors
                        String rgb[] = row.substring(row.indexOf('[')+1,row.indexOf(']')).split(",");
                        int r = Integer.parseInt(rgb[0].trim());
                        int g = Integer.parseInt(rgb[1].trim());
                        int b = Integer.parseInt(rgb[2].trim());
                        Color col = new Color(r,g,b);

                        myStyle s = new myStyle(col,name);
                        for (String terminalName : row.substring(row.indexOf(':')+1).split(",")) {
                            terminalName = terminalName.trim();
                            s.addRegexGroupName(convertedToName.getOrDefault(terminalName,terminalName));
                        }
                        sc.addStyle(s);
                    }
                }
            }
        }
        if (phase<2) {
            throw new RuntimeException("Error, the grammar compiler was stuck at phase "+phase);
        }
        grammar = new Grammar(firstRule,ruleList.toArray(new Rule[ruleList.size()]));
        lexer = new Lexer(terminalWithRegex);
        sc.setLexer(lexer);
        tst = null;
    }

    /*public Iterable<OnInput> readFromInputFile(String s) {
        return () -> lexer.lex(ForFiles.toString(s),pred);
    }

    public Iterable<OnInput> readFromInputFile(File f) {
        return () -> lexer.lex(ForFiles.toString(f),pred);
    }*/

    public LazyRead digestInputFile(File f) {
        return new LazyRead(lexer.lex(ForFiles.toString(f),pred));
    }

    public Parser generateParser() {
        if (tst==null) {
            int idx = 0;
            ItemWithLookahead starter = grammar.startItem();
            //System.out.println(starter);
            State s1 = grammar.stateFromLookahead(idx++, starter);
            tst = new Parser();
            s1.initTypesafeTable(grammar, tst);
            //System.err.println(tst);
        }
        return tst;
    }

    public OptErr<ANTerm,OnInput> parseInput(File f) {
        return generateParser().recognize(grammar, digestInputFile(f));
    }

    public XMLAst toXML(ANTerm term) {
        return new XMLAst(new StackVisitor(grammar).visit(term));
    }

    public void compileRulesToJavaClasses(String s) {
        grammar.compileRulesToJavaClasses(s);
    }

    public void showEditor(String s) {
        mte = new MultiTaskEditor(sc);
        mte.setVisible(true);
        mte.setText(s);
    }

    public void setStyleCollection(KeywordStyledDocument ksd) {
        ksd.updateStyleCollection(sc);
    }

    public void showError(OnInput onInput) {
        if (mte!=null) {
            if (onInput.asGrammarTerm().isTerminal()) {
                Token t = (Token) onInput;
                mte.setError(t);
            }
        }
    }
}
