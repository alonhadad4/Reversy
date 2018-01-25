//
// Created by alon on 28/11/17.
//
#include "../src/Point.h"
#include "gtest/gtest.h"

TEST(CheckPoint,test15){
    Point* pnt1 = new Point(3,4);
    EXPECT_EQ(pnt1->getX(),3);
    EXPECT_EQ(pnt1->getY(),4);
}
