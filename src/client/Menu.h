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
    void humanVsAiGame();
    void humanVshumanLocalGame();
    void humanVshumanServerGame();
    virtual ~Menu();
    void printMenu();
    void chooseOption();
private:
    GameRules * rules_;
    Board * b_;
    BoardDisplayer * disp_;
};
#endif //UNTITLED5_MENU_H