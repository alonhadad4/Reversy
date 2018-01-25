
#ifndef EX2_REMOTEPLAYER_H
#define EX2_REMOTEPLAYER_H
#include "GamePlay.h"
#include "Player.h"
#include "Point.h"
#include <string>


class RemotePlayer : public Player {
public:
    RemotePlayer(const char *ServerIP,int serverPort);
    RemotePlayer(const char *ServerIP,int serverPort , const char &c);
    RemotePlayer(const char &c);
	/**
	* the function connects to the server.
	*/
    void connectToServer();
	/**
	* the function sends move (num1,num2) to the server.
	*/
    void sendMove(int num1, int num2);
	/**
	* the function reads a number from the server.
	* then, it initializes the player's char member according to it.
	* lastly, it returns the number it read.
	*/
    int readNum();
    int getClientSocket();
    /**
	* the function plays a move that the player enters.
	* the function returns true if player has made a legal move.
	* returns false if player has no optional legal moves.
	*/
    virtual bool playOneTurn(GamePlay * game);
    string initiateTalk();
    virtual ~RemotePlayer();
private:
    bool hasGameStarted;
    const char *serverIP;
    int serverPort;
    int clientSocket;
    void sendCommand(string cmd);
    void readListOfGames();
};

#endif //EX2_REMOTEPLAYER_H
