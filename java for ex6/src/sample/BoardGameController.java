package sample;

import game.*;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;

import java.net.URL;
import java.util.ResourceBundle;

public class BoardGameController implements Initializable{
    @FXML
    private HBox root;
    private Board board = new Board(8,8);
    private GameRules rules_ = new BasicGameRules();
    private BoardDisplayer disp_ = new ConsoleDisplay(board);
    private boolean isPlayer1turn;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        BoardController boardControl = new BoardController(board);
        boardControl.setPrefHeight(400);
        boardControl.setPrefWidth(400);
        root.getChildren().add(0,boardControl);
        boardControl.draw();
    }
    public void startGame(){
        EventHandler<MouseEvent> eventHandler = new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent e) {
                System.out.println("Hello World");;
            }
        };
        Player p1_ = new HumanConsolePlayer('X');
        Player p2_ = new HumanConsolePlayer('O');
    }



}
