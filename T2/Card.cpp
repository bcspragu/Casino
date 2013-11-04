/*
 * Card.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Eli Siskind
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

}

void Card::operator | (Card h){
	this->suit=h.suit;
	this->value=h.value;
}

int Card::getValue() {
	return value;
}
int Card::getSuit() {
	return suit;
}

bool Card::isBlank(){
	return (suit == 0 && value == 0);
}

void Card::print() {
	if (this != NULL){
		cout << " [" << suit << " " << value << "]";
	}
}
