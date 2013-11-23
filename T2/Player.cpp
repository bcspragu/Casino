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
	next = NULL;
	prev = NULL;
	playerNum = 0;
	folded = false;
	money = 500;
	pocket = new SmallDeck();
}

Player::Player(int num) {
	next = NULL;
	prev = NULL;
	playerNum = num;
	folded = false;
	money = 500;
	pocket = new SmallDeck();
}

Player::~Player() {

}

void Player::giveCard(Card * card) {
	pocket->add(card);
}

SmallDeck * Player::fold() {
	folded = true;
	return pocket;
}

void Player::takePot(int pot) {
	money += pot;
}

void Player::unFold() {
	folded = false;
}

Bet Player::makeBet(SmallDeck comm, int minBet, GameState state) {
	Bet bet(CALL, 0);
	return bet;
}

Bet Player::makeBig(int minBet) {

	// if player cannot pay, they fold and put the rest of their money in
	if (minBet > money) {
		Bet bet(FOLD, money);
		money = 0;
		return bet;
	} else {
		Bet bet(CALL, minBet);
		money = money - minBet;
		return bet;
	}
}

Bet Player::makeLittle(int minBet) {

	int betAmt = minBet / 2;
	// if player cannot pay, they fold and put the rest of their money in
	if (betAmt > money) {
		Bet bet(FOLD, money);
		money = 0;
		return bet;
	} else {
		Bet bet(CALL, betAmt);
		money = money - betAmt;
		return bet;
	}
}

void Player::print() {
	cout << "[P " << playerNum << " ] Money: " << money << " Cards: ";
	pocket->print();
}
