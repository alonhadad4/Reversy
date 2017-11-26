/*
 * main.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: jonathan
 */
#include <iostream>
using namespace std;
#include "Board.h"
#include "BoardDisplayer.h"
#include "ConsoleDisplay.h"
#include "Player.h"
#include "HumanConsolePlayer.h"
#include "GameRules.h"
#include "BasicGameRules.h"

int main() {
	Board b;
	Player * p1 = new HumanConsolePlayer('X');
	Player * p2 = new HumanConsolePlayer('O');
	GameRules * rules = new BasicGameRules();
	GamePlay * game = new GamePlay(rules , b , p1 , p2);
	game->playGame();

	delete p1;
	delete p2;
	delete rules;
	delete game;
	return 0;
}
