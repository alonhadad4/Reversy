/*
#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

using namespace std;
Client::Client(const char *serverIP, int serverPort):
            serverIP(serverIP),serverPort(serverPort),clientSocket(0){
    cout << "Client" << endl;
}

void Client::connectToServer() {
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

char* Client::sendMove(int arg1,char op, int arg2){
    int n = write(clientSocket,&arg1,sizeof(arg1));
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

char* Client::readMove(){
    int num1,num2;
    char op;
    int n = read(clientSocket,&num1,sizeof(num1));
    if (n== -1){
        throw "Error writing arg1 to socket";
    }
    n = read(clientSocket,&op,sizeof(op));
    if (n== -1){
        throw "Error writing op to socket";
    }
    n = read(clientSocket,&num2,sizeof(num2));
    if (n== -1){
        throw "Error writing arg2 to socket";
    }
    cout << num1 << op << num2<< endl;
}

