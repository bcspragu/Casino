#ifndef T2POKER_H_
#define T2POKER_H_

#include "T2Display.h"
#include "Game.h"
#include "Layout.h"
#include "../GameObject.h"

#include <cstdlib>
#include <iostream>
extern T2Display T2GameDisplay;
class T2Poker{
public:
	int runGame(GameObject*);
};

#endif