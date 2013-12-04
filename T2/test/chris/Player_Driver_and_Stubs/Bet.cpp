/**
* Bet.cpp
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#include "Bet.h" 

Bet::Bet(int betType, int amt) {
	action = betType;  // -1 fold 0-check 1-call 2-Raise
	amount = amt;
}

