/*
 * PlayerDeck.h
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
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
};

#endif /* SMALLDECK_H */
