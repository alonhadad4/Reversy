package game;
import java.util.ArrayList;
public class Board {
	// private  ArrayList<ArrayList<Character>> b;
	private char [][]b;
	private int length;
	private int width;

	/**
	 * initializes the array member with ' ', and puts starting chars in the center.
	 * @param length of board
	 * @param width of board
	 */
	public Board(int length , int width) {
		this.length = length;
		this.width = width;
		this.b = new char[length][width];
		for (int i = 0; i < length; i ++) {
			for (int j = 0; j < width; j ++) {
				b[i][j] = ' ';
			}
		}
		int halfLength = length / 2;
		int halfWidth = width / 2;
		this.b[halfLength-1][halfWidth-1] = 'O';
		this.b[halfLength][halfWidth] = 'O';
		this.b[halfLength-1][halfWidth] = 'X';
		this.b[halfLength][halfWidth-1] = 'X';
	}

	/**
	 * @param i
	 * @param j
	 * @return char in cell (i,j)
	 */
	public char getCell(int i , int j) {
		//return this.b.get(i).get(j);
		return this.b[i][j];
	}

	/**
	 * sets cell (i,j) with char c
	 * @param i
	 * @param j
	 * @param c , char to put in cell (i,j)
	 */
	public void setCell(int i , int j , char c) {
		//this.b.get(i).set(i , c);
		this.b[i][j] = c;
	}

	/**
	 * @return length of line of board.
	 */
	public int  getLength() {
		return this.length;
	}

	/**
	 * @return width of line of board.
	 */
	public int getWidth() {
		return this.width;
	}

	/**
	 @return true if the board isn't full, false otherwise.
	 */
	public boolean isNotFull() {
		for (int i = 0; i < this.length; i ++) {
			for (int j = 0; j < this.width; j ++) {
				if (this.b[i][j] == ' ') {
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * @return current score of player one
	 */
	public int getP1Score(){
		int score = 0;
		for (int i = 0; i < length; i++){
			for (int j = 0; j < width; j++){
				if(this.b[i][j] == 'X'){
					score++;
				}
			}
		}
		return score;
	}

	/**
	 * @return current score of player two
	 */
	public int getP2Score(){
		int score = 0;
		for (int i = 0; i < length; i++){
			for (int j = 0; j < width; j++){
				if(this.b[i][j] == 'O'){
					score++;
				}
			}
		}
		return score;
	}

	public int getWinner(){
		int scorep1 = this.getP1Score();
		int scorep2 = this.getP2Score();
		if(scorep1 > scorep2){
			return 1;
		} else if(scorep1 < scorep2){
			return 2;
		} else {
			return 0;
		}
	}
}