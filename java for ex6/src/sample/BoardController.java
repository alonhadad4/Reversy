package sample;

import game.Board;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class BoardController extends GridPane {
    private Board board;

    public BoardController (Board b_){
        this.board = b_;
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("Board.fxml"));
        try{
            fxmlLoader.load();
        } catch(Exception e){
            throw new RuntimeException(e);
        }
    }
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
                    rect.setFill(Color.RED);
                } else if(board.getCell(i,j) == 'O'){
                    rect.setFill(Color.YELLOW);
                }
                rect.setX(j);
                rect.setY(i);
            this.add(rect,j,i);
            }
        }
    }
}
