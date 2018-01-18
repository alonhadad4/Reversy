package game;
import java.util.List;
import java.util.*;
public class HumanGUIPlayer extends Player {
	public HumanGUIPlayer (char c) {
		super(c);
	}

	public boolean playOneTurn(GamePlay game) {
		List<Point> listOfMoves = game.getPossibleMoves(this);
		if (listOfMoves.isEmpty()) {
			System.out.println("You have no possible moves. press any key to continue.");
			return false; // player has no possible legal moves
		} else {
			for (Point po: listOfMoves) {
					if (i == po.getX() + 1 && j == po.getY() + 1) {
						this.makeMove(i - 1  , j - 1 , game);
						return true;
					}
				}
		}
		return true; // player has played a legal move
	}
}