package it.giacomobergami.datatypelang.compiler.parser.grammar.terms;


/**
 * Created by vasistas on 11/12/16.
 */
public interface GrammarTerm<K extends Enum>  {
    boolean isTerminal();
    boolean isNull();
    String getValue();

}
