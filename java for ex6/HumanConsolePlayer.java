import java.util.List;
import java.util.*;
public class HumanConsolePlayer extends Player {
	public HumanConsolePlayer (char c) {
		super(c);
	}

	public boolean playOneTurn(GamePlay game) {
		char d;
		boolean hasPlayedCorrectly = false;
		List<Point> listOfMoves = game.getPossibleMoves(this);
		if (listOfMoves.isEmpty()) {
			System.out.println("You have no possible moves. press any key to continue.");
			return false; // player has no possible legal moves
		} else {
			int i = 0 , j = 0;
			while (!hasPlayedCorrectly) {
				System.out.println(this.c + ":your move");
				System.out.print("Your possible moves: ");
				for (Point po: listOfMoves) {
					System.out.print("(" + (po.getX() + 1) + "," + (po.getY() + 1) + ") ");
				}
				System.out.println("");
				System.out.print("enter row number, space and column number: ");
	            String action;
	            boolean invalidInp = true;
	            while (invalidInp) {
	            	Scanner dd = new Scanner(System.in);
	            	i = dd.nextInt();
	            	j = dd.nextInt();
	               invalidInp = false;
	            }
	      		// i and j are suppost to be given by user
				for (Point po: listOfMoves) {
					if (i == po.getX() + 1 && j == po.getY() + 1) {
						this.makeMove(i - 1  , j - 1 , game);
						hasPlayedCorrectly = true;
						break;
					}
				}
			}
		}
		return true; // player has played a legal move
	}
}