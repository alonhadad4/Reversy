package sample;
import game.Player;
import game.HumanConsolePlayer;
import game.GamePlay;
import game.BasicGameRules;
import game.ConsoleDisplay;
import game.Board;
import game.GameRules;
import game.BoardDisplayer;


import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.*;


import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ColorPicker;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.paint.Color;
import org.omg.PortableInterceptor.INACTIVE;

import java.io.PrintWriter;

public class SettingsController {

    @FXML
    public Button closeButton;
    @FXML
    public ColorPicker Player1Color;
    @FXML
    public ColorPicker Player2Color;
    @FXML
    public ComboBox<String> startingPlayer;
    @FXML
    public ComboBox<String> numberofB;

    @FXML
    protected void quitGame() {
        System.exit(0);
    }

    @FXML
    protected void closeSettings() {

    }
    @FXML
    public void handleCloseButtonAction(ActionEvent event) {
        Stage stage = (Stage) closeButton.getScene().getWindow();
        try {
            PrintWriter writer = new PrintWriter("settings.txt", "UTF-8");
            Color p1Color = Player1Color.getValue();
            Color p2Color = Player2Color.getValue();
            String startingP = startingPlayer.getValue();
            String numberOfBlocks = numberofB.getValue();
            writer.println(p1Color.toString() +","+ p2Color.toString() +","+ startingP +","+ numberOfBlocks);
            writer.close();
            stage.close();
        } catch(Exception e){
            System.out.println(e);
        }
    }
}