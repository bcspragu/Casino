#pragma once
#include "Frame.h"
using namespace std;

class CardD1
{
private:
	int suit;
	int rank;
	bool discard;
	Frame frame;
public:
	CardD1(int s, int r);
	int getRank();
	int getSuit();
	int getNumber();
	void setDiscarded(bool d);
	bool isDiscarded();
	void setFrame(int x, int y);
	Frame getFrame();
	~CardD1(void);
};

