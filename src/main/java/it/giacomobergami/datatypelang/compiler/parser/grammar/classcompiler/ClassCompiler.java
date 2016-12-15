package it.giacomobergami.datatypelang.compiler.parser.grammar.classcompiler;

import com.github.javaparser.ast.CompilationUnit;
import com.github.javaparser.ast.body.ClassOrInterfaceDeclaration;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.NonTerminal;

import java.util.Collection;

/**
 * Created by vasistas on 15/12/16.
 */
public class ClassCompiler {

    CompilationUnit cu;

    public ClassCompiler() {
        cu = new CompilationUnit();
        cu.setPackage("it.giacomobergami.datatypelang.compile.parser.classcompiler");
    }


    public void createClassForNonTerminal(NonTerminal nt, Collection<Rule> collOfRules) {
        ClassOrInterfaceDeclaration type = cu.addClass(nt.getValue());
        for (Rule rule : collOfRules) {

        }
    }



}
