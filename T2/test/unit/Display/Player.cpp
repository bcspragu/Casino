/**
 * Player.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "Player.h"

#include <string>
#include <iostream>

using namespace std;

Player::Player() {
	playerNum = -1;
	folded = false;
	money = 500;
	pocket = new SmallDeck();
}

Player::Player(int num) {
	playerNum = num;
	folded = false;
	money = 500;
	pocket = new SmallDeck();
}

Player::~Player() {

}

bool Player::inRound() {
	return !folded;
}

void Player::giveCard(Card * card) {
	pocket->add(card);
}

SmallDeck * Player::getPocket() {
	return pocket;
}


int Player::getMoney() {
	return money;
}


void Player::print() {
	//cout << "P" << playerNum << ": " << money << " ";
	//deck->print();
}
