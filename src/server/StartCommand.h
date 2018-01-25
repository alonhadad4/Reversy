//
// Created by feees on 28/12/17.
//

#ifndef UNTITLED5_STARTCOMMAND_H
#define UNTITLED5_STARTCOMMAND_H
#include "Command.h"
#include "Server.h"


class StartCommand: public Command {
public:
    StartCommand(); //empty constructor
    ~StartCommand(); //empty destructor
    void execute(vector<string> args , Server * server);
};


#endif //UNTITLED5_STARTCOMMAND_H
