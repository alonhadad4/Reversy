/*
 * board.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jonathan
 */

#include "Board.h"

#include <iostream>
using namespace std;

Board::Board(int l , int w) {
	this->length_ = l;
	this->width_ = w;
	this->arr_= new char * [l];
	for (int i = 0; i < l; i ++) {
		this->arr_[i] = new char [w];
		for (int j = 0; j < w; j ++) {
			this->arr_[i][j] = ' ';
		}
	}
	this->arr_[3][3] = 'O';
	this->arr_[4][4] = 'O';
	this->arr_[3][4] = 'X';
	this->arr_[4][3] = 'X';
}

Board:: Board(const Board &b) {
	this->length_ = b.length_;
	this->width_ = b.width_;
	this->arr_= new char * [b.length_];
	for (int i = 0; i < b.length_; i ++) {
		this->arr_[i] = new char [b.width_];
		for (int j = 0; j < b.width_; j ++) {
			this->arr_[i][j] = b.arr_[i][j];
		}
	}
}

Board& Board:: operator= (const Board& b) {
	if (this != &b) {
		for (int i = 0; i < this->getLength(); i ++) {
			delete this->arr_[i];
		}
		delete this->arr_;
		this->arr_= new char * [b.length_];
		for (int i = 0; i < this->getLength(); i ++) {
			this->arr_[i] = new char [b.width_];
			for (int j = 0; j < b.width_; j ++) {
				this->arr_[i][j] = b.arr_[i][j];
			}
		}
	}
	return *this;
}

bool Board:: isNotFull() {
	for (int i = 0; i < this->getLength(); i ++) {
		for (int j = 0; j < this->getWidth(); j ++) {
			if (this->arr_[i][j] == ' ') {
				return true;
			}
		}
	}
	return false;
}

char Board::getCell (int i ,  int j) {
	return this->arr_[i][j];
}

/**
 * before setting a cell, it verifies that parameters of i,j are inside array.
 */
void Board:: setCell(int i , int j , char c) {
	if (i >= 0 and i < this->getLength() and j >= 0 and j< this->getWidth() ) {
		this->arr_[i][j] = c;
	}
}

int Board:: getLength() {
	return this->length_;
}

int Board:: getWidth() {
	return this->width_;
}

Board::~Board() {
	// TODO Auto-generated destructor stub
	for (int i = 0; i < this->length_; i ++) {
		delete [] this->arr_[i];
	}
	delete [] this->arr_;
}

