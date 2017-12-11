/*
 * Point.h
 *
 *  Created on: Nov 13, 2017
 *      Author: jonathan
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point();
	Point(int x , int y);
	int getX();
	int getY();
	virtual ~Point();
private:
	int x_;
	int y_;
};

#endif /* POINT_H_ */
