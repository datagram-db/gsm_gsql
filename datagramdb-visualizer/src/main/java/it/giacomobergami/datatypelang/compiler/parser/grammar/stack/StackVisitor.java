package it.giacomobergami.datatypelang.compiler.parser.grammar.stack;

import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ATerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.Association;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.util.Arrays;
import java.util.function.Consumer;

/**
 * Created by vasistas on 17/12/16.
 */
public class StackVisitor {


    private final Grammar g;


    private static DocumentBuilderFactory docFactory;
    private static DocumentBuilder docBuilder;

    static {
        docFactory = DocumentBuilderFactory.newInstance();
        try {
            docBuilder = docFactory.newDocumentBuilder();
        } catch (ParserConfigurationException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public StackVisitor(Grammar g) {
         this.g = g;
    }

    public void visit(Document doc, Element e, OnStack x) {
        if (x instanceof ANTerm) {
            visit(doc,e,(ANTerm)x);
        } else
            visit(doc, e,(ATerm)x);
    }

    public static String toTagName(Association x) {
        if (x instanceof ANTerm) {
            return "reduced";
        } else
            return "terminal";
    }

    public void visit(Document doc, Element toadd, ATerm term) {
        toadd.setAttribute("type",term.getGrammarMatchedElement().toInput().getType());
        toadd.setTextContent(term.getUnderlyingString());
    }

    public void visit(Document doc,Element toadd, ANTerm term) {
        toadd.setAttribute("head",term.rs.r.header().toString());
        toadd.setAttribute("reduced", Arrays.toString(term.rs.r.tail()));
        toadd.setAttribute("number",""+g.ruleToNumber(term.rs.r));
        toadd.setAttribute("siblings",""+term.rs.associations.size());
        term.rs.associations.forEach(x -> {
            Element toAppend = doc.createElement(toTagName(x));
            visit(doc,toAppend, x);
            toadd.appendChild(toAppend);
        });
    }

    public void visit(Document doc, Element toadd, Association a) {
        if (a instanceof ATerm) {
            visit(doc,toadd,(ATerm)a);
        } else
            visit(doc,toadd,(ANTerm)a);
    }

    public Document visit(ANTerm root) {
        Document doc = docBuilder.newDocument();
        Element rootElement = doc.createElement("program");
        Element reduce = doc.createElement(toTagName(root));
        visit(doc,reduce,root);
        rootElement.appendChild(reduce);
        doc.appendChild(rootElement);
        return doc;
    }

}
