/*
 * HumanConsolePlayer.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */
#include <iostream>
using namespace std;
#include "HumanConsolePlayer.h"
#include "Player.h"
#include "Point.h"
#include <vector>



HumanConsolePlayer::HumanConsolePlayer(const char &c) : Player(c) {
	// TODO Auto-generated constructor stub
}

/**
 * the function gets list of possible moves for the player from game parameter.
 * if it is empty, it returns false.
 * otherwise, it asks the player for a move until he enters a legal move from
 * the list.
 * after that, it calls a function that makes the move in the game.
 * then it returns true.
 */
bool HumanConsolePlayer:: playOneTurn(GamePlay * game) {
	char d;
	bool hasPlayedCorrectly = false;
	vector<Point>:: iterator iter;
	vector<Point> listOfMoves = game->getPossibleMoves(this);
	if ((listOfMoves).empty()) {
		cout << "You have no possible moves. press any key to continue." << endl;
		cin >> d;
		return false; // player has no possible legal moves
	} else {
		int i , j;
		while (!hasPlayedCorrectly) {
			cout << "Your possible moves: ";
			for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
				cout <<"(" << iter->getX() + 1 << "," << iter->getY() + 1 << ") ";
			}
			cout << endl;
			cout << "enter row number, space and column number: ";
			cin >> i >> j;
			for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
				if (i == iter->getX() + 1 and j == iter->getY() + 1) {
					this->makeMove(i - 1  , j - 1 , game);
					hasPlayedCorrectly = true;
					break;
				}
			}
		}
	}
	return true; // player has played a legal move
}


HumanConsolePlayer::~HumanConsolePlayer() {
	// TODO Auto-generated destructor stub
}

