/*
 * Card.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Eli Siskind
 */

using namespace std;

#ifndef CARD_H
#define CARD_H

#include "Deck.h"

class Card {
private:
	int suit;
	int value;
	Card* next;
	Card* prev;
public:
	void operator | (Card h);
	Card();
	Card(int s, int v);
	~Card();
	int getValue();
	int getSuit();
	void print();
	bool isBlank();
	friend class Deck;
	friend class MainDeck;
	friend class SmallDeck;
};

#endif /* CARD_H_ */
