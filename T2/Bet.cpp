/**
 * Bet.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: Kyle Despins
 */

#include "Bet.h" 

#include <string>
#include <sstream>

using namespace std;

/*
 * Default constructor
 */
Bet::Bet() {
	action = INVALID;
	amount = 0;
}

/*
 * Constructor
 */
Bet::Bet(BetAction betAction, int betAmount) {
	action = betAction;
	amount = betAmount;
}

/*
 * Returns the bet action
 */
BetAction Bet::getAction() {
	return action;
}

/*
 * Returns the amount bet
 */
int Bet::getAmount() {
	return amount;
}

/*
 * Returns a string describing the bet
 */
string Bet::print() {
	stringstream ss;

	switch (action) {
	case FOLD:
		ss << "folded.";
		break;
	case CALL:
		if (amount == 0)
			ss << "checked.";
		else
			ss << "called.";
		break;
	case RAISE:
		ss << "raised " << amount << ".";
		break;
	default:
		ss << "made a bet.";
		break;
	}

	return ss.str();
}
