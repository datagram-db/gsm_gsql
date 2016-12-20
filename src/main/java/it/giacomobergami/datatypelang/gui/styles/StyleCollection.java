package it.giacomobergami.datatypelang.gui.styles;

import it.giacomobergami.datatypelang.compiler.lexer.Lexer;
import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
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

    public TerminalIterator tokenize(String s) {
        return lex.lex(s);
    }

    public Opt<myStyle> onStyle(Token t) {
        return mm.containsKey(t.getType()) ? Opt.of(mm.get(t.getType())) : Opt.err();
    }

}
