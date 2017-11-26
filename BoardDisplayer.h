/*
 * BoardDisplayer.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jonathan
 */

#ifndef BOARDDISPLAYER_H_
#define BOARDDISPLAYER_H_
#include "Board.h"

class BoardDisplayer {
public:
	BoardDisplayer(Board& b) {
		this->board_ = b;
	}
	// virtual ~BoardDisplayer() = 0;
	virtual void displayBoard(Board& b) = 0;
protected:
	Board board_;
};

#endif /* BOARDDISPLAYER_H_ */
