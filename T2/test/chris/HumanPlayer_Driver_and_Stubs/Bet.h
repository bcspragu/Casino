/**
* Bet.h
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#ifndef BET_H
#define BET_H

class Bet {
private:
	int action;
	int amount;

public:
	Bet(int BetType, int Amt);
	int getAmount();
	Bet();
};

#endif
