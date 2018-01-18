package game;
import java.util.List;
import java.util.*;
public class HumanGUIPlayer extends Player {
	/**
	 * calls the super constructor.
	 * @param c , char of player
	 */
	public HumanGUIPlayer (char c) {
		super(c);
	}

	/**
	 * the function checks whether the move (x,y) is a possible move.
	 * is so, it makes it and returns true.
	 * else, i.e. if there are no possible moves or (x,y) is not one, returns false.
	 * @param game , a game play
	 * @param x , x coordinate of move
	 * @param y , y coordinate of move
	 * @return true if play is legal, false otherwise (or if list of moves if empty)
	 */
	public boolean playOneTurn(GamePlay game,int y,int x) {
		List<Point> listOfMoves = game.getPossibleMoves(this);
		int i = x,j = y;
		if (listOfMoves.isEmpty()) {
			System.out.println("You have no possible moves. press any key to continue.");
			return false; // player has no possible legal moves
		} else {
			for (Point po: listOfMoves) {
					if (i == po.getX() && j == po.getY()) {
						this.makeMove(i  , j , game);
						return true;
					}
				}
		}
		return false; // player has played a legal move
	}
}