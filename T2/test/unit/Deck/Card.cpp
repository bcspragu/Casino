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


Card::Card(int s, int v) {
	suit = s;
	value = v;
	next = NULL;
	prev = NULL;
}

Card::Card(){
	suit = 0;
	value = 0;
	next = NULL;
	prev = NULL;
}

Card::~Card() {
//	cout << "deleting [" << suit << " " << value << "]" << endl;
}

void Card::operator | (Card h){
	this->suit=h.suit;
	this->value=h.value;
}

int Card::getValue() {
	return suit;
}
int Card::getSuit() {
	return value;
}

void Card::print() {
	cout << " [" << suit << " " << value << "]";
}
