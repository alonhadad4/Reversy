/*
 * board.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jonathan
 */

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board(int l = 8 , int w = 8);
	Board(const Board &b);
	char getCell(int i , int j);
	void setCell(int i , int j , char c);
	/**
	 * frees memory of arr member.
	 */
	virtual ~Board();
	int getLength();
	int getWidth();
	/**
	 * returns true if the board isn't full.
	 */
	bool isNotFull();
	virtual Board& operator= (const Board& b);
private:
	int length_;
	int width_;
	char ** arr_;
};

#endif /* BOARD_H_ */
