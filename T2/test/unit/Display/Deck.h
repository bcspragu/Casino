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
	void add(Card* newCard);
	void add(Deck *d);
	Card * draw();
	bool isEmpty();
	void print();
	void deleteAllCards();
protected:
	Card* top;
	Card* bottom;
	int size;
};


#endif /* DECK_H_ */
