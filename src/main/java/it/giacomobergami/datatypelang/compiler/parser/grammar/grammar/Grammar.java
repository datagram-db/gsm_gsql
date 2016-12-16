package it.giacomobergami.datatypelang.compiler.parser.grammar.grammar;

import com.github.javaparser.Token;
import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.Modifier;
import com.github.javaparser.ast.NodeList;
import com.github.javaparser.ast.body.ClassOrInterfaceDeclaration;
import com.github.javaparser.ast.body.ConstructorDeclaration;
import com.github.javaparser.ast.body.Parameter;
import com.github.javaparser.ast.body.TypeDeclaration;
import com.github.javaparser.ast.type.ClassOrInterfaceType;
import com.github.javaparser.ast.type.Type;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.Iterables;
import com.google.common.collect.Multimap;
import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.Item;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.items.ItemWithLookahead;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;
import it.giacomobergami.datatypelang.compiler.parser.grammar.utils.Numbers;
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.utils.data.Pair;
import it.giacomobergami.datatypelang.utils.funcs.Opt;
import org.apache.commons.lang3.ArrayUtils;

import java.lang.reflect.Array;
import java.nio.file.Path;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * Created by vasistas on 12/12/16.
 */
public class Grammar {

    private final NonTerminal starter;
    private final Multimap<NonTerminal,Rule> map;
    public final Rule[] rules;
    private Set<Terminal> terminals;
    private Set<NonTerminal> nullables;

