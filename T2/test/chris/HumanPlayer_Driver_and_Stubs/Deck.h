/**
* Deck.h
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Card;

class Deck {
public:
	Deck();
	~Deck();
	void add(Card* newCard);
};

#endif /* DECK_H_ */
