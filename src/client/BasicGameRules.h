/*
 * BasicGameRules.h
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#ifndef BASICGAMERULES_H_
#define BASICGAMERULES_H_
#include "GameRules.h"
#include "Board.h"
#include "Player.h"
#include "Point.h"
using namespace std;
#include <vector>

class BasicGameRules : public GameRules {
public:
	BasicGameRules();
	/**
	 * the function checks if move (i,j) is legal.
	 * i.e. if move transfers at least one cell to the player making it.
	 */
	virtual bool isMoveLegal(Player * p, int i , int j , Board& b);
	/**
	 * the function checks if move (i,j) is legal as for looking at row i.
	 * i.e. if move transfers at least one cell to the player making it.
	 */
	virtual bool checkRow(Player * p , int i , int j , Board& b);
	/**
	 * see comment on "checkRow", simply for column j.
	 */
	virtual bool checkColumn(Player * p , int i , int j , Board& b);
	/**
	 * see comment on "checkRow", simply for first diagonal of (i,j).
	 */
	virtual bool checkFirstDiagonal(Player * p , int i , int j , Board& b);
	/**
	 * see comment on "checkRow", simply for second diagonal of (i,j).
	 */
	virtual bool checkSecondDiagonal(Player * p , int i , int j , Board& b);
	virtual  vector<Point> possibleMoves(Player * p, Board& b);

	virtual ~BasicGameRules();
};

#endif /* BASICGAMERULES_H_ */
