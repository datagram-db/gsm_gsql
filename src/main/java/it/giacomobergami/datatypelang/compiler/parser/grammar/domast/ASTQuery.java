package it.giacomobergami.datatypelang.compiler.parser.grammar.domast;

import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;
import java.util.function.Function;
import java.util.stream.Stream;

/**
 * Created by vasistas on 18/12/16.
 */
public class ASTQuery implements Function<XMLAst,Iterable<XMLAst>> {

    private static XPath xPath = XPathFactory.newInstance().newXPath();
    public ASTQuery(String query) {
        this.query = query;
    }

    public String query;

    protected Iterable<XMLAst> evaluateNodeList(String query, Node e) {
        try {
            return new NodeListStream(e.getOwnerDocument(),(NodeList)xPath.evaluate(query, e, XPathConstants.NODESET));
        } catch (XPathExpressionException e1) {
            throw new RuntimeException(e1);
        }
    }

    @Override
    public Iterable<XMLAst> apply(XMLAst xmlAst) {
        return evaluateNodeList(query,xmlAst.getElement());
    }
}
