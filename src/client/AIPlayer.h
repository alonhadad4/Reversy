//
// Created by jonathan on 28/11/17.
//

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H
#include "GamePlay.h"
#include "Player.h"
#include "Point.h"


class AIPlayer : public Player {
public:
    AIPlayer(const char &c);
	/**
	 * the function returns true if player has made a legal move.
	 * returns false if player has no optional legal moves.
	 */
    virtual bool playOneTurn(GamePlay * game);
    virtual ~AIPlayer();
};


#endif //EX2_AIPLAYER_H
