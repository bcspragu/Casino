/**
 * HumanPlayer.cpp
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#include "HumanPlayer.h"
#include <iostream>

using namespace std;

HumanPlayer::HumanPlayer(int num) {
	playerNum = num;
}

Bet HumanPlayer::makeBet(SmallDeck comm, int minBet) {
	Bet b;
	do {
		b = game.getGui().getBetInput();
	} while (b.getAmount() < minBet || b.getAmount() > money);
	money -= b.getAmount();
	return b;
}
