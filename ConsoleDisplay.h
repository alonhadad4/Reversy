/*
 * ConsoleDisplay.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jonathan
 */

#ifndef CONSOLEDISPLAY_H_
#define CONSOLEDISPLAY_H_
#include "Board.h"
#include "BoardDisplayer.h"

class ConsoleDisplay : public BoardDisplayer {
public:
	ConsoleDisplay(Board * b);
	virtual ~ConsoleDisplay();
	virtual void displayBoard(Board * b);
	virtual ConsoleDisplay& operator= (const ConsoleDisplay& disp);
private:
};

#endif /* CONSOLEDISPLAY_H_ */
