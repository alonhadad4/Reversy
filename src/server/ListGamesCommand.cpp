//
// Created by feees on 28/12/17.
//

#include "ListGamesCommand.h"
#include "Server.h"
#include <string>
#include <cstdlib>

ListGamesCommand::ListGamesCommand(){

}

ListGamesCommand::~ListGamesCommand(){

}


/*
	parameters in args: [0]-clientSocket.
	calls showGameList of server.
*/
void ListGamesCommand::execute(vector<string> args , Server * server) {
    int clientSocket = atoi(args[0].c_str());
    server->showGameList(clientSocket);
}
