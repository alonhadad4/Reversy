import java.util.List;
public abstract class GameRules {
	public abstract boolean isMoveLegal(char c , int i , int j, Board b);
	public abstract List possibleMoves(Player p , Board b);

	public void performMove(char c , int i , int j , Board b) {
		this.performOnRow(c, i , j , b);
		this.performOnColumn(c, i , j , b);
		this.performOnFirstDiagonal(c, i , j , b);
		this.performOnSecondDiagonal(c, i , j , b);
		b.setCell(i , j , c);
	}

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