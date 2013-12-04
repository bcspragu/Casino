#include <string>
#include <sstream>
#include <cstdlib>

#include "Point.h"



using namespace std;

Point::Point()
{
	xCoord = -1;
	yCoord = -1;
}

Point::~Point()
{

}

void Point::set(int x, int y)
{
	xCoord = x;
	yCoord = y;
}

string Point::print()
{
	stringstream ss;
	ss << "x: " << xCoord << " y: " << yCoord;
	return ss.str();
}
