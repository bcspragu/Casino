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
	//money = 100;
	//deck = new SmallDeck();
}

Player::Player(int num) {
	playerNum = num;
	folded = false;
	//money = 5000;
	//deck = new SmallDeck();
}

Player::~Player() {
	//delete deck;
	cout << "Deleting player " << playerNum << endl;
}

bool Player::inRound() {
	return !folded;
}

//void Player::giveCard(Card * card) {
//	deck->add(card);
//}

//SmallDeck * Player::getDeck() {
//	return deck;
//}

void Player::fold() {
	folded = true;
	//return deck;
}

//int Player::getMoney() {
//	return money;
//}

//void Player::takePot(int pot) {
//	money += pot;
//}

void Player::unFold() {
	folded = false;
}

//Bet Player::makeBet(int minBet) {
//	Bet bet(0, 0);
//	return bet;
//}
//
//Bet Player::makeBig(int minBet) {
//
//	// if player cannot pay, they fold and put the rest of their money in
//	if (minBet > money) {
//		Bet bet(-1, money);
//		money = 0;
//		return bet;
//	} else {
//		Bet bet(0, minBet);
//		money = money - minBet;
//		return bet;
//	}
//}
//
//Bet Player::makeLittle(int minBet) {
//
//	int betAmt = minBet / 2;
//	// if player cannot pay, they fold and put the rest of their money in
//	if (betAmt > money) {
//		Bet bet(-1, money);
//		money = 0;
//		return bet;
//	} else {
//		Bet bet(0, betAmt);
//		money = money - betAmt;
//		return bet;
//	}
//}

void Player::print() {
	if (this != NULL)
		cout << "P" << playerNum << " "; // << ": " << money << " ";
	//deck->print();
}
