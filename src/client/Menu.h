//
// Created by alon on 10/12/17.
//

#ifndef UNTITLED5_MENU_H
#define UNTITLED5_MENU_H
#include "GameRules.h"
#include "Player.h"
#include "Board.h"
#include "BoardDisplayer.h"
#include "Point.h"
#include <vector>
class Menu {
public:
    Menu();
	/**
	* the function initiates a human vs. AI game.
	*/
    void humanVsAiGame();
	/**
	* the function initiates a human vs. human game.
	*/
    void humanVshumanLocalGame();
	/**
	* the function initiates a human vs. human via server game.
	*/
    void humanVshumanServerGame();
    virtual ~Menu();
	/**
	* the function prints the menu to the console.
	*/
    void printMenu();
	/**
	* the function reads a number of option from the console.
	* then, it calls the right function according to that option.
	*/
    void chooseOption();
private:
    GameRules * rules_;
    Board * b_;
    BoardDisplayer * disp_;
};
#endif //UNTITLED5_MENU_H
