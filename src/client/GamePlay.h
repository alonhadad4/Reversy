/*
 * GamePlay.h
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include "GameRules.h"
#include "Player.h"
#include "Board.h"
#include "BoardDisplayer.h"
#include "Point.h"
#include <vector>
using namespace std;
enum Symbol {X = 1 , O = 2};
class Player;
class GameRules;

class GamePlay {
public:
	GamePlay();
	/**
	 * initializes all members, including disp_ with consoleDisplay.
	 */
	GamePlay(GameRules * rules , Board * b , Player * p1 , Player * p2);
	virtual void move(char c , int i ,  int j);
	/**
	 * runs the game.
	 */
	void playGame();
	vector<Point> getPossibleMoves(Player * p);
	GamePlay& operator= (const GamePlay& g);
	void destroyBoard();
	int getScore (Player * p);
	int bestScoreForOtherPlayer(Player * p);
	void swapPlayers ();
	GamePlay(const GamePlay &game);
	virtual ~GamePlay();
private:
	GameRules * rules_;
	Board * b_;
	Player * p1_;
	Player * p2_;
	BoardDisplayer * disp_;
};

#endif /* GAMEPLAY_H_ */
