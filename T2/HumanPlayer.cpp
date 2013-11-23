/**
 * HumanPlayer.cpp
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#include "HumanPlayer.h"

#include <iostream>

#include "Bet.h"
#include "Game.h"
#include "Gui.h"
#include "Player.h"
#include "SmallDeck.h"

using namespace std;

HumanPlayer::HumanPlayer(int num, Gui gameGui, int startMoney) {
	money = startMoney;
	gui = gameGui;
	playerNum = num;
}

Bet HumanPlayer::makeBet(SmallDeck comm, int minBet, GameState state) {
	Bet b;
	do {
		b = gui.getBetInput();
	} while (b.getAmount() > money);
	money -= b.getAmount();
	return b;
}
