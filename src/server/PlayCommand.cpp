//
// Created by feees on 28/12/17.
//

#include "PlayCommand.h"
#include <cstdlib>

PlayCommand:: PlayCommand() {

}

/*
	parameters in args: [0]-clientSocket , [1]- i of move, [2]- j of move
	calls executeMove of server.
*/
void PlayCommand::execute(vector<string> args , Server * server) {
    // translating args to ints
    int i = atoi(args[1].c_str());
    int j = atoi(args[2].c_str());
    int clientSocket = atoi(args[0].c_str());
    server->executeMove(i , j, clientSocket);
}
