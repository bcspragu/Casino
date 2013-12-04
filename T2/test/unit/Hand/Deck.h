/*
 * Deck.h
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli
 */

#ifndef DECK_H
#define DECK_H

#include <string>

#include "Card.h"

using namespace std;

class Card;

class Deck {
public:
	Deck();
	~Deck();
	void shuffle();
	Card* getCardArray();
	void add(Card* newCard);
	Card * draw();
	bool isEmpty();
	void print();
		int size;
			Card* top;
	Card* bottom;
private:


	void swap(Card * source, Card * target);
};


#endif /* DICK_H_ */

