#ifndef PLAYER_H_
#define PLAYER_H_
#include "Board.h"
#include "GamePlay.h"
class GamePlay;
/**
 * class player is abstract. deriving class must implement playOneTurn.
 */
class Player {
public:
	Player();
	Player(const char &c);
	virtual char getPlayerChar();
	virtual bool playOneTurn(GamePlay * game) = 0;
	virtual Player& operator= (const Player& p);
	/**
	 * makes a legal move in the game, decided by the caller.
	 */
	virtual void makeMove(int i , int j , GamePlay * game);
	Player(const Player &p);
	~Player();
protected:
	char c_;
};

#endif /* PLAYER_H_ */
