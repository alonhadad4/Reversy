
#include "VirtualPlayer.h"
#include <sstream>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;

VirtualPlayer::VirtualPlayer(const char &c) : Player(c) {
    // TODO Auto-generated constructor stub
}

/**
* if the function reads a move (-1,-1) from the server, it returs false.
* otherwise, it makes it in the game and returns true.
*/
bool VirtualPlayer:: playOneTurn(GamePlay * game) {
    cout << "waiting for second player move..." << endl;
    int valueArr [2];
    this->readMove(valueArr);
    if ((valueArr[0] == -1 && valueArr[1] == -1) || valueArr[0] == -2 && valueArr[1] == -2) {
        return false;
    }
    if (valueArr[0] == -5) {
        game->move('d' , 0 , 0);
        return true;
    }
    this->makeMove(valueArr[0] , valueArr[1] , game);
    return true;
}


VirtualPlayer::VirtualPlayer(const char *serverIP, int serverPort , const char &c):
        Player(c) , serverIP(serverIP),serverPort(serverPort),clientSocket(0){
    cout << "Client" << endl;
}

/**
* the functions reads two separators between the numbers: "," and " ".
* then it puts the numbers in the first and second cells of the array given.
*/
void VirtualPlayer::readMove(int valueArr[]){
    int num1,num2;
    char sep;
    int n = read(clientSocket,&num1,sizeof(num1));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    n = read(clientSocket,&sep,sizeof(sep));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    /*
    n = read(clientSocket,&sep,sizeof(sep));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
     */
    n = read(clientSocket,&num2,sizeof(num2));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    valueArr[0] = num1;
    valueArr[1] = num2;
}

char VirtualPlayer::readChar() {
    char c;
    int n = read(clientSocket,&c,sizeof(c));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
}

void VirtualPlayer:: setClientSocket(int cSocket) {
    clientSocket = cSocket;
    cout << clientSocket << endl;
}

VirtualPlayer::~VirtualPlayer() {
    // TODO Auto-generated destructor stub
}
