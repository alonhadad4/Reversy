/*
 * ConsoleDisplay.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jonathan
 */

#include "ConsoleDisplay.h"
#include <iostream>
using namespace std;

ConsoleDisplay:: ConsoleDisplay(Board  * b) : BoardDisplayer (b){
	// TODO Auto-generated constructor stub
}

ConsoleDisplay&  ConsoleDisplay:: operator= (const ConsoleDisplay& disp) {
	return *this;
}

/**
 * function creates a temporary array for convenience.
 * it uses the array to write the numbers of the rows and columns.
 * it prints the board on the console.
 */
void ConsoleDisplay::displayBoard(Board * b) {
	char * tempArr = new char [b->getLength()];
	for (int i = 1; i <= b->getLength(); i++) {
			tempArr[i - 1] = 48 + i;
			}
		cout << " | ";
		for (int i = 0; i < b->getLength(); i++) {
			cout << tempArr[i] << " | ";
		}
		for (int i = 0; i < b->getLength(); i++) {
			cout << " \n" << ".................................." << "\n";
			cout << tempArr[i];
				for (int j = 0; j < b->getLength(); j++) {
					cout <<  "| " << b->getCell(i , j) << " ";
				}
			cout << "|";
		}
		cout << " \n" << ".................................." << "\n";
		delete tempArr;
}

ConsoleDisplay::~ConsoleDisplay() {
	// TODO Auto-generated destructor stub
}

