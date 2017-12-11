/*
 * BasicGameRules.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#include "BasicGameRules.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace std;
class GameRules;
class Player;

BasicGameRules::BasicGameRules() {
	// TODO Auto-generated constructor stub

}

/**
 * function starts from the cell and turns to the beginning of the row.
 * it checks whether there are cells of second player adjacent to (i,j).
 * if yes, it checks if there is another cell of this player farther on.
 * if there is, it returns true.
 * if it hasn't returned, it does the same process towards end of the row.
 */

bool BasicGameRules:: checkRow(Player * p , int i , int j , Board& b) {
	bool isThereSameColor = false;
	bool isThereOtherColor = false;
	for (int k = j - 1; k >= 0; k --) {
		if (b.getCell(i , k) == ' ' or (b.getCell(i ,k) == p->getPlayerChar() and k == j - 1)) {
			break;
		}
		if (b.getCell(i ,k) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(i ,k) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	isThereSameColor = isThereOtherColor = false;
	for (int k = j + 1; k < b.getWidth(); k ++) {
		if (b.getCell(i , k) == ' ' or (b.getCell(i ,k) == p->getPlayerChar() and k == j + 1)) {
			break;
		}
		if (b.getCell(i ,k) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(i ,k) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	return false;
}

/**
 * function starts from the cell and turns to the beginning of the column.
 * it checks whether there are cells of second player adjacent to (i,j).
 * if yes, it checks if there is another cell of this player farther on.
 * if there is, it returns true.
 * if it hasn't returned, it does the same process towards end of the column.
 */

bool BasicGameRules:: checkColumn(Player * p , int i , int j , Board& b) {
	bool isThereSameColor = false;
	bool isThereOtherColor = false;
	for (int k = i - 1; k >= 0; k --) {
		if (b.getCell(k , j) == ' ' or (b.getCell(k ,j) == p->getPlayerChar() and k == i - 1)) {
			break;
		}
		if (b.getCell(k ,j) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,j) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	isThereSameColor = isThereOtherColor = false;
	for (int k = i + 1; k < b.getLength(); k ++) {
		if (b.getCell(k , j) == ' ' or (b.getCell(k ,j) == p->getPlayerChar() and k == i + 1)) {
			break;
		}
		if (b.getCell(k ,j) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,j) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	return false;
}

/**
 * function starts from the cell and turns to one side of the first diagonal.
 * it checks whether there are cells of second player adjacent to (i,j).
 * if yes, it checks if there is another cell of this player farther on.
 * if there is, it returns true.
 * if hasn't returned, it does the same process towards other side of diagonal.
 */

bool BasicGameRules:: checkFirstDiagonal(Player * p , int i , int j , Board& b) {
	bool isThereSameColor = false;
	bool isThereOtherColor = false;
	for (int k = i - 1 , l = j - 1; k >= 0 and l >= 0; k -- , l --) {
		if (b.getCell(k , l) == ' ' or (b.getCell(k ,l) == p->getPlayerChar() and k == i - 1)) {
			break;
		}
		if (b.getCell(k ,l) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,l) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	isThereSameColor = isThereOtherColor = false;
	for (int k = i + 1 , l = j + 1; k < b.getLength() and l < b.getWidth(); k ++ , l ++) {
		if (b.getCell(k , l) == ' ' or (b.getCell(k ,l) == p->getPlayerChar() and k == i + 1)) {
			break;
		}
		if (b.getCell(k ,l) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,l) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	return false;
}

/**
 * function starts from the cell and turns to one side of the second diagonal.
 * it checks whether there are cells of second player adjacent to (i,j).
 * if yes, it checks if there is another cell of this player farther on.
 * if there is, it returns true.
 * if hasn't returned, it does the same process towards other side of diagonal.
 */

bool BasicGameRules:: checkSecondDiagonal(Player * p , int i , int j , Board& b) {
	bool isThereSameColor = false;
	bool isThereOtherColor = false;
	for (int k = i + 1 , l = j - 1; k < b.getLength() and l >= 0; k ++ , l --) {
		if (b.getCell(k , l) == ' ' or (b.getCell(k ,l) == p->getPlayerChar() and k == i + 1)) {
			break;
		}
		if (b.getCell(k ,l) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,l) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	isThereSameColor = isThereOtherColor = false;
	for (int k = i - 1 , l = j + 1; k >= 0 and l < b.getWidth(); k -- , l ++) {
		if (b.getCell(k , l) == ' ' or (b.getCell(k ,l) == p->getPlayerChar() and k == i - 1)) {
			break;
		}
		if (b.getCell(k ,l) != p->getPlayerChar()) {
			isThereOtherColor = true;
		}
		if (b.getCell(k ,l) == p->getPlayerChar()) {
			isThereSameColor = true;
		}
		if (isThereSameColor and isThereOtherColor) {
			return true;
		}
	}
	return false;
}

/**
 * returns true if one of: row, column or diagonal checks was true.
 */
bool BasicGameRules:: isMoveLegal(Player * p, int i , int j , Board& b) {
	if (this->checkRow(p , i , j , b) or this->checkColumn(p , i , j , b) or checkFirstDiagonal(p , i , j , b)
		or this->checkSecondDiagonal(p , i , j , b)) {
		return true;
	}
	return false;

}
/**
 * function puts all cells that are optional legal moves in a vector.
 * it puts them as point objects, containing x and y for row and column.
 * it returns the vector.
 */
vector<Point> BasicGameRules:: possibleMoves(Player * p, Board& b) {
	vector<Point> vec;
	for (int i = 0; i < b.getLength(); i ++) {
		for (int j = 0; j < b.getWidth(); j ++) {
			if (b.getCell(i , j) == ' ' and this->isMoveLegal(p , i , j , b)) {
				Point po (i , j);
				vec.push_back(po);
			}
		}
	}
	return vec;
}


BasicGameRules::~BasicGameRules() {
	// TODO Auto-generated destructor stub
}

