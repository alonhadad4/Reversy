#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
Server::Server(int port):port(port),serverSocket(0) {
    cout << "Server" << endl;
}

void Server::start(){
    serverSocket = socket(AF_INET,SOCK_STREAM, 0);
    if(serverSocket == -1) {
        throw "Error opening socket";
    }

    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);
    cout << "Waiting for client connections..." << endl;
    while(true) {
        while (this->cp1 == -1 || this->cp2 == -1) {
            int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
            if (this->cp1 == -1) {
                cp1 = clientSocket;
            } else if (this->cp2 == -1) {
                this->cp2 = clientSocket;
            }
            cout << "Client Connected" << endl;
            if (clientSocket == -1) {
                close(serverSocket);
                throw "Error on accept";
            }
        }
        startGameLoop();
        close(cp1);
        close(cp2);
        cp1 = -1;
        cp2 = -1;
    }
}

void Server::sendSign(int sign,int cp) {
    int n = write(cp,&sign,sizeof(sign));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
}

void Server::startGameLoop(){
    sendSign(1,cp1);
    sendSign(2,cp2);
    cout << "Game loop Started" << endl;
    string msg;
    int num1,num2;
    char sep;
    bool p1done =false;
    bool p2done =false;
    while(true){
        // reading the msg from player 1
        int n = read(this->cp1,&num1,sizeof(num1));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp1,&sep,sizeof(sep));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp1,&sep,sizeof(sep));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp1,&num2,sizeof(num2));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        // writing the msg from player 1
        //
        //
        //
        //
        n = write(this->cp2,&num1,sizeof(num1));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp2,&sep,sizeof(sep));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp2,&sep,sizeof(sep));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp2,&num2,sizeof(num2));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        //reading the msg from player 2
        //
        //
        //
        //
        n = read(this->cp2,&num1,sizeof(num1));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp2,&sep,sizeof(sep));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp2,&sep,sizeof(sep));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        n = read(this->cp2,&num2,sizeof(num2));
        if (n == -1){
            cout << "Error reading msg" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        // writing the msg from player 2
        n = write(this->cp1,&num1,sizeof(num1));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp1,&sep,sizeof(sep));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp1,&sep,sizeof(sep));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(this->cp1,&num2,sizeof(num2));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
    }
}

void Server::handleClient(int clientSocket) {
    int arg1,arg2;
    char op;

    while (true){
        // reading the row number
        int n = read(clientSocket,&arg1,sizeof(arg1));
        if (n == -1){
            cout << "Error reading arg1" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }
        // reading the " "
        n = read(clientSocket,&op,sizeof(op));
        // reading the column number
        n = read(clientSocket,&arg2,sizeof(arg2));

        if (n == -1){
            cout << "Error reading arg1" << endl;
            return;
        }
        if(n == 0){
            cout << "Client disconnected" << endl;
            return;
        }

        cout << "got move:" <<arg1 <<" "<< arg2 << endl;

        n = write(clientSocket,&arg1,sizeof(arg1));
        if (n== -1){
            throw "Error writing arg1 to socket";
        }
        n = write(clientSocket,&op,sizeof(op));
        if (n== -1){
            throw "Error writing op to socket";
        }
        n = write(clientSocket,&arg2,sizeof(arg2));
        if (n== -1){
            throw "Error writing arg2 to socket";
        }
    }
}

void Server::stop(){
    close(serverSocket);
}


