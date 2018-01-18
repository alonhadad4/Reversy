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
import javafx.scene.layout.HBox;

import java.net.URL;
import java.util.ResourceBundle;

public class GameController implements Initializable {
    private HBox root;
    @FXML
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) { ;
        GameRules rules_ = new BasicGameRules();
        Board b_ = new Board(8,8);
        BoardDisplayer disp_ = new ConsoleDisplay(b_);

        Player  p1_ = new HumanConsolePlayer('X');
        Player  p2_ = new HumanConsolePlayer('O');
        GamePlay  game = new GamePlay(rules_ , b_ , p1_ , p2_);
        game.playGame();
    }
}