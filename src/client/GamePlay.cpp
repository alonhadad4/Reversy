/*
 * GamePlay.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#include "GamePlay.h"

#include "ConsoleDisplay.h"
#include "VirtualPlayer.h"
#include "RemotePlayer.h"
#include <iostream>
using namespace std;

GamePlay::GamePlay() {

}

GamePlay::GamePlay(GameRules * rules , Board  * b, Player * p1 , Player * p2) {
	// TODO Auto-generated constructor stub
	this->rules_ = rules;
	this->b_ = b;
	this->p1_ = p1;
	this->p2_ = p2;
	this->disp_ = new ConsoleDisplay(b);
}

vector<Point> GamePlay:: getPossibleMoves(Player * p) {
	return this->rules_->possibleMoves(p , *(this->b_));
}

/**
 * runs the game until both players has no possible moves or the board's full.
 */
void GamePlay:: playGame() {
	this->disp_->displayBoard(this->b_);
	bool possibleMovesForP1 = true;
	bool possibleMovesForP2 = true;
	while (this->b_->isNotFull() and (possibleMovesForP1 or possibleMovesForP2)) {
		possibleMovesForP1 = this->p1_->playOneTurn(this);
		if (this->b_->getCell(0,0) == 'd') {
			return;
		}
		this->disp_->displayBoard(this->b_);
		possibleMovesForP2 = this->p2_->playOneTurn(this);
        if (this->b_->getCell(0,0) == 'd') {
            return;
        }
		this->disp_->displayBoard(this->b_);
	}
	int countPlayerOne = 0;
	int countPlayerTwo = 0;
	for (int i = 0; i < this->b_->getLength(); i ++) {
		for (int j = 0; j < this->b_->getWidth() ; j ++) {
			if (this->b_->getCell(i , j) == this->p1_->getPlayerChar()) {
				countPlayerOne ++;
			} else if (this->b_->getCell(i , j) == this->p2_->getPlayerChar()) {
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


void GamePlay:: move(char c , int i , int j) {
	this->rules_->performMove(c , i , j , *(this->b_));
}

int GamePlay:: bestScoreForOtherPlayer(Player * p) {
    int max , currentScore;
    vector<Point>:: iterator iter;
	Player * opponent;
	if (p == this->p1_) {
		opponent = this->p2_;
	}
	if (p == this->p2_) {
		opponent = this->p1_;
	}
    char charOp = opponent->getPlayerChar();
    vector<Point> listOfMoves = this->getPossibleMoves(opponent);
    GamePlay * copyGame;
    if ((listOfMoves).empty()) {
        return this->b_->getLength() * this->b_->getWidth(); // player has no possible legal moves
    } else {
        for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
            copyGame = (new GamePlay(*this));
            copyGame->move(charOp , iter->getX()  , iter->getY());
            currentScore = copyGame->getScore(opponent);
            if (iter == listOfMoves.begin()) {
                max =currentScore;
            } else if (currentScore > max) {
                max = currentScore;
            }
			delete copyGame->b_;
            delete copyGame;
        }
    }
    return max;
}

int GamePlay:: getScore(Player * p) {
    char c = p->getPlayerChar();
    char currentChar;
    int countThisPlayer = 0;
    int countOtherPlayer = 0;
    for (int i = 0; i < this->b_->getLength(); i ++) {
        for (int j = 0; j < this->b_->getWidth() ; j ++) {
            currentChar =this->b_->getCell(i , j);
            if (currentChar == c) {
                countThisPlayer ++;
            } else if (currentChar != ' ') {
                countOtherPlayer ++;
            }
        }
    }
    return (countThisPlayer - countOtherPlayer);
}

GamePlay:: GamePlay(const GamePlay &game) {
	this->b_ = new Board(*(game.b_));
	this->rules_ = game.rules_;
	this->p1_= game.p1_;
	this->p2_= game.p2_;
	this->disp_ = new ConsoleDisplay(this->b_);
}

void GamePlay:: destroyBoard() {
	delete this->b_;
}

GamePlay::~GamePlay() {
	// TODO Auto-generated destructor stub
	delete this->disp_;
}

void GamePlay::swapPlayers() {
    Player * temp;
    temp = this->p1_;
	this->p1_ = this->p2_;
	this->p2_ = temp;
}

GamePlay& GamePlay:: operator= (const GamePlay& g) {
    return *this;
}

