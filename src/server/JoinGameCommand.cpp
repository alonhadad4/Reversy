//
// Created by feees on 28/12/17.
//

#include "JoinGameCommand.h"
#include <cstdlib>
#include "Server.h"
JoinGameCommand:: JoinGameCommand() {

}

/*
	parameters in args: [0]-clientSocket, [1]- name of game to join
	calls joinGame of server.
*/
void JoinGameCommand::execute(vector<string> args , Server * server) {
    int clientSocket = atoi(args[0].c_str());
    server->joinGame(args[1],clientSocket);
}
