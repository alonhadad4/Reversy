//
// Created by alon on 10/12/17.
//
#include "GamePlay.h"
#include <fstream>
#include <string.h>
#include "ConsoleDisplay.h"
#include "Menu.h"
#include "RemotePlayer.h"
#include <iostream>
#include "Board.h"
#include "BoardDisplayer.h"
#include "ConsoleDisplay.h"
#include "Player.h"
#include "HumanConsolePlayer.h"
#include "AIPlayer.h"
#include "GameRules.h"
#include "BasicGameRules.h"
#include "RemotePlayer.h"
#include "VirtualPlayer.h"
#include <sstream>
#include <stdlib.h>
#define boardSize 8
using namespace std;


Menu::Menu() {
    this->rules_ = new BasicGameRules();
    this->b_ = new Board(boardSize,boardSize);
    this->disp_ = new ConsoleDisplay(b_);
}

/**
* when game ends, it frees the memory allocated.
*/
void Menu::humanVshumanLocalGame(){
    Player * p1_ = new HumanConsolePlayer('X');
    Player * p2_ = new HumanConsolePlayer('O');
    GamePlay * game = new GamePlay(this->rules_ , this->b_ , p1_ , p2_);
    game->playGame();
    delete p1_;
    delete p2_;
    delete game;
}
/**
* when game ends, it frees the memory allocated.
*/
void Menu::humanVsAiGame () {
    Player * p1_ = new AIPlayer('X');
    Player * p2_ = new HumanConsolePlayer('O');
    GamePlay * game = new GamePlay(this->rules_ , this->b_ , p1_ , p2_);
    game->playGame();
    delete p1_;
    delete p2_;
    delete game;
}

/**
* the function reads the IP and port number from "Client.txt" config. file.
* then it initializes a remote player with those, and activates the game.
* when game ends, it frees the memory allocated.
*/
void Menu::humanVshumanServerGame() {
    while (true)
    {
        ifstream file;
        file.open("Client.txt" , ios::in);
        if (!file.is_open()) {
            //return;
            cout << "error";
        }
        vector<string> strings;
        string line , IP , port;
        getline(file , IP);
        getline(file , port);
        int portNum = atoi(port.c_str());
        // port num is int of the port number
        // IP is string of the IP
        file.close();
        Player * p1_ = new RemotePlayer(IP.c_str(),portNum);
        try{
            (dynamic_cast<RemotePlayer *>(p1_))->connectToServer();
        } catch(const char *msg) {
            cout << "Failed to connect to server .reason- " << msg << endl;
            return;
        }
        string command;
        do {
            string command = (dynamic_cast<RemotePlayer *>(p1_))->initiateTalk();
        } while(command.compare("start over") == 0);


        Player * p2_;

        // int c = (dynamic_cast<RemotePlayer *>(p1_))->readNum(); // getting number of the player
        char op = 'O';
        if (p1_->getPlayerChar() == 'O') {
            op = 'X';
        }
        p2_ = new VirtualPlayer(IP.c_str(), portNum, op);
        (dynamic_cast<VirtualPlayer *>(p2_))->setClientSocket((dynamic_cast<RemotePlayer *>(p1_))->getClientSocket());
        GamePlay * game = new GamePlay(this->rules_ , this->b_ , p1_ , p2_);
        if (op == 'X') {
            game->swapPlayers();
        }

        game->playGame();
        delete p1_;
        delete p2_;
        delete game;
        delete this->b_;
        this->b_ = new Board(boardSize,boardSize);
    }
}

void Menu::printMenu() {
    cout << "Choose an opponent type:"<< endl;
    cout << "1: A human local Player."<< endl;
    cout << "2: An AI player."<< endl;
    cout << "3: A remote player."<< endl;
}

void Menu::chooseOption() {
    int option;
    cin >> option;
    cin.ignore();
    switch (option){
        case 1:
            this->humanVshumanLocalGame();
            break;
        case 2:
            this->humanVsAiGame();
            break;
        case 3:
            this->humanVshumanServerGame();
            break;
    }
}

Menu::~Menu() {
    delete this->b_;
    delete this->disp_;
    delete this->rules_;
}

