//
// Created by alon on 28/11/17.
//

#include "gtest/gtest.h"
#include <iostream>
using namespace std;
#include "../src/Board.h"

TEST(boardCheckCell, Test10) {
    Board* b= new Board();
    EXPECT_EQ(b->getCell(3,4),'X');
    EXPECT_EQ(b->getCell(4,3),'X');
    EXPECT_EQ(b->getCell(3,3),'O');
    EXPECT_EQ(b->getCell(4,4),'O');
}
//Check the sizes of the board
TEST(BoardCheckSize, Test11) {
    Board* b= new Board();
    EXPECT_EQ(b->getLength(),8);
    EXPECT_EQ(b->getWidth(),8);
}
//Check if the initial board is not full
TEST(BoardIsNotFull, Test12) {
    Board* b= new Board();
    EXPECT_EQ(b->isNotFull(),true);
}
//Check if a full board apears as full
TEST(BoardIsFull, Test14) {
    Board* b= new Board();
    for(int i = 0;i < 8 ;i++){
        for(int j = 0; j < 8;j++){
           b->setCell(i,j,'X');
        }
    }
    EXPECT_EQ(b->isNotFull(),false);
}

