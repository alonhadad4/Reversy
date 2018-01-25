//
// Created by feees on 28/12/17.
//
#ifndef UNTITLED5_LISTGAMESCOMMAND_H
#define UNTITLED5_LISTGAMESCOMMAND_H
#include "Command.h"



class ListGamesCommand: public Command {
public:
    ListGamesCommand(); //empty constructor
    virtual ~ListGamesCommand(); //empty destructor
    void execute(vector<string> args , Server * server);
};

#endif
