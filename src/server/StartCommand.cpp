//
// Created by feees on 28/12/17.
//

#include "StartCommand.h"
#include <cstdlib>

StartCommand:: StartCommand() {
}

/*
	parameters in args: [0]-clientSocket.
	calls startNewGame of server.
*/
void StartCommand::execute(vector<string> args , Server * server) {
    int clientSocket = atoi(args[0].c_str());
    server->startNewGame(args[1] , clientSocket);
}
