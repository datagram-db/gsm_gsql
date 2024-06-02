package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.OnStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.ReducedStack;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.myToken;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public abstract class Association {

    public abstract GrammarTerm getGrammarMatchedElement();
    public abstract boolean hasSubtree();
    public abstract String getUnderlyingString();
    public abstract Opt<ReducedStack> getSubTree();

    public static  Association assocL(Terminal token, myToken term) {
        return new ATerm(token,term);
    }

    public static Association assocR(NonTerminal token, ReducedStack term) {
        return new ANTerm(token,term);
    }

    public static Association assoc(GrammarTerm gt, OnStack element) {
        return  (gt.isTerminal() && (element instanceof myToken)) ? assocL((Terminal)gt,(myToken) element) : assocR((NonTerminal)gt,(ReducedStack) element);
    }

}
