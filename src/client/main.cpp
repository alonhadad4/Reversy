/*
 * main.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: jonathan
 */

#include "Menu.h"

using namespace std;

int main(){
    Menu * gameMenu = new Menu();
    gameMenu->printMenu();
    gameMenu->chooseOption();
    delete gameMenu;
}
