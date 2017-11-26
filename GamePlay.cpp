/*
 * GamePlay.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#include "GamePlay.h"

#include "ConsoleDisplay.h"
#include <iostream>
using namespace std;

GamePlay::GamePlay() {

}

GamePlay::GamePlay(GameRules * rules , Board &b, Player * p1 , Player * p2) {
	// TODO Auto-generated constructor stub
	this->rules_ = rules;
	this->b_ = b;
	this->p1_ = p1;
	this->p2_ = p2;
	this->disp_ = new ConsoleDisplay(this->b_);
}

vector<Point> GamePlay:: getPossibleMoves(Player * p) {
	return this->rules_->possibleMoves(p , this->b_);
}

/**
 * runs the game until both players has no possible moves or the board's full.
 */
void GamePlay:: playGame() {
	this->disp_->displayBoard(this->b_);
	bool possibleMovesForP1 = true;
	bool possibleMovesForP2 = true;
	while (this->b_.isNotFull() and (possibleMovesForP1 or possibleMovesForP2)) {
		possibleMovesForP1 = this->p1_->playOneTurn(this);
		this->disp_->displayBoard(this->b_);
		possibleMovesForP2 = this->p2_->playOneTurn(this);
		this->disp_->displayBoard(this->b_);
	}
	int countPlayerOne = 0;
	int countPlayerTwo = 0;
	for (int i = 0; i < this->b_.getLength(); i ++) {
		for (int j = 0; j < this->b_.getWidth() ; j ++) {
			if (this->b_.getCell(i , j) == this->p1_->getPlayerChar()) {
				countPlayerOne ++;
			} else if (this->b_.getCell(i , j) == this->p2_->getPlayerChar()) {
				countPlayerTwo ++;
			}
		}
	}
	if (countPlayerOne > countPlayerTwo) {
		cout << "Player one wins!" << endl;
	} else if (countPlayerTwo > countPlayerOne) {
		cout << "Player two wins!" << endl;
	} else {
		cout << "It's a tie!" << endl;
	}
}


void GamePlay:: move(Player * p , int i , int j) {
	char c = p->getPlayerChar();
	this->rules_->performMove(c , i , j , this->b_);
}

GamePlay::~GamePlay() {
	// TODO Auto-generated destructor stub
	delete this->disp_;
}

