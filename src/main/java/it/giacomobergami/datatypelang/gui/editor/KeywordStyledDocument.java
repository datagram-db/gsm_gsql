package it.giacomobergami.datatypelang.gui.editor;

import it.giacomobergami.datatypelang.compiler.lexer.TerminalIterator;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.gui.styles.StyleCollection;
import it.giacomobergami.datatypelang.gui.styles.myStyle;
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.utils.funcs.Opt;

import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultStyledDocument;
import javax.swing.text.Style;
import java.io.File;

/**
 * http://stackoverflow.com/a/30040486/1376095
 */

public class KeywordStyledDocument extends DefaultStyledDocument  {
    private static final long serialVersionUID = 1L;
    private Style _defaultStyle;
    private StyleCollection styles;

    public KeywordStyledDocument(StyleCollection sc) {
        _defaultStyle = myStyle.getDefault();
        styles = sc;
    }

    public void updateStyleCollection(StyleCollection sc) {
        this.styles = sc;
    }

    public void insertString (int offset, String str, AttributeSet a) throws BadLocationException {
        super.insertString(offset, str, a);
        refreshDocument();
    }

    public boolean readFile(File f) {
        try {
            remove(0,getLength());
            String fs = ForFiles.toString(f);
            insertString(0,fs,null);
            return true;
        } catch (BadLocationException e) {
            e.printStackTrace();
            return false;
        }
    }

    public void clear() {
        try {
            remove(0,getLength());
        } catch (BadLocationException e) {
            throw new RuntimeException(e);
        }
    }

    public void remove (int offs, int len) throws BadLocationException {
        super.remove(offs, len);
        refreshDocument();
    }

    private synchronized void refreshDocument() throws BadLocationException {
        String text = getText(0, getLength());

        setCharacterAttributes(0, text.length(), _defaultStyle, true);
        TerminalIterator l = styles.tokenize(text);
        while (l.hasNext()) {
            OnInput oi = l.next();
            if (oi.nonEmpty()) {
                Token t = (Token)oi;
                Opt<myStyle> st = styles.onStyle(t);
                if (!st.isError()) {
                    setCharacterAttributes(t.start(), t.end()-t.start()+1, styles.onStyle(t).value().asStyle(), true);
                }
            }
        }
    }

    public void setError(Token t) {
        setCharacterAttributes(t.start(), t.end()-t.start()+1,styles.error,true);
    }


}
