package game;
import java.util.LinkedList;
public class BasicGameRules extends GameRules {

	/**
	 * the function checks if move (i,j) is legal.
	 * i.e. if move transfers at least one cell to the player making it.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 * @return true if the play is legal, false otherwise.
	 */
	public boolean isMoveLegal(char c, int i , int j , Board b) {
		if (this.checkRow(c , i , j , b) || this.checkColumn(c , i , j , b) || this.checkFirstDiagonal(c , i , j , b)
			|| this.checkSecondDiagonal(c , i , j , b)) {
			return true;
		}
		return false;

	}

	/**
	 * the function checks if move (i,j) is legal as for looking at row i.
	 * i.e. if move transfers at least one cell to the player making it.
	 * function starts from the cell and turns to the beginning of the row.
	 * it checks whether there are cells of second player adjacent to (i,j).
	 * if yes, it checks if there is another cell of this player farther on.
	 * if there is, it returns true.
	 * if it hasn't returned, it does the same process towards end of the row.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 * @return true if the play is legal in respect to row i, false otherwise.
	 */
	public boolean checkRow(char c , int i , int j , Board b) {
		boolean isThereSameColor = false;
		boolean isThereOtherColor = false;
		for (int k = j - 1; k >= 0; k --) {
			if (b.getCell(i , k) == ' ' || (b.getCell(i ,k) == c && k == j - 1)) {
				break;
			}
			if (b.getCell(i ,k) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(i ,k) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		isThereSameColor = isThereOtherColor = false;
		for (int k = j + 1; k < b.getWidth(); k ++) {
			if (b.getCell(i , k) == ' ' || (b.getCell(i ,k) == c && k == j + 1)) {
				break;
			}
			if (b.getCell(i ,k) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(i ,k) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		return false;
	}

	/**
	 * the function checks if move (i,j) is legal as for looking at column j.
	 * i.e. if move transfers at least one cell to the player making it.
	 * function starts from the cell and turns to the beginning of the column.
	 * it checks whether there are cells of second player adjacent to (i,j).
	 * if yes, it checks if there is another cell of this player farther on.
	 * if there is, it returns true.
	 * if it hasn't returned, it does the same process towards end of the column.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 * @return true if the play is legal in respect to column j, false otherwise.
	 */

	public boolean checkColumn(char c , int i , int j , Board b) {
		boolean isThereSameColor = false;
		boolean isThereOtherColor = false;
		for (int k = i - 1; k >= 0; k --) {
			if (b.getCell(k , j) == ' ' || (b.getCell(k ,j) == c && k == i - 1)) {
				break;
			}
			if (b.getCell(k ,j) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,j) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		isThereSameColor = isThereOtherColor = false;
		for (int k = i + 1; k < b.getLength(); k ++) {
			if (b.getCell(k , j) == ' ' || (b.getCell(k ,j) == c && k == i + 1)) {
				break;
			}
			if (b.getCell(k ,j) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,j) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		return false;
	}

	/**
	 * the function checks if move (i,j) is legal as for looking at first diagonal.
	 * i.e. if move transfers at least one cell to the player making it.
	 * function starts from the cell and turns to one side of the first diagonal.
	 * it checks whether there are cells of second player adjacent to (i,j).
	 * if yes, it checks if there is another cell of this player farther on.
	 * if there is, it returns true.
	 * if hasn't returned, it does the same process towards other side of diagonal.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 * @return true if the play is legal in respect to column j, false otherwise.
	 */

	public boolean checkFirstDiagonal(char c , int i , int j , Board b) {
		boolean isThereSameColor = false;
		boolean isThereOtherColor = false;
		for (int k = i - 1 , l = j - 1; k >= 0 && l >= 0; k -- , l --) {
			if (b.getCell(k , l) == ' ' || (b.getCell(k ,l) == c && k == i - 1)) {
				break;
			}
			if (b.getCell(k ,l) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,l) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		isThereSameColor = isThereOtherColor = false;
		for (int k = i + 1 , l = j + 1; k < b.getLength() && l < b.getWidth(); k ++ , l ++) {
			if (b.getCell(k , l) == ' ' || (b.getCell(k ,l) == c && k == i + 1)) {
				break;
			}
			if (b.getCell(k ,l) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,l) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		return false;
	}

	/**
	 * the function checks if move (i,j) is legal as for looking at second diagonal.
	 * i.e. if move transfers at least one cell to the player making it.
	 * function starts from the cell and turns to one side of the second diagonal.
	 * it checks whether there are cells of second player adjacent to (i,j).
	 * if yes, it checks if there is another cell of this player farther on.
	 * if there is, it returns true.
	 * if hasn't returned, it does the same process towards other side of diagonal.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 * @return true if the play is legal in respect to column j, false otherwise.
	 */

	public boolean checkSecondDiagonal(char c , int i , int j , Board b) {
		boolean isThereSameColor = false;
		boolean isThereOtherColor = false;
		for (int k = i + 1 , l = j - 1; k < b.getLength() && l >= 0; k ++ , l --) {
			if (b.getCell(k , l) == ' ' || (b.getCell(k ,l) == c && k == i + 1)) {
				break;
			}
			if (b.getCell(k ,l) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,l) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		isThereSameColor = isThereOtherColor = false;
		for (int k = i - 1 , l = j + 1; k >= 0 && l < b.getWidth(); k -- , l ++) {
			if (b.getCell(k , l) == ' ' || (b.getCell(k ,l) == c && k == i - 1)) {
				break;
			}
			if (b.getCell(k ,l) != c) {
				isThereOtherColor = true;
			}
			if (b.getCell(k ,l) == c) {
				isThereSameColor = true;
			}
			if (isThereSameColor && isThereOtherColor) {
				return true;
			}
		}
		return false;
	}

	/**
	 * function puts all cells that are optional legal moves in a linked list.
	 * it puts them as point objects, containing x and y for row and column.
	 * it returns the linked list.
	 * @param p , player
	 * @param b , board
	 * @return linked list of optional moves on board b for player p
	 */
	public LinkedList<Point> possibleMoves(Player p, Board b) {
		char c = p.getChar();
		LinkedList<Point> listOfPoints = new LinkedList<Point>();
		for (int i = 0; i < b.getLength(); i ++) {
			for (int j = 0; j < b.getWidth(); j ++) {
				if (b.getCell(i , j) == ' ' && this.isMoveLegal(c , i , j , b)) {
					Point po = new Point(i , j);
					listOfPoints.add(po);
				}
			}
		}
		return listOfPoints;
	}
}