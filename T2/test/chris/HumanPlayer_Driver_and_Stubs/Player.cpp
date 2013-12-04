/**
 * Player.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "Player.h"

Player::Player() {
		folded = false;
		money = 500;
}

Player::Player(int num) {
	playerNum = num;
	folded = false;
	money = 500;
}

Player::~Player() {

}

Bet Player::makeBet(SmallDeck comm, int minBet) {
	Bet bet(1, 50000000);
	return bet;
}
