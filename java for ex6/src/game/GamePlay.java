package game;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.GridPane;

import java.io.IOException;
import java.util.List;
public class GamePlay extends GridPane {
	private GameRules rules;
	private Board b;
	private Player p1;
	private Player p2;
	private BoardDisplayer disp;

	/**
	 * initializes members by parameters given.
	 * @param rul
	 * @param boa
	 * @param playerOne
	 * @param playerTwo
	 */
	public GamePlay(GameRules rul , Board  boa, Player playerOne , Player playerTwo) {
		// TODO Auto-generated constructor stub
		this.rules = rul;
		this.b = boa;
		this.p1 = playerOne;
		this.p2 = playerTwo;
		this.disp = new ConsoleDisplay(this.b);

	}

	/**
	 * @param p , one of the players in this game.
	 * @return list of possible moves for player p
	 */
	public List getPossibleMoves(Player p) {
		return this.rules.possibleMoves(p , this.b);
	}

	/**
	 * runs the game until both players has no possible moves or the board's full.
	 */
	public void playGame() {
		this.disp.displayBoard(this.b);
		boolean possibleMovesForP1 = true;
		boolean possibleMovesForP2 = true;
		while (this.b.isNotFull() && (possibleMovesForP1 || possibleMovesForP2)) {
			possibleMovesForP1 = this.p1.playOneTurn(this, 0, 0);
			this.disp.displayBoard(this.b);
			possibleMovesForP2 = this.p2.playOneTurn(this, 0, 0);
			this.disp.displayBoard(this.b);
		}
		int countPlayerOne = 0;
		int countPlayerTwo = 0;
		char cOne = this.p1.getChar();
		char cTwo = this.p2.getChar();
		for (int i = 0; i < this.b.getLength(); i ++) {
			for (int j = 0; j < this.b.getWidth() ; j ++) {
				if (this.b.getCell(i , j) == cOne) {
					countPlayerOne ++;
				} else if (this.b.getCell(i , j) == cTwo) {
					countPlayerTwo ++;
				}
			}
		}
		if (countPlayerOne > countPlayerTwo) {
			System.out.println("Player one wins!");
		} else if (countPlayerTwo > countPlayerOne) {
			System.out.println("Player two wins!");
		} else {
			System.out.println("It's a tie!");
		}
	}

	/**
	 * function makes a move of player p in (i,j).
	 * @param p , a player in the game
	 * @param i
	 * @param j
	 */
	public void move(Player p , int i , int j) {
		char c = p.getChar();
		this.rules.performMove(c , i , j , this.b);
	}
}