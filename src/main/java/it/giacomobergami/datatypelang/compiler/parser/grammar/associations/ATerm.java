package it.giacomobergami.datatypelang.compiler.parser.grammar.associations;

import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;

/**
 * Created by vasistas on 11/12/16.
 */
public class ATerm<K extends Enum> extends Association<K> {

    private final Terminal<K> term;
    private final Token<K> token;

    ATerm(Terminal<K> term, Token<K> token) {
        this.term = term;
        this.token = token;
    }
}
