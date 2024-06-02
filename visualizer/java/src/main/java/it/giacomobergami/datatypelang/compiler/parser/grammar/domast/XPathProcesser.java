package it.giacomobergami.datatypelang.compiler.parser.grammar.domast;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.function.Consumer;

/**
 * Created by vasistas on 18/12/16.
 */
public class XPathProcesser {
    private final Map<String,Consumer<XMLAst>> mappings;
    public XPathProcesser() {
        mappings = new LinkedHashMap<>();
    }

    public static final String fromCurrent = ".//";

    public static String setNonTerminalReduction(String nonTerminalReduction) {
        return fromCurrent + "reduced[@head=\""+nonTerminalReduction+"\"]";
    }

    public static String fromElementWithAttributeSequence(ElementWithAttribute... seq) {
        StringBuilder sb = new StringBuilder();
        sb.append(fromCurrent);
        for (int i=0; i<seq.length; i++) {
            sb.append(seq[i].toString());
            if (i<seq.length-1) sb.append('/');
        }
        return sb.toString();
    }

    public void setConsumer(String typedef, Consumer<XMLAst> consumer) {
        mappings.put(typedef,consumer);
    }

    public static String selectSentences() {
        return setNonTerminalReduction("Sentence");
    }

    public void process(Iterable<XMLAst> forest) {
        forest.forEach(x->mappings.entrySet().forEach(cp -> x.forest(cp.getKey()).forEach(y -> cp.getValue().accept(y))));
    }

    public static class ElementWithAttribute {

        String tag;
        Map<String,String> property_to_value;

        public ElementWithAttribute(String tag) {
            this.tag = tag;
            property_to_value = new HashMap<>();
        }

        public ElementWithAttribute put(String property, String value) {
            property_to_value.put(property,value);
            return this;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(tag == null || tag.length() == 0 ? "*" : tag);
            if (!property_to_value.isEmpty()) {
                sb.append('[');
                Iterator<Map.Entry<String, String>> it = property_to_value.entrySet().iterator();
                while (it.hasNext()) {
                    Map.Entry<String, String> elem = it.next();
                    sb.append('@').append(elem.getKey()).append("=\"").append(elem.getValue()).append("\"");
                    if (it.hasNext()) sb.append(',');
                }
                sb.append(']');
            }
            return sb.toString();
        }

    }

}
