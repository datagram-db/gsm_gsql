package it.giacomobergami.examples.DTL;

import com.google.common.collect.Iterables;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XMLAst;
import it.giacomobergami.datatypelang.compiler.parser.grammar.domast.XPathProcesser;
import it.giacomobergami.datatypelang.language.Compiler;
import it.giacomobergami.datatypelang.language.interpreter.JSONElem;
import it.giacomobergami.examples.DTL.types.Type;
import it.giacomobergami.examples.DTL.types.TypeEnvironment;
import it.giacomobergami.datatypelang.utils.regex.Strings;

/**
 * Created by vasistas on 19/12/16.
 */
public class DTLCompiler extends Compiler {

    public DTLCompiler() {
        super(); //Mandatory
    }

    //Each method has the name of the non-terminal within a tree. Those methods are got by the compiler
    public void Typedef(XMLAst xmlAst) {
        XMLAst array[] = Iterables.toArray(xmlAst.getChildren(),XMLAst.class);
        if (array.length>0) {
            String languageType = array[2].getContent();
            String nativeType = array[4].getContent();
            boolean isMutable = array[1].getChildren().iterator().next().getContent().equals("mutable");
            f.addNativeType(languageType,new JSONElem(nativeType,isMutable,-1));
            //System.err.println("Declaring native type "+nativeType);
        }
    }

    public void Access(XMLAst xmlAst) {
        String arity = Strings.unquote(xmlAst.getChild(4).getContent());
        String data  = Strings.unquote(xmlAst.getChild(6).getContent());
        boolean forAllFixed = (xmlAst.getChild(1).getContent().equals("allfixed"));
        String type = (xmlAst.getChild(1).getContent());
        if (forAllFixed) type = "fixed_"; else type = type+"_";
        setSnippet(type+"arity",arity);
        setSnippet(type+"data",data);
        //System.err.println("Getting other type information for: "+type);
    }

    public void Declare(XMLAst xmlAst) {
        XMLAst whatToDeclare = xmlAst.getChild(1);
        //Record declaration
        if (whatToDeclare.isAttribute("head","Record")) {
            //Getting the record name
            String recordName = whatToDeclare.getChild(1).getContent();
            TypeEnvironment.RecordCreator rec = f.declareRecord(recordName);
            //Getting the record fields
            whatToDeclare.forest(XPathProcesser.setNonTerminalReduction("Field")).forEach(x->{
                rec.addField(x.getChild(0).getContent(),x.getChild(2).getContent());
            });
            rec.close(); //Compiling the record definition
            Type record = f.getCompiledType(recordName);
            XMLAst compileOptList = whatToDeclare.getChild(6);
            while (compileOptList.isAttribute("head","NameCommaList") && compileOptList.isAttribute("number","2")) {
                compileRecordAs(record,compileOptList.getChild(0).getContent());
                compileOptList = compileOptList.getChild(2);
            }
            compileRecordAs(record,compileOptList.getChild(0).getContent());
                /*while (compileOptList!=null) {

                }*/

            //System.err.println("Creating record type "+recordName);
        } else if (whatToDeclare.isAttribute("head","Snippet")) {
            //Getting the record name
            String snippetName = whatToDeclare.getChild(0).getContent();
            String snippet = Strings.unquote(whatToDeclare.getChild(4).getContent());
            f.setSnippet(snippetName,snippet);
            //System.err.println("Got snippet '"+snippetName+"'");
        }
    }



}
