//
// Created by jonathan on 28/11/17.
//

#include "AIPlayer.h"
#include <iostream>
using namespace std;

AIPlayer::AIPlayer(const char &c) : Player(c) {
	// TODO Auto-generated constructor stub
}

bool AIPlayer:: playOneTurn(GamePlay * game) {
    int min , currentScore;
    Point bestMove;
    GamePlay * copyGame;
    vector<Point>:: iterator iter;
    vector<Point> listOfMoves = game->getPossibleMoves(this);
    if ((listOfMoves).empty()) {
        return false; // player has no possible legal moves
    } else {
        for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
            copyGame = (new GamePlay(*game));
            this->makeMove(iter->getX()  , iter->getY() , copyGame);
            currentScore = copyGame->bestScoreForOtherPlayer(this);
            if (iter != listOfMoves.begin()) {
                if (currentScore < min) {
                    min = currentScore;
                    bestMove = Point(iter->getX() , iter->getY());
                }
            } else {
                min = currentScore;
                bestMove = Point(iter->getX() , iter->getY());
            }
            copyGame->destroyBoard();
            delete copyGame;
        }
    }
    cout <<this->c_<< " played (" << bestMove.getX() + 1 << " , " << bestMove.getY() + 1 << ")" << endl;
    this->makeMove(bestMove.getX() , bestMove.getY() , game);
    return true;
}

AIPlayer::~AIPlayer() {
	// TODO Auto-generated destructor stub
}
