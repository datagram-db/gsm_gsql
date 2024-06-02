package it.giacomobergami.datatypelang.gui.styles;

import antlr4.parsing;
import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.myToken;
import it.giacomobergami.datatypelang.gui.MultiTaskEditor;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import javax.swing.text.Style;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by vasistas on 18/12/16.
 */
public class StyleCollection {

    Lexer lex;
    List<myStyle> styles;
    Map<String,myStyle> mm;
    public Style error;


    public StyleCollection(Style error) {
        mm = new HashMap<>();
        lex = null;
        styles = new ArrayList<>();
        this.error = error;
    }

    public void setLexer(Lexer lexer) {
        this.lex = lexer;
    }

    public void addStyle(myStyle s) {
        styles.add(s);
        s.toRegexGroups().forEach(x->mm.put(x,s));
    }

    public TerminalIterator antlrTokenize(String s, MultiTaskEditor mte) {
        return parsing.fromANTLR4(s, mte);
    }

    public TerminalIterator tokenize(String s) {
        return lex.lex(s);
    }

    public Opt<Style> onStyle(myToken t) {
        if (mm.containsKey(t.getType()))
            return Opt.of(mm.get(t.getType()).asStyle());
        else if (mm.containsKey(t.getData()))
            return Opt.of(mm.get(t.getData()).asStyle());
        else if (t.getType().equals("__ERROR__"))
            return Opt.of(error);
        else
            return Opt.err();

    }

}
