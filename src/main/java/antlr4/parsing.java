package antlr4;

import it.giacomobergami.datatypelang.compiler.ParserLexer;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.myToken;
import it.giacomobergami.datatypelang.gui.MultiTaskEditor;
import it.giacomobergami.datatypelang.gui.styles.StyleCollection;
import it.giacomobergami.datatypelang.gui.styles.myStyle;
import it.giacomobergami.datatypelang.utils.ForFiles;
import org.antlr.v4.runtime.*;
import uk.ncl.giacomobergami.ProgressBarExample;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Supplier;

public class parsing {

    public static StyleCollection styleCollectionParse(File f) {
        Style error = myStyle.CONTEXT.addStyle("__ERROR__", null);
        StyleConstants.setForeground(error, new Color(255,0,0));
        StyleConstants.setBold(error, true);
        StyleConstants.setUnderline(error,true);

        StyleCollection sc = new StyleCollection(error);
        String fileStirng = ForFiles.toString(f);
        String rows[] = fileStirng.split("\n");
        for (String row : rows) {
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
                s.addRegexGroupName(terminalName);
            }
            sc.addStyle(s);
        }
        return sc;
    }

    public static class DescriptiveErrorListener extends BaseErrorListener implements Supplier<List<myToken>> {

        private final String source;
        private final AtomicInteger ai;
        private final MultiTaskEditor mte;
        List<myToken> l;
        public DescriptiveErrorListener(String source, AtomicInteger ai, MultiTaskEditor mte) {
            this.source = source;
            this.ai = ai;
            this.mte = mte;
            l = new ArrayList<>();
        }

        @Override
        public void syntaxError(Recognizer<?, ?> recognizer, Object offendingSymbol,
                                int line, int charPositionInLine,
                                String msg, RecognitionException e)
        {
            Token t = (Token)offendingSymbol;
            myToken x = new myToken("__ERROR__", t.getText(), source.indexOf(t.getText(), ai.get()), /*t.getStopIndex()*/t.getText().length());
            l.add(x);
            mte.setLabel(msg);
        }

        @Override
        public List<myToken> get() {
            return l;
        }
    }


    public static TerminalIterator fromANTLR4(String source, MultiTaskEditor mte) {
        AtomicInteger currentOffset = new AtomicInteger(0);
        datagramqlLexer lexer = new datagramqlLexer(CharStreams.fromString(source));
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        datagramqlParser parser = new datagramqlParser(tokens);
        parser.removeErrorListeners();
        DescriptiveErrorListener y = new DescriptiveErrorListener(source, currentOffset, mte);
        parser.addErrorListener(y);
        datagramqlParser.All_matchesContext ap = parser.all_matches();
        TokenStream is  = parser.getInputStream();
        Vocabulary voc = lexer.getVocabulary();
        List<OnInput> mtl = new ArrayList<>(is.size());
        for (int i = 0; i<is.size(); i++) {
            Token t = is.get(i);
            String tt = voc.getSymbolicName(t.getType());
            if (tt == null) {
                tt = voc.getLiteralName(t.getType());
            }
            currentOffset.set(source.indexOf(t.getText(), currentOffset.get()));
            myToken x = new myToken(tt, t.getText(), currentOffset.get(), /*t.getStopIndex()*/t.getText().length());
            mtl.add(x);
        }
        List<myToken> mtlY = y.get();
        if (mtlY.isEmpty())
            mte.setLabel("");
        mtl.addAll(mtlY);
        TerminalIterator ti = new TerminalIterator(mtl.stream());
        return ti;
    }

    public static void main(String args[]) throws IOException, InterruptedException {

        String source = "p1 = (X)--[l:det||nmod_poss||amod||mark||case||punct||advmod||advcl||dep]->(Y)                   // Graph matching, First pattern\n" +
                "          ↪  set (\uD835\uDF0B (label l) @ X) as (\uD835\uDF09 0 @ Y)                        // Property extension\n" +
                "       del Y                                             // Removing a node\n" +
                "\n" +
                "       (X);                                              // Instance of reference to be returned\n" +
                "\n" +
                "// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" +
                "\n" +
                "p2 = (>> H)<-[∀l:]--(X)                                   // Graph matching, Second pattern\n" +
                "           --[conj] hook\n" +
                "           --[? case]->(K)\n" +
                "           --[? c : cc]->(Z)\n" +
                "     ↪  new h                                             // Creating a new node standing for H\n" +
                "       set (φ orig , h) as H                             // This node will contain all the grouped element (>>)\n" +
                "       set (\uD835\uDF0B conj @ h) as (\uD835\uDF09 0 @ Z)                     // Optional, only if Z exists!\n" +
                "       set (\uD835\uDF09 0 @ h) as (\uD835\uDF09 0 @ H)\n" +
                "       set (φ (if ((label l ) = nmod) over l then\n" +
                "                                       (\uD835\uDF09 0 @ K)\n" +
                "                                      else\n" +
                "                                       (label l)\n" +
                "                                      ), X) as h\n" +
                "       del Z\n" +
                "       del K\n" +
                "       del l\n" +
                "\n" +
                "\n" +
                "       (h);\n" +
                "\n" +
                "p3simple = (V)--[∀n:nsubj]->(>>S)\n" +
                "        --[? mark]->(M)\n" +
                "        --[? aux]->(A)\n" +
                "        --[? neg]->(N)\n" +
                "        --[∀l:dobj||ccomp||nmod]->(>>Z) // Future work: nested join between >>Z and >>Z from the join, when required. This might require to re-do the join semantics\n" +
                "     (Z)--[? case]->(T)\n" +
                "     ↪\n" +
                "        set(φ (SCRIPT \"(^(^(^(^ (^ ( [(\uD835\uDF09 ⦃\\\"A\\\"⦄) 0])  \\\" \\\") ([ (\uD835\uDF09 ⦃\\\"N\\\"⦄)  0])) \\\" \\\") ([ (\uD835\uDF09 ⦃\\\"V\\\"⦄)  0])) \\\" \\\") ([ (\uD835\uDF09 ⦃\\\"T\\\"⦄)  0])\") , S) as Z\n" +
                "         set(\uD835\uDF0B kernel @ S) as (\uD835\uDF09 0 @ S)\n" +
                "       del V\n" +
                "       del T\n" +
                "       del M\n" +
                "       del A\n" +
                "       del N\n" +
                "       (S)";


        ParserLexer pl = new ParserLexer(null);
        pl.initEditor(styleCollectionParse(new File("antlr4/highlight.txt")), source);

    }
}
