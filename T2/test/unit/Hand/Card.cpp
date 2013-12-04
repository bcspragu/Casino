/*
 * Card.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include <iostream>
#include <string>

#include "Card.h"
#include "Deck.h"

using namespace std;

Card::Card(){}

Card::Card(int s, int v) {
	suit = s;
	value = v;
	next = NULL;
	prev = NULL;
}
void Card::operator | (Card h){
	this->suit=h.suit;
	this->value=h.value;
}
Card::~Card() {
}

int Card::getValue() {
	return value;
}
int Card::getSuit() {
	return suit;
}

void Card::print() {
	cout << "Suit: " << suit << "\tValue:" << value << endl;
}
