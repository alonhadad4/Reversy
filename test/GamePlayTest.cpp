//
// Created by alon on 28/11/17.
//

using namespace std;
#include "../src/Board.h"
#include "../src/Player.h"
#include "../src/HumanConsolePlayer.h"
#include "../src/BasicGameRules.h"
#include "gtest/gtest.h"

//Checking the Possible moves if p1 started the game
TEST(CheckPossibleMovesp1, Test12) {
    Board* b= new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    GamePlay * game = new GamePlay(rules ,b , p1 , p2);
    vector <Point> vp = game->getPossibleMoves(p1);
    EXPECT_EQ(vp[0].getX(),2);
    EXPECT_EQ(vp[0].getY(),3);
    EXPECT_EQ(vp[1].getX(),3);
    EXPECT_EQ(vp[1].getY(),2);
    EXPECT_EQ(vp[2].getX(),4);
    EXPECT_EQ(vp[2].getY(),5);
    EXPECT_EQ(vp[3].getX(),5);
    EXPECT_EQ(vp[3].getY(),4);
}
//Checking the Possible moves if p2 started the game
TEST(CheckPossibleMovesp2, Test13) {
    Board* b= new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    GamePlay * game = new GamePlay(rules , b , p1 , p2);
    vector <Point> vp = game->getPossibleMoves(p2);
    EXPECT_EQ(vp[0].getX(),2);
    EXPECT_EQ(vp[0].getY(),4);
    EXPECT_EQ(vp[1].getX(),3);
    EXPECT_EQ(vp[1].getY(),5);
    EXPECT_EQ(vp[2].getX(),4);
    EXPECT_EQ(vp[2].getY(),2);
    EXPECT_EQ(vp[3].getX(),5);
    EXPECT_EQ(vp[3].getY(),3);
}