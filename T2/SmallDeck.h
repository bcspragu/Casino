/*
 * SmallDeck.h
 *
 *  Created on: Oct 29, 2013
 *      Author: Eli Siskind
 */

#ifndef SMALLDECK_H
#define SMALLDECK_H

using namespace std;

#include "Deck.h"

class SmallDeck: public Deck {
public:
	SmallDeck();
	~SmallDeck();
	Card getCard(int num);
	int getSize();
};

#endif /* SMALLDECK_H */
