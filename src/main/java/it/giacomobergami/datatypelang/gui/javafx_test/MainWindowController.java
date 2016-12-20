package it.giacomobergami.datatypelang.gui.javafx_test;

import it.giacomobergami.datatypelang.compiler.ParserLexer;
import it.giacomobergami.datatypelang.compiler.parser.grammar.associations.ANTerm;
import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.gui.editor.GUIUtils;
import it.giacomobergami.datatypelang.gui.editor.KeywordStyledDocument;
import it.giacomobergami.datatypelang.utils.funcs.OptErr;
import javafx.embed.swing.SwingNode;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import javax.swing.*;
import java.awt.*;
import java.io.File;

/**
 * Created by vasistas on 19/12/16.
 */
public class MainWindowController {

    @FXML private BorderPane roota;
    @FXML private SwingNode editor;
    ParserLexer parserLexer = null;
    KeywordStyledDocument ksd;
    JTextPane ksd_father;

    public void grammar(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Open Grammar File");
        File selectedFile = fileChooser.showOpenDialog(roota.getScene().getWindow());
        if (selectedFile != null) {
            parserLexer = new ParserLexer(selectedFile.getAbsoluteFile());
            parserLexer.setStyleCollection(ksd);
        }
    }

    public void input(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Open Interpreted File");
        File selectedFile = fileChooser.showOpenDialog(roota.getScene().getWindow());
        if (selectedFile != null) {
            OptErr<ANTerm, OnInput> result = parserLexer.parseInput(selectedFile);
            if (result.isError()) {
                Toolkit.getDefaultToolkit().beep();
                ksd.setError((Token)result.errorElement());
            } else {
                ksd.readFile(selectedFile);
                // TODO: show the parsed tree
                ANTerm t = result.value();
            }
            parserLexer.setStyleCollection(ksd);
        }
    }

    ///////////
    /**
     * Events that have to be invoked while initializing the Swing objects
     * @param stageAndSetupListeners
     */
    void initializeModel(Stage stageAndSetupListeners) {
        ksd = new KeywordStyledDocument(null);
        SwingUtilities.invokeLater(() -> {
            ksd_father = new JTextPane(ksd);
            ksd_father.setFont(GUIUtils.monospace());
            editor.setContent(ksd_father);;
        });
    }

}
