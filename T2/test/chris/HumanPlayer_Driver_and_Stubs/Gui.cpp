/**
* Gui.cpp
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/


#include "Gui.h"
#include "Bet.h"

Gui::Gui() {

}

Gui::~Gui() {

}

Bet Gui::getBetInput(int minBet) {
	return Bet(0, minBet);
}

int Gui::getAmount() {
	return 5;
}
