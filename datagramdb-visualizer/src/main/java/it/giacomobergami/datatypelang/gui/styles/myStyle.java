package it.giacomobergami.datatypelang.gui.styles;

import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;
import java.awt.*;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by vasistas on 18/12/16.
 */
public class myStyle {

    private final Color hue;
    private final String stylename;
    private Set<String> regexGroupName;
    public static final StyleContext CONTEXT = new StyleContext();

    public myStyle(Color hue, String stylename) {
        this.hue = hue;
        this.stylename = stylename;
        this.regexGroupName = new HashSet<>();
    }

    public myStyle addRegexGroupName(String regex) {
        this.regexGroupName.add(regex);
        return this;
    }

    public static Style getDefault() {
        return CONTEXT.getStyle(StyleContext.DEFAULT_STYLE);
    }

    public Style asStyle() {
        Style cwStyle = CONTEXT.addStyle(stylename, null);
        StyleConstants.setForeground(cwStyle, hue);
        StyleConstants.setBold(cwStyle, true);
        return cwStyle;
    }

    public Iterable<String> toRegexGroups() {
        return regexGroupName;
    }


}
