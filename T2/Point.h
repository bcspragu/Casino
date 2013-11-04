/*
 * Point.h
 * Author: Eli Siskind
 *
 * Description: Holds coordinate locations for layout class
 *
 */

#ifndef H_POINT
#define H_POINT

#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Point
{
public:
	Point();
	~Point();
	int getX(){return xCoord;}
	int getY(){return yCoord;}
	void set(int x, int y);
	string print();
private:
	int xCoord;
	int yCoord;
};

#endif
