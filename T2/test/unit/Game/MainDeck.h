/*
 * MainDeck.h
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#ifndef MAINDECK_H
#define MAINDECK_H

#include "Deck.h"
class Card;


using namespace std;

class MainDeck: public Deck
{
public:
	MainDeck();
	~MainDeck();
	void shuffle();
private:
	void swap(Card * source, Card * target);

};

#endif /* MAINDECK_H */
