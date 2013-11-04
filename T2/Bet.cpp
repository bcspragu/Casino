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

Bet::Bet(){
	action = -2;
	amount = 0;
}

Bet::Bet(int betType, int amt) {
	action = betType;  // -1 fold 0-check 1-call 2-Raise
	amount = amt;
}

int Bet::getAction() {
	return action;
}

int Bet::getAmount() {
	return amount;
}

string Bet::print() {
	stringstream ss;

	switch (action) {
	case -1:
		ss << "folded.";
		break;
	case 0:
		ss << "checked.";
		break;
	case 1:
		ss << "called ";
		break;
	case 2:
		ss << "raised " << amount << ".";
		break;
	default:
		ss << "made a bet.";
		break;
	}

	return ss.str();
}
