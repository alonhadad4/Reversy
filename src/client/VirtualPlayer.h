
#ifndef EX4_VIRTUALPLAYER_H
#define EX4_VIRTUALPLAYER_H
#include "GamePlay.h"
#include "Player.h"
#include "Point.h"
#include <string>

class VirtualPlayer : public Player {
public:
    VirtualPlayer(const char *ServerIP,int serverPort);
    VirtualPlayer(const char *ServerIP,int serverPort , const char &c);
    VirtualPlayer(const char &c);
	/**
	* the function reads a move from the server.
	*/
    void readMove(int valueArr[]);
	/**
	* the function reads a char from the server and returns it.
	*/
    char readChar();
    void setClientSocket(int cSocket);
    /**
	* the function waits to read a move from the server.
	* then, it makes the move in the game.
	* the function returns true if player has made a legal move.
	* returns false if player has no optional legal moves.
	*/
    virtual bool playOneTurn(GamePlay * game);
    virtual ~VirtualPlayer();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //EX4_VIRTUALPLAYER_H
