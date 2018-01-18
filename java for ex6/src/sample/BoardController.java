package sample;

import game.Board;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class BoardController extends GridPane {
    private Board board;
    private Color p1ColorConv;
    private Color p2ColorConv;

    /**
     * loading the fxml and setting the players colors
     * @param b_ the board
     * @param p1Color p1 color sent from the settings
     * @param p2Color p2 color sent from the settings
     */
    public BoardController (Board b_, String p1Color, String p2Color){
        this.board = b_;
        this.p1ColorConv = Color.web(p1Color);
        this.p2ColorConv = Color.web(p2Color);
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("Board.fxml"));
        try{
            fxmlLoader.load();
        } catch(Exception e){
            throw new RuntimeException(e);
        }
    }

    /**
     * draws the initial board and all players tiles. using javafx
     */
    public void draw(){
        this.getChildren().clear();

        int height = (int)this.getPrefHeight();
        int width = (int)this.getPrefWidth();

        int cellHeight =height / this.board.getLength();
        int cellWidth = width / this.board.getWidth();
        for (int i = 0; i< this.board.getLength(); i++){
            for (int j = 0; j< this.board.getWidth();j++){
                Rectangle rect = new Rectangle(cellWidth,cellHeight);
                rect.setStroke(Color.BLACK);
                rect.setFill(Color.GRAY);
                if(board.getCell(i,j) == 'X'){
                    rect.setFill(p1ColorConv);
                } else if(board.getCell(i,j) == 'O'){
                    rect.setFill(p2ColorConv);
                }
                rect.setX(j);
                rect.setY(i);
            this.add(rect,j,i);
            }
        }
    }
}
