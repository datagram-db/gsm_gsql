package it.giacomobergami.datatypelang.compiler.parser.grammar.classcompiler;

import com.github.javaparser.ast.CompilationUnit;

/**
 * Created by vasistas on 15/12/16.
 */
public class ClassCompiler {

    CompilationUnit cu;

    public ClassCompiler() {
        cu = new CompilationUnit();
        cu.setPackage("it.giacomobergami.datatypelang.compile.parser.classcompiler");
    }

    

}
