//
// Created by feees on 28/12/17.
//

#ifndef UNTITLED5_JOINGAMECOMMAND_H
#define UNTITLED5_JOINGAMECOMMAND_H
#include "Command.h"



class JoinGameCommand: public Command {
public:
    JoinGameCommand(); //empty constructor
    ~JoinGameCommand(); //empty destructor
    void execute(vector<string> args , Server * server);
};

#endif //UNTITLED5_JOINGAMECOMMAND_H
