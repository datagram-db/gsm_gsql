package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

/**
 * Created by vasistas on 11/12/16.
 */
public interface IRule<Type, RuleHeadType extends Type> {
    RuleHeadType header();
    Type[] tail();
}
