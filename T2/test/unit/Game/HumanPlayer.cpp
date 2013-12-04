/**
 * HumanPlayer.cpp
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(int num){
	playerNum = num;
}

Bet HumanPlayer::makeBet(SmallDeck d, int minBet, int state) {
	money -= minBet;
	return Bet (1, minBet);
}
