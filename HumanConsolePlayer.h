/*
 * HumanConsolePlayer.h
 *
 *  Created on: Nov 9, 2017
 *      Author: jonathan
 */

#ifndef HUMANCONSOLEPLAYER_H_
#define HUMANCONSOLEPLAYER_H_
#include "Player.h"
#include "GamePlay.h"

class HumanConsolePlayer : public Player {
public:
	HumanConsolePlayer(const char &c);
	/**
	 * the function returns true if player has made a legal move.
	 * returns false if player has no optional legal moves.
	 */
	virtual bool playOneTurn(GamePlay * game);
	virtual ~HumanConsolePlayer();
};

#endif /* HUMANCONSOLEPLAYER_H_ */
