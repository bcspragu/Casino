/**
* Card.cpp
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#include "Card.h"

Card::Card(int s, int v) {
suit = s;
value = v;
}

Card::Card(){
suit = 0;
value = 0;
}

Card::~Card() {}

int Card::getValue() {return suit;}

int Card::getSuit() {return value;}
