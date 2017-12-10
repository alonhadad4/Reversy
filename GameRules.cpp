#include "GameRules.h"
#include <iostream>
using namespace std;

GameRules:: GameRules() {

}

GameRules:: GameRules(const GameRules &g) {
}

/**
 * function calls making the move on row, column and diagonals.
 * later, it sets the cell itself to the char given.
 */
void GameRules:: performMove(char c , int i , int j , Board& b) {
	this->performOnRow(c , i , j , b);
	this->performOnColumn(c , i , j , b);
	this->performOnFirstDiagonal(c , i , j , b);
	this->performOnSecondDiagonal(c , i , j , b);
	b.setCell(i , j , c);
}

/**
 * function starts from the cell and turns to the end of the row.
 * it checks whether cells has to be changed there because of the move.
 * if yes, it changes them and returns.
 * if not, it checks the beginning of the row, again: yes-> change, return.
 */
void GameRules:: performOnRow(char c ,int i ,int j ,Board& b) {
		char d;
		char op = 'X';
		if (c == 'X') {
			op = 'O';
		}
		int index = -1;
		bool atLeastOneDifferent = false;
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
 * function starts from the cell and turns to the end of the column.
 * it checks whether cells has to be changed there because of the move.
 * if yes, it changes them and returns.
 * if not, it checks the beginning of the column, again: yes-> change, return.
 */
void GameRules:: performOnColumn(char c ,int i ,int j ,Board& b) {
	char d;
	char op = 'X';
	if (c == 'X') {
		op = 'O';
	}
	int index = -1;
	bool atLeastOneDifferent = false;
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
/*
	for (int k = i + 2; k < b.getLength(); k ++) {
			if (b.getCell(k , j) == c) {
				for (int l = i + 1; l < k; l ++) {
					b.setCell(l , j , c);
				}
				return;
			}
	}
*/
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
/*
	for (int k = i - 2; k >= 0; k --) {
		if (b.getCell(k , j) == c) {
			for (int l = i - 1; l > k; l --) {
				b.setCell(l , j , c);
			}
			return;
		}
	}
*/
}

/**
 * function starts from the cell and turns to one side of first diagonal of it.
 * it checks whether cells has to be changed there because of the move.
 * if yes, it changes them and returns.
 * if not, it checks the other side of diagonal, again: yes-> change, return.
 */
void GameRules:: performOnFirstDiagonal(char c ,int i ,int j ,Board& b) {
	char d;
	char op = 'X';
	if (c == 'X') {
		op = 'O';
	}
	int index = -1;
	bool atLeastOneDifferent = false;
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
/*
	for (int k = i - 2 , l = j - 2; k >= 0 and l >= 0; k -- , l --) {
		if (b.getCell(k , l) == c) {
			for (int m = i - 1 , n = j - 1; m >= k and n >= l; m --, n --) {
				b.setCell(m , n , c);
			}
			return;
		}
	}
*/
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
/*
	for (int k = i + 2 , l = j + 2; k < b.getLength() and l < b.getWidth(); k ++ , l ++) {
		if (b.getCell(k , l) == c) {
			for (int m = i + 1 , n = j + 1; m < k and n < l; m ++, n ++) {
				b.setCell(m , n , c);
			}
			return;
		}
	}
*/
}

/**
 * function starts from cell and turns to one side of second diagonal of it.
 * it checks whether cells has to be changed there because of the move.
 * if yes, it changes them and returns.
 * if not, it checks the other side of diagonal, again: yes-> change, return.
 */
void GameRules:: performOnSecondDiagonal(char c ,int i ,int j ,Board& b) {
	char d;
	char op = 'X';
	if (c == 'X') {
		op = 'O';
	}
	int index = -1;
	bool atLeastOneDifferent = false;
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
/*
	for (int k = i + 2 , l = j - 2; k < b.getLength() and l >= 0; k ++ , l --) {
		if (b.getCell(k , l) == c) {
			for (int m = i + 1 , n = j - 1; m <= k and n >= l; m ++, n --) {
				b.setCell(m , n , c);
			}
			return;
		}
	}
*/
	/*
	for (int k = i - 2 , l = j + 2; k >= 0 and l < b.getWidth(); k -- , l ++) {
		if (b.getCell(k , l) == c) {
			for (int m = i - 1 , n = j + 1; m > k and n < l; m --, n ++) {
				b.setCell(m , n , c);
			}
			return;
		}
	}
*/
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
