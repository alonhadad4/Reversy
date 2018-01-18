package sample;

import game.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.io.PrintWriter;
import java.net.URL;
import java.util.ResourceBundle;

public class BoardGameController implements Initializable{
    @FXML
    public Button closeButton;
    @FXML
    private HBox root;
    private Board board = new Board(8,8);
    private GameRules rules_ = new BasicGameRules();
    private BoardDisplayer disp_ = new ConsoleDisplay(board);
    private boolean isPlayerOneTurn;
    private BoardController boardController;
    private GamePlay game;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        this.boardController = new BoardController(board);
        this.boardController.setPrefHeight(400);
        this.boardController.setPrefWidth(400);
        root.getChildren().add(0,this.boardController);
        this.boardController.draw();
    }
    public void startGame() {
        Player p1_ = new HumanGUIPlayer('X');
        Player p2_ = new HumanGUIPlayer('O');
        this.isPlayerOneTurn = true;
        this.game = new GamePlay(this.rules_ , this.board , p1_ , p2_);
        root.addEventHandler(MouseEvent.MOUSE_PRESSED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                //System.out.println(event.getTarget());
                Rectangle tempRect = (Rectangle)event.getTarget();
                int x = (int)(tempRect.getX());
                int y = (int)(tempRect.getY());
                List<Point> listOfMoves;
                if (isPlayerOneTurn) {
                    listOfMoves = this.rules_.possibleMoves(p1_ , this.board);
                    if (!listOfMoves.isEmpty()) {
                        p1_.playOneTurn(game);
                        this.isPlayerOneTurn = false;
                        return;
                    } else { // player One's turn but has no possible moves
                        p2_.playOneTurn(game);
                        return;
                        // not changing who's turn is it, because it should still be player one's turn
                    }
                }
                // if here, player's two turn
                listOfMoves = this.rules_.possibleMoves(p2_ , this.board);
                if (!listOfMoves.isEmpty()) {
                    p2_.playOneTurn(game);
                    this.isPlayerOneTurn = true;
                    return;
                } else { // player two's turn but has no possible moves
                    p1_.playOneTurn(game);
                    return;
                    // not changing who's turn is it, because it should still be player two's turn
                }
                if (this.board.isFull()) {
                    // alon, add here end of game process.
                }
                System.out.println(x +", "+y);
            }
        });
    }
    public void handleCloseButtonAction(ActionEvent event) {
        Stage stage = (Stage) closeButton.getScene().getWindow();
        try {
            stage.close();
        } catch(Exception e){
            System.out.println(e);
        }
    }



}
