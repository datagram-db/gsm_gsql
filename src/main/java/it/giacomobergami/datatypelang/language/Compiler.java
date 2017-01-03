package it.giacomobergami.datatypelang.language;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.Multimap;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XMLAst;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XPathProcesser;
import it.giacomobergami.examples.datatypelang.Filler;
import it.giacomobergami.examples.datatypelang.types.Type;

import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;

/**
 * Created by vasistas on 19/12/16.
 */
public class Compiler {

    public Filler f;
    Multimap<Type,String> compileRecordAs;

    public Compiler() {
        super();
        f= new Filler();
        compileRecordAs = HashMultimap.create();
    }

    public void setSnippet(String s, String arity) {
        f.setSnippet(s,arity);
    }

    public void compileRecordAs(Type record, String content) {
        compileRecordAs.put(record,content);
    }

    public void compile(XMLAst abstractTree) {
        XPathProcesser processer = new XPathProcesser();
        Arrays.stream(getClass().getDeclaredMethods())
                .filter(x->
                        x.getGenericParameterTypes().length==1 && x.getGenericParameterTypes()[0].equals(XMLAst.class))
                .forEach(x->{
                    processer.setConsumer(XPathProcesser.setNonTerminalReduction(x.getName()), y -> {
                        try {
                            x.invoke(this, y);
                        } catch (IllegalAccessException | InvocationTargetException e) {
                            e.printStackTrace();
                            System.exit(1);
                        }
                    });
                });
        processer.process(abstractTree.forest(XPathProcesser.selectSentences()));

        //Compiling what it has to be compiled
        compileRecordAs.asMap().forEach((l,r)->{
            r.forEach(x->System.out.println(f.compile(x,l)));
        });
    }

}
