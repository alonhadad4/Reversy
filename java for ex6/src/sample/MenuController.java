package sample;
import game.Player;
import game.HumanConsolePlayer;
import game.GamePlay;
import game.BasicGameRules;
import game.ConsoleDisplay;
import game.Board;
import game.GameRules;
import game.BoardDisplayer;



import javafx.fxml.*;


import javafx.fxml.FXML;

public class MenuController {
    /**
     * initializes start option of the menu, that loads BoardGame.fxml to start game.
     */
    @FXML
    protected void startGame() {
        try {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("BoardGame.fxml"));
        javafx.scene.Parent root1 = (javafx.scene.Parent) fxmlLoader.load();
        javafx.stage.Stage stage = new javafx.stage.Stage();
        stage.initModality(javafx.stage.Modality.APPLICATION_MODAL);
        stage.initStyle(javafx.stage.StageStyle.UNDECORATED);
        stage.setTitle("ABC");
        stage.setScene(new javafx.scene.Scene(root1));
        stage.show();
        } catch (Exception e){
            System.out.println("error: " + e);
        }
    }

    /**
     * initializes settings option of the menu, that loads settingsSample.fxml.
     */
    @FXML
    protected void editSettings() {
        try{
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("SettingsSample.fxml"));
            javafx.scene.Parent root1 = (javafx.scene.Parent) fxmlLoader.load();
            javafx.stage.Stage stage = new javafx.stage.Stage();
            stage.initModality(javafx.stage.Modality.APPLICATION_MODAL);
            stage.initStyle(javafx.stage.StageStyle.UNDECORATED);
            stage.setTitle("ABC");
            stage.setScene(new javafx.scene.Scene(root1));
            stage.show();
        } catch (Exception e){
                System.out.println("error: " + e);
            }
    }

    /**
     * executes exit game by closing program.
     */
    @FXML
    protected void quitGame() {
        System.exit(0);
    }
}