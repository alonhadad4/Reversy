
#include "RemotePlayer.h"
#include <sstream>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;

RemotePlayer::RemotePlayer(const char &c) : Player(c) {
    // TODO Auto-generated constructor stub
}

bool RemotePlayer:: playOneTurn(GamePlay * game) {
    char d;
    string action;
    int num1 = -1 , num2 = -1;
    bool hasPlayedCorrectly = false;
    vector<Point>:: iterator iter;
    vector<Point> listOfMoves = game->getPossibleMoves(this);
    if ((listOfMoves).empty()) {
        cout << "You have no possible moves. press any key to continue." << endl;
        cin >> d;
        return false; // player has no possible legal moves
    } else {
        int i , j;
        while (!hasPlayedCorrectly) {
            cout << this->c_ << ":your move" << endl;
            cout << "Your possible moves: ";
            for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
                cout <<"(" << iter->getX() + 1 << "," << iter->getY() + 1 << ") ";
            }
            cout << endl;
            cout << "enter row number, space and column number: ";
            bool invalidInp = true;
            while (invalidInp) {
                getline(cin, action);
                try {
                    int p = action.find(', ');
                    if (p == -1) {
                        throw std::invalid_argument("Bad argument");
                    }
                    istringstream(action.substr(0, p)) >> i;
                    istringstream(action.substr(p + 1, action.size() - 2)) >> j;
                    invalidInp = false;
                } catch (...) {
                    cout << "invalid format, enter row number, space and column number:" << endl;
                    cout << "Your possible moves: ";
                    for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter++) {
                        cout << "(" << iter->getX() + 1 << "," << iter->getY() + 1 << ") ";
                    }
                }
            }
            for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter ++) {
                if (i == iter->getX() + 1 and j == iter->getY() + 1) {
                    this->makeMove(i - 1  , j - 1 , game);
                    num1 = i - 1;
                    num2 = j - 1;
                    hasPlayedCorrectly = true;
                    break;
                }
            }
        }
    }
    try {
        this->sendMove(action);
    } catch (const char *msg){
        cout << "Failed to send move. reason- " << msg << endl;
    }
    return true; // player has played a legal move
}


RemotePlayer::RemotePlayer(const char *serverIP, int serverPort , const char &c): Player(c)
        , serverIP(serverIP),serverPort(serverPort),clientSocket(0){
    cout << "Client" << endl;
}

void RemotePlayer::connectToServer() {
    //Create a socket Point
    clientSocket = socket(AF_INET,SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    struct in_addr address;
    if(!inet_aton(serverIP,&address)){
        throw "Can't parse IP adress";
    }
    struct hostent *server;
    server = gethostbyaddr((const void *)&address,sizeof(address),AF_INET);
    if (server == NULL){
        throw "Host is unreachable";
    }

    struct sockaddr_in serverAddress;
    bzero((char *)&address,sizeof(address));

    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);

    if(connect(clientSocket,(struct sockaddr *)&serverAddress, sizeof(serverAddress))== -1){
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

}

char* RemotePlayer::sendMove(string msg1){
    int n = write(clientSocket,&msg1,sizeof(msg1));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
}

int RemotePlayer::readNum() {
    int num;
    int n = read(clientSocket,&num,sizeof(num));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    return num;
}

int RemotePlayer:: getClientSocket() {
    return clientSocket;
}

RemotePlayer::~RemotePlayer() {
    // TODO Auto-generated destructor stub
}