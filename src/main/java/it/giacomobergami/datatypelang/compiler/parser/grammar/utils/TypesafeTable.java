package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import it.giacomobergami.datatypelang.compiler.parser.TableCase;
import it.giacomobergami.datatypelang.compiler.parser.grammar.Rule;
import it.giacomobergami.datatypelang.compiler.parser.grammar.TableColumnEntry;
import it.giacomobergami.datatypelang.compiler.parser.grammar.grammar.Grammar;
import it.giacomobergami.datatypelang.representation.Type;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

/**
 * Created by vasistas on 11/12/16.
 */
public class TypesafeTable<K extends Enum> {

    Table<Integer, TableColumnEntry<K>, TableCase> table;

    public TypesafeTable() {
        table = HashBasedTable.create();
    }

    public Opt<TableCase> set(Integer state, TableColumnEntry<K> t_nt_dollar, int shift) {
        TableCase t;
        return (t = table.put(state, t_nt_dollar, new TableCase(shift))) != null ? Opt.of(t) : Opt.err();
    }

    public Opt<TableCase> set(Integer state, TableColumnEntry<K> t_nt_dollar, Rule r) {
        TableCase t;
        return (t = table.put(state, t_nt_dollar, new TableCase(r))) != null ? Opt.of(t) : Opt.err();
    }

    public Opt<TableCase> get(Integer state, TableColumnEntry<K> t_nt_dollar) {
        return  (table.contains(state,t_nt_dollar)) ? Opt.of(table.get(state,t_nt_dollar)) : Opt.err();
    }

}
