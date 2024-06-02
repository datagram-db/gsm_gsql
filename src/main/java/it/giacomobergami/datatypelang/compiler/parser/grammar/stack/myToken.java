package it.giacomobergami.datatypelang.compiler.parser.grammar.stack;

import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.GrammarTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Terminal;

/**
 * Created by vasistas on 11/12/16.
 */
public class myToken implements OnStack, OnInput {

    public final String type;
    public final String data;
    public final Terminal term;
    public final int start,end;

    public String getData() {
        return data;
    }

    public myToken(String type, String data, int start, int end) {
        this.type = type;
        this.data = data;
        this.term = new Terminal(type);
        this.start = start;
        this.end = end;
    }

    @Override
    public String toString() {
        return String.format("(%s %s)", type, data);
    }

    public String input() {
        return data;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public TableColumnEntry asTableColumnValue() {
        return term;
    }

    @Override
    public String getType() {
        return type;
    }

    @Override
    public GrammarTerm asGrammarTerm() {
        return term;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof myToken)) return false;

        myToken token = (myToken) o;

        if (type != null ? !type.equals(token.type) : token.type != null) return false;
        if (data != null ? !data.equals(token.data) : token.data != null) return false;
        return term != null ? term.equals(token.term) : token.term == null;
    }

    @Override
    public int hashCode() {
        int result = type != null ? type.hashCode() : 0;
        result = 31 * result + (data != null ? data.hashCode() : 0);
        result = 31 * result + (term != null ? term.hashCode() : 0);
        return result;
    }

    public int start() {
        return start;
    }

    public int end() {
        return end;
    }
}
