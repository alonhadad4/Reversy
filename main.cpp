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
#include "AIPlayer.h"
#include "GameRules.h"
#include "BasicGameRules.h"

int main() {
	Board * b = new Board();
	Player * p1 = new HumanConsolePlayer('X');
    Player * p2;
	char player;
	cout << "Choose Player 2: H for Humen and c for Computer";
	cin >> player;
	if(player == 'c'){
        p2 = new AIPlayer('O');
	} else {
		p2 = new HumanConsolePlayer('O');
	}
	GameRules * rules = new BasicGameRules();
	GamePlay * game = new GamePlay(rules , b , p1 , p2);
	game->playGame();

	delete p1;
	delete p2;
	delete rules;
	delete b;
	delete game;
	return 0;
}
