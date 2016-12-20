package it.giacomobergami.datatypelang.gui.javafx_test;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

/**
 * Created by vasistas on 19/12/16.
 */
public class MainWindow extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("windowas.fxml"));
        final Pane root = loader.load();
        MainWindowController controller = loader.getController();
        controller.initializeModel(primaryStage); // or what you want to do
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }

}
