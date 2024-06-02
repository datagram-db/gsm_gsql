package it.giacomobergami.datatypelang.compiler.parser.grammar.domast;

import com.sun.istack.internal.NotNull;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;

import javax.xml.soap.Node;
import java.util.Iterator;
import java.util.stream.Stream;

/**
 * Created by vasistas on 18/12/16.
 */
public class NodeListStream implements Iterable<XMLAst> {

    private final NodeList arg;
    private int i, len;
    private Document dom;

    public NodeListStream(Document dom, NodeList arg) {
        this.arg = arg;
        i = 0;
        len = arg == null ? 0 : arg.getLength();
        this.dom = dom;
    }

    @Override
    public Iterator<XMLAst> iterator() {
        return new Iterator<XMLAst>() {
            @Override
            public boolean hasNext() {
                return i<len;
            }

            @Override
            public XMLAst next() {
                return new XMLAst(dom,arg.item(i++));
            }
        };
    }
}
