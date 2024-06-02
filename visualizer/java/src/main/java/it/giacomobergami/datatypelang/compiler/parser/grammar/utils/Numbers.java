package it.giacomobergami.datatypelang.compiler.parser.grammar.utils;

import com.ibm.icu.text.RuleBasedNumberFormat;

import java.util.Locale;

/**
 * Created by vasistas on 15/12/16.
 */
public class Numbers {

    private static RuleBasedNumberFormat nf = new RuleBasedNumberFormat(Locale.UK, RuleBasedNumberFormat.SPELLOUT);
    public static String toOrdinal(int i) {
        return nf.format(i, "%spellout-ordinal");
    }

}
