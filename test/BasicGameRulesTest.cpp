//
// Created by ori on 23/11/17.
//
#include "gtest/gtest.h"
#include <iostream>
using namespace std;
#include "../src/Board.h"
#include "../src/Player.h"
#include "../src/HumanConsolePlayer.h"
#include "../src/BasicGameRules.h"

//are the following moves are legal
//reversing up
TEST(legalUp, Test2) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    GameRules * rules = new BasicGameRules();
    EXPECT_EQ(rules->isMoveLegal(p1,2,3,* b),true);
}
//reversing left
TEST(legalLeft, Test3) {
    Board* b= new Board();
    Player * p1 = new HumanConsolePlayer('X');
    GameRules * rules = new BasicGameRules();
    EXPECT_EQ(rules->isMoveLegal(p1,3,2,* b),true);
}
//reversing right
TEST(legelRight, Test4) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    EXPECT_EQ(rules->isMoveLegal(p1,4,5,* b),true);
}
//reversing down
TEST(legelDown, Test5) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    EXPECT_EQ(rules->isMoveLegal(p1,5,4,* b),true);
}
//reversing up left
TEST(legelUpLeft, Test6) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    b->setCell(3, 3, 'X');
    EXPECT_EQ(rules->isMoveLegal(p2,2,2,* b),true);
}
//reversing down right
TEST(legelDownRight, Test7) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    b->setCell( 4 , 4, 'X');
    EXPECT_EQ(rules->isMoveLegal(p2,5,5,* b),true);
}
//reversing up right
TEST(legelUpRight, Test8) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    b->setCell( 3 , 4, 'O');
    EXPECT_EQ(rules->isMoveLegal(p1,2,5,* b),true);
}
//reversing down left
TEST(legelDownLeft, Test9) {
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    b->setCell(4 , 3, 'O');
    EXPECT_EQ(rules->isMoveLegal(p1,5,2,* b),true);
}
TEST(checkPossibleMoves,test16){
    Board* b = new Board();
    Player * p1 = new HumanConsolePlayer('X');
    Player * p2 = new HumanConsolePlayer('O');
    GameRules * rules = new BasicGameRules();
    GamePlay * game = new GamePlay(rules , b , p1 , p2);
    vector <Point> vp = rules->possibleMoves(p1,* b);
    EXPECT_EQ(vp[0].getX(),2);
    EXPECT_EQ(vp[0].getY(),3);
    EXPECT_EQ(vp[1].getX(),3);
    EXPECT_EQ(vp[1].getY(),2);
    EXPECT_EQ(vp[2].getX(),4);
    EXPECT_EQ(vp[2].getY(),5);
    EXPECT_EQ(vp[3].getX(),5);
    EXPECT_EQ(vp[3].getY(),4);
}


