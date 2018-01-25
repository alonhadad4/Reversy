
#include "RemotePlayer.h"
#include <sstream>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

RemotePlayer::RemotePlayer(const char &c) : Player(c) {
    // TODO Auto-generated constructor stub
}

/**
 * the function is called only when game is instantiated.
 * if the player has no possible moves, it sends a message to the server.
 * in this case, the turn will move to the other player.
 * else, it prints the possible moves and calls initiateTalk.
 * this will read commands from user until play is given.
 * when this happens, the play will be made and sent to server.
 * true will be returned.
*/
bool RemotePlayer:: playOneTurn(GamePlay * game) {
    string input, command;
    while(true) {
        char command[5];
        int num1 = -1, num2 = -1;
        bool hasPlayedCorrectly = false;
        vector<Point>::iterator iter;
        vector<Point> listOfMoves = game->getPossibleMoves(this);
        if ((listOfMoves).empty()) {
            cout << "You have no possible moves. turn moves to other player" << endl;
            try {
                this->sendCommand("play -1 -1");
            } catch (const char *msg) {
                cout << "Failed to send move. reason- " << msg << endl;
            }
            return false; // player has no possible legal moves
        } else {
            int i, j;
            cout << this->c_ << ":your move" << endl;
            cout << "Your possible moves: ";
            for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter++) {
                cout << "(" << iter->getX() + 1 << "," << iter->getY() + 1 << ") ";
            }
            cout << endl;
            input = initiateTalk();
            if (input.compare("start over") == 0) {
                this->c_ = 'd'; // move for game ending
                this->makeMove(0 , 0 , game);
                return false;
            }
            try {
                std::istringstream iss(input);
                vector<string> tempVector;
                for (std::string word; iss >> word;)
                    tempVector.push_back(word);
                strcpy(command, tempVector[0].c_str());
                if (tempVector.size() != 3) {
                    throw invalid_argument("invalid format, sir!");
                }
                i = atoi(tempVector[1].c_str());
                j = atoi(tempVector[2].c_str());
            } catch (exception e) {
                cout << "invalid format, sir! " << endl;
                continue;
            }

            for (iter = listOfMoves.begin(); iter != listOfMoves.end(); iter++) {
                if (i == iter->getX() + 1 and j == iter->getY() + 1) {
                    this->makeMove(i - 1, j - 1, game);
                    num1 = i - 1;
                    num2 = j - 1;
                    hasPlayedCorrectly = true;
                    break;
                }
            }
            if (!hasPlayedCorrectly) {
                cout << "invalid move. " <<endl;
                continue;
            }
        }

        try {
            this->sendCommand(input);
        } catch (const char *msg) {
            cout << "Failed to send move. reason- " << msg << endl;
        }

        cout << "current Board:" << endl;
        return true; // player has played a legal move
    }
}


RemotePlayer::RemotePlayer(const char *serverIP,int serverPort) : serverIP(serverIP),serverPort(serverPort),clientSocket(0) {
}

void RemotePlayer::connectToServer() {
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

string RemotePlayer::initiateTalk() {

    while(true) {
        string cmd;
        cout << "Enter command for game:\n" << "'start <name>' for new game\n";
        cout << "list_games for the list of games waiting for players\n";
        cout << "join <name> to join a specific game\n";
        cout << "play <x> <y> (if game is in progress)\n";
        cout << "close <name> to close a specific game\n";
        getline(cin,cmd);
        if (cmd.compare("list_games") == 0) { // client asked list of games
            this->sendCommand(cmd);
            this->readListOfGames(); //list of games is printed to console
            this->connectToServer();
        } else {// command is start/join/close
            stringstream ss(cmd);
            string firstWord;
            ss >> firstWord;
            if (firstWord.compare("play") == 0) {
                return cmd;
            }
            if (firstWord.compare("close") == 0) {
                this->sendCommand(cmd);
                this->hasGameStarted = false;
                return "start over";
            }
            if (this->hasGameStarted) {
                cout << "Sorry , this is not a valid option. try again, sir!" << endl;
                continue;
            }
            if (firstWord.compare("start") == 0 || firstWord.compare("join") == 0) { // start or join
                this->sendCommand(cmd);
                int num = this->readNum();
                if (num == 1001) {
                    this->hasGameStarted = true;
                    break;
                } else {
                    cout << "this game already exists :/ . try again!" << endl;
                }
            }
        }
    }
    // out of the loop means that game starts
    int numForChar = this->readNum();
    this->c_ = 'X';
    if (numForChar == O) {
        this->c_= 'O';
    }
    return "";
}

void RemotePlayer:: sendCommand(string cmd) {
    int len = strlen(cmd.c_str())+1;
    int n = write(clientSocket,&len,sizeof(len));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
    char m[len];
    strcpy(m , cmd.c_str());
    m[len-1] = '\0';
    n = write(clientSocket,&m,sizeof(m));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
}

// function reads number of games and then reads the list of games.
void RemotePlayer:: readListOfGames() {
    // vector<string> listGames;
    int numOfGames = this->readNum();
    cout << "Optional games to join:\n";
    for (int i = 1; i <= numOfGames; i++) {
        // listGames.push_back(name);
        int num1;
        int n = read(this->clientSocket,&num1,sizeof(num1));
        if (n == -1){
            cout << "Error reading msg" << endl;
        }
        if (num1 == -1001) {
            cout << "Server is down. exiting from program" << endl;
        }
        char buffer[num1];
        bzero((char*) &buffer, sizeof(buffer));
        n = read(this->clientSocket,&buffer,sizeof(buffer));
        if (n == -1){
            cout << "Error reading msg" << endl;
        }

        cout << i << ". " << buffer << "\n";
    }
    // return listGames;
}

/**
 * the function sends the move with seperators of "," and " " between the nums.
*/
void RemotePlayer::sendMove(int num1,int num2){
    // char sep1 = ',';
    // char sep2 = ' ';
    string str = num1 + " " + num2;
    int n = write(clientSocket,&str,sizeof(str));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
    /*
    n = write(clientSocket,&sep1,sizeof(sep1));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
    n = write(clientSocket,&sep2,sizeof(sep2));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
    n = write(clientSocket,&num2,sizeof(num2));
    if (n== -1){
        throw "Error writing msg1 to socket";
    }
    */
}

/**
 * the number that is read from the server means the char of the player.
*/
int RemotePlayer::readNum() {
    int num;
    int n = read(clientSocket,&num,sizeof(num));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    if (num == -1001) {
        cout << "Server is down. exiting from program" << endl;
    }
    return num;
}

int RemotePlayer:: getClientSocket() {
    return clientSocket;
}

RemotePlayer::~RemotePlayer() {
    // TODO Auto-generated destructor stub
}
