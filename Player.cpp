#include "Player.h"

Player:: Player() {

}

Player:: Player(const char &c) {
	this->c_ = c;
}
char Player:: getPlayerChar() {
	return this->c_;
}
/**
 * calls the move function of the game parameter.
 */
void Player:: makeMove(int i , int j ,GamePlay * game) {
	game->move(this , i , j);
}

Player& Player:: operator= (const Player& p) {
	return *this;
}

Player:: ~Player() {

}
