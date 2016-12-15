package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.OnStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public abstract class Association<K extends Enum> {

    public abstract GrammarTerm<K> getGrammarMatchedElement();
    public abstract boolean hasSubtree();
    public abstract String getUnderlyingString();
    public abstract Opt<ReducedStack<K>> getSubTree();

    public static <T extends Enum> Association<T> assocL(Terminal<T> token, Token term) {
        return new ATerm<T>(token,term);
    }

    public static <T extends Enum> Association<T> assocR(NonTerminal<T> token, ReducedStack<T> term) {
        return new ANTerm<T>(token,term);
    }

    public static <T extends Enum> Association<T> assoc(GrammarTerm<T> gt, OnStack<T> element) {
        return  (gt.isTerminal() && (element instanceof Token)) ? assocL((Terminal<T>)gt,(Token) element) : assocR((NonTerminal<T>)gt,(ReducedStack<T>) element);
    }

}
