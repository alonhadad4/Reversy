package sample;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class Main extends Application {

    /**
     * start a new game and loads the menusample fxml tp load the menu controller
     * @param primaryStage
     * @throws Exception
     */
    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("MenuSample.fxml"));
        primaryStage.setTitle("Hello World");
        Scene scene = new Scene(root,400,350);
        //scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
        primaryStage.setTitle("FXML Welcome");


        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}