/*
 * Player.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "Player.h"
#include <iostream>
using namespace std;
Player::Player() {
	folded = false;
	money = 100;

}

Player::~Player() {}

bool Player::inRound() {return !folded;}

void Player::giveCard(Card * card) {deck.add(card);}

SmallDeck Player::show() {return deck;}

Bet * Player::makeBet(int amount) {
	//should never be called...consider removing
	cout << "player" << endl;
	return new Bet(0, 0);
}

void Player::fold() {folded = true;} //return deck when fold

int Player::getMoney() {return money;}

//void Player::takePot(Pot p) {money += p.getPotAmount();}

void Player::unFold() {folded = false;}

Card* Player::discard() {return cards;}

