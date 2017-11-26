#ifndef GAMERULES_H_
#define GAMERULES_H_
#include "Board.h"
#include "Player.h"
#include "Point.h"
#include <vector>
using namespace std;
class Player;
class GameRules {
public:
	GameRules();
	virtual bool isMoveLegal(Player * p , int i , int j , Board& b) = 0;
	virtual  vector<Point> possibleMoves(Player * p , Board& b) = 0;
	virtual void performMove(char c , int i , int j , Board& b);
	/**
	 * the function checks if a move of (i,j) changes row i.
	 * if so, it changes the row according to the rules.
	 */
	virtual void performOnRow(char c ,int i ,int j ,Board& b);
	/**
	 * see comment for "performOnRow", simply for column.
	 */
	virtual void performOnColumn(char c ,int i ,int j ,Board& b);
	/**
	 * see comment for "performOnRow", simply for one of the diagonals.
	 */
	virtual void performOnFirstDiagonal(char c ,int i ,int j ,Board& b);
	/**
	 * see comment for "performOnRow", simply for second of diagonals.
	 */
	virtual void performOnSecondDiagonal(char c ,int i ,int j ,Board& b);
};

#endif /* GAMERULES_H_ */
