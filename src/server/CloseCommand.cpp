//
// Created by feees on 28/12/17.
//

#include "CloseCommand.h"

CloseCommand::CloseCommand(){

}

void CloseCommand::execute(vector<string> args , Server * server) {
    string name = args[1];
    server->closeGame(name);
}