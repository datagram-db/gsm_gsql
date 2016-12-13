package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.OnStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;

/**
 * Created by vasistas on 11/12/16.
 */
public class Association<K extends Enum> {

    public static <T extends Enum> Association<T> assoc(Terminal<T> token, Token<T> term) {
        return new ATerm<T>(token,term);
    }

    public static <T extends Enum> Association<T> assoc(NonTerminal<T> token, ReducedStack<T> term) {
        return new ANTerm<T>(token,term);
    }

    public static <T extends Enum> Association<T> assoc(GrammarTerm<T> gt, OnStack<T> element) {
        return  (gt.isTerminal() && (element instanceof Token)) ? assoc((Terminal<T>)gt,(Token<T>) element) : assoc((NonTerminal<T>)gt,(ReducedStack<T>) element);
    }

}
