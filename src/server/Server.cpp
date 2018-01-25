#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <cstdlib>
#include <sstream>
#include "ThreadPool.h"

struct ThreadArgs{
    Server * s1;
    int clientSocket;
};
struct newGameThread{
    int  cs1;
    int cs2;
};

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define THREADS_NUM 5

int index1 = 0;
Server::Server(int port):port(port),serverSocket(0) {
    cout << "Server" << endl;
    cm = new CommandsManager();
}

/**
* when cliens disconnect, the function will wait for next clients to connect.
*/
void Server::start(){
    threadPool= new ThreadPool(THREADS_NUM);
    this->threadPool->addTask(new Task(listeningLoop,(void *)this));
    string command;
    getline (cin,command);
    if(command.compare("exit")){
        this->stop();
    }
}



void Server:: activateCm (string str,vector<string> args){
    cm->executeCommand(str,args , this);
}

void * Server::listeningLoop(void * arg){
    Server * server = (Server *)arg;
    server->serverSocket = socket(AF_INET,SOCK_STREAM, 0);
    if(server->serverSocket == -1) {
        throw "Error opening socket";
    }

    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress,sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(server->port);
    if (bind(server->serverSocket,(struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    listen(server->serverSocket, MAX_CONNECTED_CLIENTS);

    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);
    cout << "Waiting for client connections..." << endl;
    while(true) {
        ThreadArgs * ptr = new ThreadArgs;
        int clientSocket = accept(server->serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        server->clients.push_back(clientSocket);
        cout << "Client Connected" << endl;
        if (clientSocket == -1) {
            close(server->serverSocket);
            throw "Error on accept";
        }
        ptr->clientSocket = server->clients[index1];
        ptr->s1 = server;
        index1 ++;
        /*pthread_t threads[1];*/
        cout << "new thread created" << endl;
        server->threadPool->addTask(new Task(clientLoop,(void *)ptr));
        /*int rc = pthread_create(&threads[0] , NULL, clientLoop , (void *)ptr);*/
    }
}

// the thread each user has on the server
void * Server::clientLoop(void * ta){
    // while the user is connected
    while (true){
        std::string command, income;
        int num1;
        // read a number from the user: number of chars
        int n = read(((ThreadArgs *)ta)->clientSocket,&num1,sizeof(num1));
        if (n == -1){
            cout << "Error reading msg" << endl;
        }
        // read the message from the user
        char buffer[num1];
        bzero((char*) &buffer, sizeof(buffer));
        n = read(((ThreadArgs *)ta)->clientSocket,&buffer,sizeof(buffer));
        if (n == -1){
            cout << "Error reading msg" << endl;
        }
        //seperate the string
        std::vector<std::string> result;

        std::istringstream iss(buffer);
        for(std::string word; iss >> word; )
            result.push_back(word);
        vector <string> vc;
        vc.push_back(static_cast<ostringstream*>(&(ostringstream()<< (((ThreadArgs *)ta)->clientSocket)))->str());
        // vc[0] = socket
        // if not list_games: vc[1] = name or parameters of move
        // if play: vc [2] = x , vc [3] = y
        //check if  the command is list games, if not set vc[0] to be the name
        // vc[0] name
        if(result[0].compare("play") == 0){
            vc.push_back(result[1]); // x
            vc.push_back(result[2]); // y
        } else if (result[0].compare("list_games")){ //is not
            vc.push_back(result[1]); //name (of game) or moves
        }

        // conerting the client socket into string, to put it in vector of args

        ((ThreadArgs *)ta)->s1->activateCm(result[0] , vc);
        if(result[0].compare("list_games") == 0 || result[0].compare("close") == 0){
            break;
        }
    }

}

void Server::sendSign(int sign,int cp) {
    int n = write(cp,&sign,sizeof(sign));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
}

void Server::stop(){
    this->threadPool->terminate();
    delete this->threadPool;

    for(int i =0; i< clients.size(); i++){
        int logout = -1001;
        int n = write(clients[i],&logout,sizeof(logout));
        if (n == -1) {
            throw "Error writing sign to socket";
        }
    }
    close(serverSocket);
}

void *Server::gameLoop(void *t) {
    // set a new game send the users a message the game has started and then the signs of the players
    int num1;
    int cs1 = ((newGameThread *)t)->cs1;
    int cs2 = ((newGameThread *)t)->cs2;
    int sign = 1,started = 1001;
    int n = write(cs1,&started,sizeof(started));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
    n = write(cs1,&sign,sizeof(sign));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
    sign = 2;
    n = write(cs2,&started,sizeof(started));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
    n = write(cs2,&sign,sizeof(sign));
    if (n== -1) {
        throw "Error writing sign to socket";
    }
}
//a function that starts new games and adds them to pending games
void Server:: startNewGame(string name, int clientSocket) {
    //check if the game exists and if so send error
    if (this->pendingGames.find(name) != this->pendingGames.end()){
        int numError = -1;
        int n = write(clientSocket,&numError,sizeof(numError));
        if (n== -1) {
            throw "Error writing sign to socket";
        }
        return;
    }
    pendingGames[name] = clientSocket;
}
// joining a pending game
void Server::joinGame(string name , int clientSocket){
    //check if the game has been started and is pending for a second player
        if(this->pendingGames.find(name) == this->pendingGames.end()){
            //game doesnt exist
            int num1 = -5000;
            int n = write(clientSocket,&num1,sizeof(num1));
            if (n== -1) {
                throw "Error writing sign to socket";
            }
        } else {
            // seeting gnew thread
            newGameThread * ptr = new newGameThread;
            ptr->cs1 = (int)(this->pendingGames[name]);
            ptr->cs2 = clientSocket;
            // add to pvplist in order to cehck client sockets
            pvplist[name].push_back(ptr->cs1);
            pvplist[name].push_back(ptr->cs2);
            pthread_t threadsJoin[1];
            this->listOfGames[name] = &threadsJoin[0];
            pendingGames.erase(name);
           // pthread_mutex_t mutexGame;
           // pthread_mutex_lock(&mutexGame);
            cout << "new thread created" << endl;
            this->threadPool->addTask(new Task(gameLoop,(void *)ptr));
            //int rc = pthread_create(&threadsJoin[0] , NULL, gameLoop , (void *)ptr);
          //  pthread_mutex_unlock(&mutexGame);
        }
    }

void Server::showGameList(int clientSocket) {
    // using vector of strings

    //tell user the list is done (number of games)
    int size = pendingGames.size();
    int n = write(clientSocket, &size, sizeof(int));
    if (n == -1) {
        throw "Error writing sign to socket";
    }
    //send the messages one by one
    for (std::map<string,int>::iterator it = pendingGames.begin(); it != pendingGames.end(); ++it) {

        int len = strlen((it->first).c_str())+1;
        n = write(clientSocket,&len,sizeof(len));
        if (n== -1){
            throw "Error writing msg1 to socket";
        }

        char m[len];
        strcpy(m , (it->first).c_str());
        m[len-1] = '\0';
        n = write(clientSocket,&m,sizeof(m));
        if (n== -1){
            throw "Error writing msg1 to socket";
        }

    }
    //TBD Close client socket from server side
}
// close the game sent
void Server::closeGame(string name){
    // loop over all connected players
    for (std::map<string,vector<int> >::iterator it = pvplist.begin(); it != pvplist.end(); ++it){
        if (it->first.compare(name) == 0){
            int numError = -5;
            char ch = ' ';
            int n = write(it->second[0], &numError, sizeof(numError));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
             n = write(it->second[0], &ch, sizeof(ch));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
            n = write(it->second[0], &numError, sizeof(numError));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
            n = write(it->second[1], &numError, sizeof(numError));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
            n = write(it->second[1], &ch, sizeof(ch));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
            n = write(it->second[1], &numError, sizeof(numError));
            if (n == -1) {
                throw "Error writing sign to socket";
            }
        }
    }
    // remove frmo pending
    if (this->pendingGames.find(name) != this->pendingGames.end()){
        int numError = -1;
        int n = write(this->pendingGames[name], &numError, sizeof(numError));
        if (n == -1) {
            throw "Error writing sign to socket";
        }
    }
    try {
        if (*(listOfGames.at(name)) != NULL)
            pthread_cancel(* listOfGames[name]);
    }
    catch (exception e){

    }
    pendingGames.erase(name);
    pvplist.erase(name);
    listOfGames.erase(name);
}
// make a new move inside the game
void Server::executeMove(int i, int j, int clientSocket) {
    char ch = ' ';
    i = i - 1;
    j = j - 1;
    for (std::map<string,vector<int> >::iterator it = pvplist.begin(); it != pvplist.end(); ++it) {
        //send to player 1
        if(clientSocket == it->second[0]){
            int opSocket = it->second[1];
            int n = write(opSocket,&i,sizeof(i));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
            n = write(opSocket,&ch,sizeof(ch));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
            n = write(opSocket,&j,sizeof(j));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
        }
            //send to player 2
        else if(clientSocket == it->second[1]){
            int opSocket = it->second[0];
            int n = write(opSocket,&i,sizeof(i));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
            n = write(opSocket,&ch,sizeof(ch));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
            n = write(opSocket,&j,sizeof(j));
            if (n== -1){
                throw "Error writing msg1 to socket";
            }
        }
    }
}

