package game;
import java.util.List;
public abstract class GameRules {
	/**
	 * @param c
	 * @param i
	 * @param j
	 * @param b
	 * @return
	 */
	public abstract boolean isMoveLegal(char c , int i , int j, Board b);
	public abstract List possibleMoves(Player p , Board b);

	/**
	 * function calls making the move on row, column and diagonals.
	 * later, it sets the cell itself to the char given.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 */
	public void performMove(char c , int i , int j , Board b) {
		this.performOnRow(c, i , j , b);
		this.performOnColumn(c, i , j , b);
		this.performOnFirstDiagonal(c, i , j , b);
		this.performOnSecondDiagonal(c, i , j , b);
		b.setCell(i , j , c);
	}

	/**
	 * the function checks if a move of (i,j) changes row i.
	 * if so, it changes the row according to the rules.
	 * function starts from the cell and turns to the end of the row.
	 * it checks whether cells has to be changed there because of the move.
	 * if yes, it changes them and returns.
	 * if not, it checks the beginning of the row, again: yes-> change, return.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 */
	public void performOnRow(char c ,int i ,int j ,Board b) {
		char d;
		char op = 'X';
		if (c == 'X') {
			op = 'O';
		}
		int index = -1;
		boolean atLeastOneDifferent = false;
		for (int k = j + 1; k < b.getWidth(); k ++) {
			d = b.getCell(i , k);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int l = j + 1; l <= index; l ++) {
						b.setCell(i , l , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
		index = b.getLength();
		atLeastOneDifferent = false;
		for (int k = j - 1; k >= 0; k --) {
			d = b.getCell(i , k);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int l = j - 1; l >= index; l --) {
						b.setCell(i , l , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
	}

	/**
	 * the function checks if a move of (i,j) changes column j.
	 * if so, it changes the column according to the rules.
	 * function starts from the cell and turns to the end of the column.
	 * it checks whether cells has to be changed there because of the move.
	 * if yes, it changes them and returns.
	 * if not, it checks the beginning of the column, again: yes-> change, return.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 */
	public void performOnColumn(char c ,int i ,int j ,Board b) {
		char d;
		char op = 'X';
		if (c == 'X') {
			op = 'O';
		}
		int index = -1;
		boolean atLeastOneDifferent = false;
		for (int k = i + 1; k < b.getLength(); k ++) {
			d = b.getCell(k , j);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int l = i + 1; l <= index; l ++) {
						b.setCell(l , j , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
		index = b.getLength();
		atLeastOneDifferent = false;
		for (int k = i - 1; k >= 0; k --) {
			d = b.getCell(k , j);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int l = i - 1; l >= index; l --) {
						b.setCell(l , j , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
	}

	/**
	 * the function checks if a move of (i,j) changes first diagonal.
	 * if so, it changes the diagonal according to the rules.
	 * function starts from the cell and turns to one side of first diagonal of it.
	 * it checks whether cells has to be changed there because of the move.
	 * if yes, it changes them and returns.
	 * if not, it checks the other side of diagonal, again: yes-> change, return.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 */
	public void performOnFirstDiagonal(char c ,int i ,int j ,Board b) {
		char d;
		char op = 'X';
		if (c == 'X') {
			op = 'O';
		}
		int index = -1;
		boolean atLeastOneDifferent = false;
		for (int k = i + 1 , l = j + 1; k < b.getLength() && l < b.getWidth(); k ++ , l ++) {
			d = b.getCell(k , l);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int m = i + 1 , n = j + 1; m <= index; m ++ , n ++) {
						b.setCell(m , n , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
		index = b.getLength();
		atLeastOneDifferent = false;
		for (int k = i - 1 , l = j - 1; k >= 0 && l >= 0; k -- , l --) {
			d = b.getCell(k , l);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int m = i - 1 , n = j - 1; m >= index; m -- , n --) {
						b.setCell(m , n , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
	}

	/**
	 * the function checks if a move of (i,j) changes second diagonal.
	 * if so, it changes the diagonal according to the rules.
	 * function starts from the cell and turns to one side of second diagonal of it.
	 * it checks whether cells has to be changed there because of the move.
	 * if yes, it changes them and returns.
	 * if not, it checks the other side of diagonal, again: yes-> change, return.
	 * @param c , char to put in (i,j)
	 * @param i
	 * @param j
	 * @param b , board
	 */
	public void performOnSecondDiagonal(char c ,int i ,int j ,Board b) {
		char d;
		char op = 'X';
		if (c == 'X') {
			op = 'O';
		}
		int index = -1;
		boolean atLeastOneDifferent = false;
		for (int k = i + 1 , l = j - 1; k < b.getLength() && l >= 0; k ++ , l --) {
			d = b.getCell(k , l);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int m = i + 1 , n = j - 1; m <= index; m ++ , n --) {
						b.setCell(m , n , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}

		index = b.getLength();
		atLeastOneDifferent = false;
		for (int k = i - 1 , l = j + 1; k >= 0 && l < b.getWidth(); k -- , l ++) {
			d = b.getCell(k , l);
			if (d != c && d != op) {
				break;
			}
			if (d == c) {
				if (atLeastOneDifferent == false) {
					break;
				} else {
					for (int m = i - 1 , n = j + 1; m >= index; m -- , n ++) {
						b.setCell(m , n , c);
					}
					break;
			 	}
			} else { // d= char of opponent
				atLeastOneDifferent = true;
				index = k;
			}
		}
	}
}