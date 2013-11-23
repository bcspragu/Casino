/**
 * Bet.h
 *
 *  Created on: Oct 20, 2013
 *      Author: Kyle Despins
 */

#ifndef BET_H
#define BET_H

#include <string>

using namespace std;

enum BetAction { INVALID, FOLD, CALL, RAISE };

class Bet
{
	private:
	BetAction action;
	int amount;

	public:
	Bet();
	Bet(BetAction BetType, int Amt);
	string print();
	BetAction getAction();
	int getAmount();
};

#endif
