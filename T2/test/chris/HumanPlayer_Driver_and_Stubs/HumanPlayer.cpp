/**
 * HumanPlayer.cpp
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#include "HumanPlayer.h"
#include "Game.h"
#include "Gui.h"
#include "SmallDeck.h"
#include <iostream>

extern Game game;

HumanPlayer::HumanPlayer(int num) {
	playerNum = num;
}

Bet HumanPlayer::makeBet(SmallDeck comm, int minBet) {
	Bet b;
	do {
		b = game.getGui().getBetInput(minBet);
	} while (b.getAmount() > money);
	money -= b.getAmount();
	return b;
}
