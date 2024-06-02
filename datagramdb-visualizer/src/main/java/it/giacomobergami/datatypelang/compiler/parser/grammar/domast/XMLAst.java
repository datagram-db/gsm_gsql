package it.giacomobergami.datatypelang.compiler.parser.grammar.domast;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.ls.DOMImplementationLS;
import org.w3c.dom.ls.LSSerializer;

import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.StringWriter;
import java.util.Iterator;

/**
 * Created by vasistas on 18/12/16.
 */
public class XMLAst {
    Document dom;
    Node node;

    public XMLAst(Document visit) {
        dom = visit;
        node = dom.getDocumentElement();
    }

    protected XMLAst(Document visit, Node elem) {
        dom = visit;
        node = elem;
    }

    public Iterable<XMLAst> getChildren() {
        return () -> new Iterator<XMLAst>() {
            NodeList nl = node.getChildNodes();
            private int i=0;
            private int len = nl.getLength();

            @Override
            public boolean hasNext() {
                return i<len;
            }

            @Override
            public XMLAst next() {
                return new XMLAst(dom,nl.item(i++));
            }
        };
    }


    public Node getElement() {
        return node;
    }

    public String getContent() {
        return node.getTextContent();
    }

    public Iterable<XMLAst> forest(String s) {
        return new ASTQuery(s).apply(this);
    }

    @Override
    public String toString() {
        Transformer transformer = null;
        try {
            transformer = TransformerFactory.newInstance().newTransformer();
            transformer.setOutputProperty(OutputKeys.INDENT, "yes");
            transformer.setOutputProperty("{http://xml.apache.org/xslt}indent-amount", "2");
            StreamResult result = new StreamResult(new StringWriter());
            DOMSource source = new DOMSource(dom);
            transformer.transform(source, result);
            return result.getWriter().toString();
        } catch (TransformerException e) {
            throw new RuntimeException(e);
        }

    }

    public XMLAst getChild(int i) {
        return new XMLAst(dom,node.getChildNodes().item(i));
    }

    public boolean isAttribute(String head, String record) {
        return node.getAttributes().getNamedItem(head).getNodeValue().equals(record);
    }
}
