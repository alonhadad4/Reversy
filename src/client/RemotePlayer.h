
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
    void connectToServer();
    void sendMove(int num1, int num2);
    int readNum();
    int getClientSocket();
    /**
     * the function returns true if player has made a legal move.
     * returns false if player has no optional legal moves.
     */

    virtual bool playOneTurn(GamePlay * game);
    virtual ~RemotePlayer();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};

#endif //EX2_REMOTEPLAYER_H
