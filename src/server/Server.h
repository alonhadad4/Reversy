

#ifndef UNTITLED5_SERVER_H
#define UNTITLED5_SERVER_H

#include <string>
#include <map>
#include "CommandsManager.h"
#include "ThreadPool.h"

using namespace std;

class Server {
public:
    Server(int port);
	/**
	* the function activates the server and waits for clients.
	* when clients are connected, it calls the game loop.
	*/
    void start();
	/**
	* the function closes the server.
	*/
    void stop();
    void startNewGame(string name , int clientSocket);

    void showGameList(int clientSocket);

    void closeGame(string name);

    void joinGame(string name , int clientSocket);

    //this function will execute a move
    void executeMove(int i , int j, int clientSocket);


private:
    int port;
    ThreadPool * threadPool;
    int serverSocket;
    vector<int> clients;
    static void *listeningLoop(void * arg);
    map <string, pthread_t *> listOfGames;
    CommandsManager * cm;
    static void * gameLoop(void *t);
    static void * clientLoop(void * s1);
    int getClientSocket (int i);
    void activateCm(string str , vector<string> args);
    map <string,int> pendingGames;
    map <string, vector<int> > pvplist;
	/**
	* the function runs the game for two servers, reading and writing to them.
	*/
    void startGameLoop(int cp1,int cp2);
	/**
	* the function sends a player with client socket cp his sign in the game.
	*/
    void sendSign(int sign,int cp);


};

#endif //UNTITLED5_SERVER_H