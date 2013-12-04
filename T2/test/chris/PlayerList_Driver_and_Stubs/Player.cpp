/**
 * Player.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "Player.h"

Player::Player() {
	folded = false;
	money = 10;
}

Player::~Player() {
	////cout << "Deleting player " << playerNum << endl;
}
void Player::fold() {
	folded = true;
}
bool Player::inRound() {
	return !folded;
}

void Player::takeMoney(int amt) {
	money -= amt;
}

int Player::getMoney() {
	return money;
}

void Player::unFold() {
	folded = false;
}

