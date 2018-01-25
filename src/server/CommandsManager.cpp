//
// Created by feees on 28/12/17.
//

#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinGameCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"


CommandsManager::CommandsManager() {
    this->commandsMap["start"] = new StartCommand();
    this->commandsMap["list_games"] = new ListGamesCommand();
    this->commandsMap["join"] = new JoinGameCommand();
    this->commandsMap["play"] = new PlayCommand();
    this->commandsMap["close"] = new CloseCommand();

}

void CommandsManager::executeCommand(string command, vector<string> args, Server * server) {
    Command *commandObj = this->commandsMap[command];
    commandObj->execute(args, server);
}

CommandsManager::~CommandsManager(){
    map<string, Command *>::iterator it;
    for (it = this->commandsMap.begin(); it != this->commandsMap.end(); it++) {
        delete it->second;
    }
}
