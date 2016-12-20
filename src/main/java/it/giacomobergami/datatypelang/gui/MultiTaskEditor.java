package it.giacomobergami.datatypelang.gui; /**
 * Created by vasistas on 18/12/16.
 */
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.gui.editor.GUIUtils;
import it.giacomobergami.datatypelang.gui.editor.KeywordStyledDocument;
import it.giacomobergami.datatypelang.gui.styles.StyleCollection;
import it.giacomobergami.datatypelang.utils.ForFiles;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.io.File;
import java.util.function.Consumer;

import static javax.swing.JFileChooser.CANCEL_OPTION;
import static javax.swing.JFileChooser.ERROR_OPTION;

public class MultiTaskEditor extends JFrame  {
    private static final long serialVersionUID = 1L;
    KeywordStyledDocument ksd;
    JLabel label;

    public static JMenuItem item(String label, Consumer<ActionEvent> action, KeyStroke stroke) {
        JMenuItem menuItem = new JMenuItem(new AbstractAction(label) {
            public void actionPerformed(ActionEvent e) {
                action.accept(e);
            }
        });
        if (stroke!=null) menuItem.setAccelerator(stroke);
        return menuItem;
    }

    public  JMenuBar bar() {
        JMenuBar menuBar;
        JMenu file, compile;
        JMenuItem menuItem;


//Create the file bar.
        menuBar = new JMenuBar();

//Build the first file.
        file = new JMenu("File");
        file.setMnemonic(KeyEvent.VK_A);
        file.getAccessibleContext().setAccessibleDescription(
                "File oerations");
        file.add(item("Load Input…", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Choose the input file…");
            int n = fc.showOpenDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                ksd.clear();
                setText(ForFiles.toString(f));
            }
        },null));
        menuBar.add(file);

        compile = new JMenu("Compile");
        compile.setMnemonic(KeyEvent.VK_F5);
        file.getAccessibleContext().setAccessibleDescription(
                "Compile operations");
        file.add(item("Load grammar…", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Choose the input file…");
            int n = fc.showOpenDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                ksd.clear();
                setText(ForFiles.toString(f));
            }
        },null));
        file.add(item("Check", x-> {
            JFileChooser fc = new JFileChooser();
            fc.setToolTipText("Choose the input file…");
            int n = fc.showOpenDialog(MultiTaskEditor.this);
            if (n!=CANCEL_OPTION && n!=ERROR_OPTION) {
                File f = fc.getSelectedFile();
                ksd.clear();
                setText(ForFiles.toString(f));
            }
        },null));
        menuBar.add(file);

//a group of JMenuItems
        return menuBar;
        /*JMenuBar mb = new JMenuBar();
        JMenu file = new JMenu("File");
        file.setMnemonic(KeyEvent.VK_A);
        file.getAccessibleContext().setAccessibleDescription(
                "The only file in this program that has file items");
        JMenu bar = createMenu("File", KeyEvent.VK_0);
        mb.add(bar);
        JMenuItem itm = createMenuItem("Load Source…", new MenuAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("PPPP");
            }
        });
        bar.add(itm);
        return mb;*/
    }

    public  JMenu createMenu(String name, int keyEvent, Component... items) {
        JMenu menu = new JMenu(name);
        menu.setMnemonic(keyEvent);
        for (Component item : items) {
            menu.add(item);
        }
        return menu;
    }

    public JMenuItem createMenuItem(String name, MenuAction a) {
        JMenuItem jmi = new JMenuItem(name);
        jmi.setAction(a);
        return jmi;
    }

    public MultiTaskEditor(StyleCollection sc) {
        ksd = new KeywordStyledDocument(sc);
        final JTextPane pane = new JTextPane(ksd);
        pane.setFont(GUIUtils.monospace());
        JScrollPane scrollPane = new JScrollPane(pane);
        label = new JLabel("Welcome do DataType Language.");

        getContentPane().add(scrollPane, BorderLayout.CENTER);
        getContentPane().add(bar(),BorderLayout.NORTH);
        getContentPane().add(label,BorderLayout.SOUTH);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(375, 400);
        //pack();
        setLocationByPlatform(true);
    }

    public void setError(Token t) {
        ksd.setError(t);
    }

    public void clear() {

    }

    public void setText(String text) {
        try {
            ksd.insertString(0,text,null);
        } catch (BadLocationException e) {
            throw new RuntimeException(e);
        }
    }

}