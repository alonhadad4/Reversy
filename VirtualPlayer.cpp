
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

bool VirtualPlayer:: playOneTurn(GamePlay * game) {
    string msg1 = this->readMove();
    if (msg1.compare("noMove")) {
        return false;
    }
    int i,j;
    int p = msg1.find(', ');
    istringstream(msg1.substr(0, p)) >> i;
    istringstream(msg1.substr(p + 1 , msg1.size() - 2)) >> j;
    this->makeMove(i - 1  , j - 1 , game);
    return true;
}


VirtualPlayer::VirtualPlayer(const char *serverIP, int serverPort , const char &c):
        Player(c) , serverIP(serverIP),serverPort(serverPort),clientSocket(0){
    cout << "Client" << endl;
}

string VirtualPlayer::readMove(){
    string msg1;
    int n = read(clientSocket,&msg1,sizeof(msg1));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    return msg1;
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
}

VirtualPlayer::~VirtualPlayer() {
    // TODO Auto-generated destructor stub
}