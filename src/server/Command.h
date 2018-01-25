//
// Created by feees on 28/12/17.
//

#ifndef UNTITLED5_COMMAND_H
#define UNTITLED5_COMMAND_H

#include <vector>
#include <string>
class Server;
using namespace std;


class Command {

public:
	/*
	the function executes with args given in vector, calling function from server.
	*/
    virtual void execute(vector<string> args , Server * server) = 0;
};


#endif //UNTITLED5_COMMAND_H
