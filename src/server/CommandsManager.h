//
// Created by feees on 28/12/17.
//

#ifndef UNTITLED5_COMMANDSMANAGER_H
#define UNTITLED5_COMMANDSMANAGER_H
#include <map>
#include "Command.h"



class CommandsManager {
public:
	/**
	* initializes all commands to map member of commands.
	*/
    CommandsManager();
	/**
	* deletes all commands from map.
	*/
    ~CommandsManager();
	/**
	sending the command object to execute with args and server.	
	*/
    void executeCommand(string command, vector<string> args , Server * server);
private:
    map<string,Command *> commandsMap;
};


#endif //UNTITLED5_COMMANDSMANAGER_H