    public void compileRulesToJavaClasses(String packageName) {
        CompilationUnit cu = new CompilationUnit();
        cu.setPackage(packageName);
        HashMap<NonTerminal,ClassOrInterfaceDeclaration> classes = new HashMap<>();
        HashMap<NonTerminal,Integer> classToId = new HashMap<>();
        int counter = 0;
        cu.addClass("ReducedStack");

        //Creating the types
        for (NonTerminal k : map.keySet()) {
            ClassOrInterfaceDeclaration clazz = cu.addClass(k.getValue());
            NodeList<ClassOrInterfaceType> extendsList = new NodeList<>();
            extendsList.add(0,new ClassOrInterfaceType("it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack"));
            clazz.setExtends(extendsList);
            classes.put(k,clazz);
            classToId.put(k,counter++);
        }
        Set<String> terminalNames = getAllTerminals().stream().map(
                Terminal::getValue
        ).collect(Collectors.toSet());
        for (NonTerminal k : map.keySet()) {

            for (Rule r : map.get(k)) {
                ConstructorDeclaration constructor = classes.get(k).addConstructor(Modifier.PUBLIC);
                GrammarTerm[] tail = r.tail();
                for (int i = 0, tailLength = tail.length; i < tailLength; i++) {
                    GrammarTerm x = tail[i];
                    if (terminalNames.contains(x.getValue())) {
                        constructor.addAndGetParameter(Token.class,Numbers.toOrdinal(i+1)+"_"+x.getValue());
                    } else
                        constructor.addAndGetParameter(x.getValue(), Numbers.toOrdinal(i+1));
                }
            }
            System.err.println(classes.get(k).toString());
        }



    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Rule x : rules) sb.append(x.toString()).append(",");
        return sb.toString();
    }

    private Multimap<ItemWithLookahead,GrammarTerm> mapFromLookahead(Multimap<ItemWithLookahead,GrammarTerm> stateElementsMap,ItemWithLookahead axB) {
        if (axB != null) {
            stateElementsMap.putAll(axB,axB.getIterableLookaheadSymbols());
            // A -> αxβ
            Opt<GrammarTerm> x = axB.elementAtCurrentPosition();

            // The first element has been already visited, so I just return the actual state.
            // MEMO: In this case I should generate  a reduce operation
            // Otherwise, I have to check the elements stored within the element
            if (axB.getItemPos() != axB.getCore().length && !x.isError()) {
                GrammarTerm t = x.value();

                // If, otherwise, it is a terminal,
                // I only have a shift operation. I do not have to visit the other elements
                //return stateElementsMap;
                if (!t.isTerminal()) {

                    NonTerminal nt = (NonTerminal)t;

                    GrammarTerm[] B = axB.getElementsNextToCore();

                    for (Rule y : map.get(nt)) {
                        ItemWithLookahead item = y.asLookaheadItem(this);
                        for (GrammarTerm z : B)
                            stateElementsMap.putAll(item,first(ArrayUtils.add(B,z)));

                        //Check recursively if the current expanded item starts with a NT, and hence it has to be expanded
                        Opt<GrammarTerm> nt2 = item.elementAtCurrentPosition();
                        if (nt2.ifte(z->!z.isTerminal(),()->false)) {
                            if (!stateElementsMap.get(item).containsAll(item.getListLookaheadSymbols())) {
                                mapFromLookahead(stateElementsMap,item);
                            }
                        }
                    }

                }



            }

        }
        return stateElementsMap;
    }

    /**
     * Generates an LR(1) state from the state definition
     * @param No
     * @param first
     * @return
     */
    public State stateFromLookahead(int No, ItemWithLookahead first) {
        return new State(No,mapFromLookahead(HashMultimap.create(),first).asMap().entrySet().stream().map(x->x.getKey().setLookaheadSymbols(x.getValue())).collect(Collectors.toSet()));
    }

    public State stateFromLookaheads(int No, Collection<ItemWithLookahead> first) {
        Multimap<ItemWithLookahead,GrammarTerm> stateElementsMap = HashMultimap.create();
        first.forEach(x->mapFromLookahead(stateElementsMap,x));
        return new State(No,stateElementsMap.asMap().entrySet().stream().map(x->x.getKey().setLookaheadSymbols(x.getValue())).collect(Collectors.toSet()));
    }


    public Grammar(NonTerminal starter,Rule... rules) {
        this.starter = starter;
        map = HashMultimap.create();
        for (Rule x : rules) map.put(x.header(),x);
        this.rules = rules;
        terminals = null;
        nullables = null;
    }



    private Grammar(NonTerminal starter,Collection<Rule> rules) {
        this.starter = starter;
        map = HashMultimap.create();
        this.rules = Iterables.toArray(rules,Rule.class);
        rules.forEach(x -> map.put(x.header(), x));
        terminals = null;
        nullables = null;
    }

    public static Pair<Grammar,Lexer> parseGrammarFromFile(Path file) {
        LinkedHashMap<String,String> terminalWithRegex = new LinkedHashMap<>();
        HashMap<String,String> convertedToName = new HashMap<>();
        String fileStirng = ForFiles.toString(file.toFile());
        String rows[] = fileStirng.split("\n");
        ArrayList<Rule> ruleList = new ArrayList<>();
        NonTerminal firstRule = null;
        Predicate<OnInput> pred = OnInput::nonEmpty;
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
        return new Pair<>(new Grammar(firstRule,ruleList.toArray(new Rule[ruleList.size()])), new Lexer(terminalWithRegex));
    }

    public static <K extends Enum> Opt<Grammar> generateGrammar(NonTerminal starter, Rule... rules) {
        boolean hasStarter = false;
        for (Rule x : rules) if (starter.equals(x.header())) {
            hasStarter = true;
            break;
        }
        return hasStarter ? Opt.of(new Grammar(starter, rules)) : Opt.err();
    }

    public static <K extends Enum> Opt<Grammar> generateGrammar(NonTerminal starter, Collection<Rule> rules) {
        boolean hasStarter = false;
        for (Rule x : rules) if (starter.equals(x.header())) {
            hasStarter = true;
            break;
        }
        return hasStarter ? Opt.of(new Grammar(starter, rules)) : Opt.err();
    }

    /**
     * Collects all the headers from the rules
     * @return
     */
    public Set<NonTerminal> getAllNonTerminals() {
        return map.keySet();
    }

    /**
     * Collects all the terminals from all the rules
     * @return
     */
    public Set<Terminal> getAllTerminals() {
        if (terminals == null)
            terminals = map.values().stream()
                    .map(x-> Arrays.stream(x.tail()))
                    .flatMap(x->x)
                    .filter(GrammarTerm::isTerminal)
                    .map(x->((Terminal)x)).collect(Collectors.toSet());
        return terminals;
    }

    public Set<NonTerminal> nullables() {
        if (nullables==null) {
            nullables = new HashSet<>();
            Arrays.stream(rules)
                    .filter(x -> x.tail().length == 0)
                    .map(Rule::header)
                    .forEach(nullables::add);
            for (Rule x : rules) {
                boolean toadd = true;
                boolean thereIsNonTerminal = false;
                for (GrammarTerm y : x.tail()) {
                    if (y instanceof NonTerminal) {
                        thereIsNonTerminal = true;
                        if (!nullables.contains(y)) {
                            toadd = false;
                            break;
                        }
                    }
                }
                if (toadd && thereIsNonTerminal)
                    nullables.add(x.header());
            }
        }
        return nullables;
    }

    private Set<TableColumnEntry> first(GrammarTerm x) {
        Set<TableColumnEntry> hs = new HashSet<>();
        if (x.isTerminal() && (!x.isNull())) {
            hs.add((TableColumnEntry)x);
            return hs;
        } else {
            nullables();
            map.get((NonTerminal) x).forEach(y -> {
                StringBuilder sb = new StringBuilder();
                //System.out.println("@@"+y);
                GrammarTerm[] tl = y.tail();
                if (!tl[0].equals(x)) //Add the element, but do not get trapped in a loop. I'm already visiting x
                    hs.addAll(first(tl[0]));
                for (int i = 1; i < tl.length; i++) {
                    boolean allNullable = true;
                    for (int j = 0; j < i; j++) {
                        if (!nullables.contains(tl[j])) {
                            allNullable = false;
                            break;
                        }
                    }
                    if (allNullable) {
                        hs.addAll(first(tl[i]));
                    }

                }
            });
            if (nullables.contains(x)) {
                hs.add(new Varepsilon<>());
            }
            return hs;
        }
    }

    public Set<TableColumnEntry> first(Rule r) {
        return first(r.tail());
    }

    public Set<TableColumnEntry> first(NonTerminal nt) {
        return map.get(nt).stream().map(x->first(x.tail()).stream()).flatMap(x->x).collect(Collectors.toSet());
    }

    private Set<TableColumnEntry> first(GrammarTerm... x) {
        return first(0,x);
    }

    public Set<TableColumnEntry> first(List<GrammarTerm> x) {
        return first(0,x);
    }

    public Set<TableColumnEntry> first(Item lh) {
        return first((lh.pos),lh.elems);
    }

    private Set<TableColumnEntry> first(int pos, List<GrammarTerm> x) {
        Set<TableColumnEntry> hs = new HashSet<>();
        if (x.size()==0||pos>=x.size()) {
            hs.add(new Varepsilon<>());
            return hs;
        } else {
            nullables();
            GrammarTerm fst = x.get(pos);
            if (nullables.contains(fst)) {
                hs.addAll(first(x));
                hs.remove(new Varepsilon());
                hs.addAll(first(pos+1,x));
                return hs;
            } else {
                return first(fst);
            }
        }
    }

    private Set<TableColumnEntry> first(int pos, GrammarTerm... x) {
        Set<TableColumnEntry> hs = new HashSet<>();
        if (x.length==0||pos>=x.length) {
            hs.add(new Varepsilon<>());
            return hs;
        } else {
            nullables();
            GrammarTerm fst = x[pos];
            if (nullables.contains(fst)) {
                hs.addAll(first(fst));
                hs.remove(new Varepsilon());
                hs.addAll(first(pos+1,x));
                return hs;
            } else {
                return first(fst);
            }
        }
    }


    public Set<TableColumnEntry> follow(NonTerminal x) {
        Set<TableColumnEntry> hs = new HashSet<>();
        if (x.equals(this.starter)) {
            hs.add(new Varepsilon());
        }
        for (Rule y : rules) {
            Opt<Item> opt = Item.generate(y, x);
            if (!opt.isError()) {
                Item lh = opt.value();
                do {
                    Set<TableColumnEntry> betaFirst = first(lh);
                    hs.addAll(betaFirst);
                    hs.remove(new Varepsilon());
                    if (lh.pos==lh.elems.length || betaFirst.contains(new Varepsilon())) {
                        hs.addAll(follow(y.header()));
                    }
                } while (lh!=null);
            }
        }
        return hs;
    }

    public ItemWithLookahead startItem() {
        return ItemWithLookahead.generate(this,map.get(this.starter).stream().findFirst().get()).value();
    }
    public Stream<GrammarTerm> firstsToLookaheadStream(Collection<TableColumnEntry> coll) {
        return coll.stream().filter(TableColumnEntry::isInput).map(TableColumnEntry::asGrammarTerm);
    }

//////
    private OnInput[] firstsToLookahead(Collection<TableColumnEntry> coll) {
        return coll.stream().filter(TableColumnEntry::isInput).map(TableColumnEntry::asOnInput).toArray(value -> (OnInput[])Array.newInstance(OnInput.class, value));
    }



    public NonTerminal getStarter() {
        return starter;
    }
}
