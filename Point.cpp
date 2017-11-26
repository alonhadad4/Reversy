/*
 * Point.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: jonathan
 */

#include "Point.h"

Point::Point() {
	// TODO Auto-generated constructor stub
	this->x_ = 0;
	this->y_ = 0;
}


Point:: Point(int x , int y) {
	this->x_ = x;
	this->y_ = y;
}

int Point:: getX() {
	return this->x_;
}

int Point:: getY() {
	return this->y_;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

