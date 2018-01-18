package sample;

import game.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import java.io.*;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class BoardGameController implements Initializable{
    @FXML
    public Button closeButton;
    @FXML
    private Label player1Score;
    @FXML
    private Label currentTurn;
    @FXML
    private Label endgame;
    @FXML
    private Label player2Score;
    @FXML
    private HBox root;
    private Board board;
    private GameRules rules_ = new BasicGameRules();
    private BoardDisplayer disp_ = new ConsoleDisplay(board);
    private boolean isPlayerOneTurn;
    private BoardController boardController;
    private GamePlay game;

    /**
     *
     * @param url
     * @param resourceBundle
     * this function runs upon initialization, it reads the settings file. and loads the settings of the game.
     * it then creates the board and the board controller and draws it to the board.
     */
    @Override

    public void initialize(URL url, ResourceBundle resourceBundle) {
        int boardSize = 8;
        String p1Color = "#E4F117";
        String p2Color = "#518FF5";
        BufferedReader bufferedReader = null;
        String [] definitions = {""};
        try {
            File file = new File("settings.txt");
            FileInputStream inputStream = new FileInputStream(file);
            bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            String line = bufferedReader.readLine();
            definitions = line.split(",");
            boardSize = Integer.parseInt(definitions[2]);
            p1Color = definitions[0];
            p2Color = definitions[1];
        } catch (FileNotFoundException e) {
            System.out.println("unable to find file");
            //TBD default
        } catch (Exception e) {
            System.out.println("buufered reader failed");
            //TBD default
        }


        board = new Board(boardSize,boardSize);

        this.boardController = new BoardController(board,p1Color,p2Color);
        this.boardController.setPrefHeight(600);
        this.boardController.setPrefWidth(600);
        root.getChildren().add(0,this.boardController);
        this.isPlayerOneTurn = true;
        updateScores();
        this.boardController.draw();
    }

    /**
     * starts a new game, create new players, and add an event handler that contains the main game loop
     * according to player inputs, it calls the play one turn of each player. also updates the score and
     * manage the texts
     */
    public void startGame() {
        Player p1_ = new HumanGUIPlayer('X');
        Player p2_ = new HumanGUIPlayer('O');
        this.game = new GamePlay(this.rules_ , this.board , p1_ , p2_);
        root.addEventHandler(MouseEvent.MOUSE_PRESSED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                if(isPlayerOneTurn){
                    currentTurn.setText("Player1 Turn");
                } else {
                    currentTurn.setText("Player2 Turn");
                }
                //System.out.println(event.getTarget());
                Rectangle tempRect = (Rectangle)event.getTarget();
                int x = (int)(tempRect.getX());
                int y = (int)(tempRect.getY());
                boolean p1HasMoves = true;
                boolean p2HasMoves = true;
                List<Point> listOfMoves;
                if (isPlayerOneTurn) {
                    listOfMoves = rules_.possibleMoves(p1_ , board);
                    if (!listOfMoves.isEmpty()) {
                        if(p1_.playOneTurn(game,x,y)){
                            isPlayerOneTurn = false;
                            boardController.draw();
                        }
                        updateScores();
                        if (!checkPossibleMoves(p1_ , p2_)) {
                            endGame();
                        }
                        return;
                    } else { // player One's turn but has no possible moves
                        if(rules_.possibleMoves(p2_ , board).isEmpty()){
                            endGame();
                        }
                        if(p2_.playOneTurn(game,x,y)){
                            boardController.draw();
                        }
                        updateScores();
                        if (!checkPossibleMoves(p1_ , p2_)) {
                            endGame();
                        }
                        return;
                        // not changing who's turn is it, because it should still be player one's turn
                    }
                }
                // if here, player's two turn
                listOfMoves = rules_.possibleMoves(p2_ , board);
                if (!listOfMoves.isEmpty()) {
                    if(p2_.playOneTurn(game,x,y)){
                        isPlayerOneTurn = true;
                        boardController.draw();
                    }
                    updateScores();
                    if (!checkPossibleMoves(p1_ , p2_)) {
                        endGame();
                    }
                    return;
                } else { // player two's turn but has no possible moves
                    if(rules_.possibleMoves(p1_ , board).isEmpty()){
                        endGame();
                    }
                    if(p1_.playOneTurn(game,x,y)){
                        boardController.draw();
                    }
                    updateScores();
                    if (!checkPossibleMoves(p1_ , p2_)) {
                        endGame();
                    }
                    return;
                    // not changing who's turn is it, because it should still be player two's turn
                }


                //System.out.println(x +", "+y);
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

    public void updateScores(){
        int p1Score = board.getP1Score();
        int p2Score = board.getP2Score();
        player1Score.setText("Player 1: " + p1Score);
        player2Score.setText("Player 2: " + p2Score);
        if(isPlayerOneTurn){
            currentTurn.setText("Player1 Turn");
        } else {
            currentTurn.setText("Player2 Turn");
        }
    }

    public void endGame(){
        int winner = board.getWinner();
        if(winner != 0){
            endgame.setText("Player"+ winner+ " wins!");
        } else {
            endgame.setText("Tie!");
        }
    }

    public boolean checkPossibleMoves(Player p1_, Player p2_){
        return (!rules_.possibleMoves(p1_ , board).isEmpty() || !rules_.possibleMoves(p2_ , board).isEmpty());
    }

}
