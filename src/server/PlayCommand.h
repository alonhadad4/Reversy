//
// Created by feees on 28/12/17.
//

#include "Command.h"
#include "Server.h"


class PlayCommand: public Command {
public:
    PlayCommand(); //empty constructor
    ~PlayCommand(); //empty destructor
    void execute(vector<string> args , Server * server);
};
