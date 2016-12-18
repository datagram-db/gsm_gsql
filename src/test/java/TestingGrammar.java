import com.google.common.collect.HashMultimap;
import com.google.common.collect.Iterables;
import com.google.common.collect.Multimap;
import com.sun.org.apache.xalan.internal.xsltc.compiler.util.MultiHashtable;
import it.giacomobergami.datatypelang.compiler.Configuration;
import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XMLAst;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XPathProcesser;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.representation.Type;
import it.giacomobergami.datatypelang.representation.TypeEnvironment;
import it.giacomobergami.datatypelang.representation.compiler.Filler;
import it.giacomobergami.datatypelang.representation.compiler.JSONElem;
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.utils.data.Pair;
import it.giacomobergami.datatypelang.utils.funcs.Opt;
import it.giacomobergami.datatypelang.utils.regex.Strings;

import java.io.File;
import java.util.*;
import java.util.function.Consumer;
import java.util.regex.Matcher;

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


    public static String inputFromFile(String path) {
        return ForFiles.toString(path);
    }

    public static void main(String args[]) {
        //String t = "na \"horoto\"";
        //System.out.println(t.replaceAll("'([^\\\\']+|\\\\([btnfr\"'\\\\]|[0-3]?[0-7]{1,2}|u[0-9a-fA-F]{4}))*'|\"([^\\\\\"]+|\\\\([btnfr\"'\\\\]|[0-3]?[0-7]{1,2}|u[0-9a-fA-F]{4}))*\"",t));
        //System.exit(1);
        Configuration configuration = new Configuration(new File("typetest/typeslang.txt").getAbsoluteFile());
        ANTerm result = configuration.parseInput(new File("typetest/input.txt").getAbsoluteFile());
        XMLAst d = configuration.toXML(result);
        //System.out.println(d.toString());
        //d.forest(XPathLanguageQueries.selectStatements()).forEach(System.out::println);
        Multimap<Type,String> compileRecordAs = HashMultimap.create();
        XPathProcesser processer = new XPathProcesser();
        Filler f = new Filler();

        //Type declaration
        processer.setConsumer(XPathProcesser.setNonTerminalReduction("Typedef"), xmlAst -> {
            XMLAst array[] = Iterables.toArray(xmlAst.getChildren(),XMLAst.class);
            if (array.length>0) {
                String languageType = array[2].getContent();
                String nativeType = array[4].getContent();
                boolean isMutable = array[1].getChildren().iterator().next().getContent().equals("mutable");
                f.addNativeType(languageType,new JSONElem(nativeType,isMutable,-1));
                System.err.println("Declaring native type "+nativeType);
            }
        });
        processer.setConsumer(XPathProcesser.setNonTerminalReduction("Access"), xmlAst -> {
            String arity = Strings.unquote(xmlAst.getChild(4).getContent());
            String data  = Strings.unquote(xmlAst.getChild(6).getContent());
            boolean forAllFixed = (xmlAst.getChild(1).getContent().equals("allfixed"));
            String type = (xmlAst.getChild(1).getContent());
            if (forAllFixed) type = "fixed_"; else type = type+"_";
            f.setSnippet(type+"arity",arity);
            f.setSnippet(type+"data",data);
            System.err.println("Getting other type information for: "+type);
        });

        //Get all the declarations
        processer.setConsumer(XPathProcesser.setNonTerminalReduction("Declare"), xmlAst -> {
            XMLAst whatToDeclare = xmlAst.getChild(1);
            //Record declaration
            if (whatToDeclare.isAttribute("head","Record")) {
                //Getting the record name
                String recordName = whatToDeclare.getChild(1).getContent();
                TypeEnvironment.RecordCreator rec = f.declareRecord(recordName);
                //Getting the record fields
                whatToDeclare.forest(XPathProcesser.setNonTerminalReduction("Field")).forEach(x->{
                    rec.addField(x.getChild(0).getContent(),x.getChild(2).getContent());
                });
                rec.close(); //Compiling the record definition
                Type record = f.getCompiledType(recordName);
                XMLAst compileOptList = whatToDeclare.getChild(6);
                while (compileOptList.isAttribute("head","NameCommaList") && compileOptList.isAttribute("number","2")) {
                    compileRecordAs.put(record,compileOptList.getChild(0).getContent());
                    compileOptList = compileOptList.getChild(2);
                }
                compileRecordAs.put(record,compileOptList.getChild(0).getContent());
                /*while (compileOptList!=null) {

                }*/

                System.err.println("Creating record type "+recordName);
                Type geno = f.env.get("prova");
            } else if (whatToDeclare.isAttribute("head","Snippet")) {
                //Getting the record name
                String snippetName = whatToDeclare.getChild(0).getContent();
                String snippet = Strings.unquote(whatToDeclare.getChild(4).getContent());
                f.setSnippet(snippetName,snippet);
                System.err.println("Got snippet '"+snippetName+"'");
            }
        });


        processer.process(d.forest(XPathProcesser.selectSentences()));

        //Compiling what it has to be compiled
        compileRecordAs.asMap().forEach((l,r)->{
            r.forEach(x->System.out.println(f.compile(x,l)));
        });
        //configuration.compileRulesToJavaClasses("test.package");
    }



}
