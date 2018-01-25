//
// Created by feees on 28/12/17.
//

#ifndef UNTITLED5_CLOSECOMMAND_H
#define UNTITLED5_CLOSECOMMAND_H

#include "Command.h"
#include "Server.h"


class CloseCommand: public Command {
public:
    CloseCommand(); //empty constructor
    ~CloseCommand(); // empty destructor
	/*
	calls server function of close game in args[1]
	*/
    void execute(vector<string> args , Server * server);
};


#endif //UNTITLED5_CLOSECOMMAND_H
