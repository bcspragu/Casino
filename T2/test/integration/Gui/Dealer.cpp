/* Dealer class
 *
 */

#include "Dealer.h"
#include <iostream>

using namespace std;

Dealer::Dealer() {
	discardDeck = new Deck();
	mainDeck = new MainDeck();
}

Dealer::~Dealer() {
	delete discardDeck;
	delete mainDeck;
}

void Dealer::makeDeck() {
	int s;
	int v;

	for (s = 1; s <= 4; s++) {
		for (v = 2; v <= 14; v++) {
			Card *c = new Card(s, v);
			mainDeck->add(c);
			//c->print();
		}

	}
	//mainDeck->print();
}

void Dealer::resetDeck() {
	mainDeck->add(discardDeck);
	mainDeck->shuffle();
}

Card * Dealer::deal() {
	return mainDeck->draw();
}

void Dealer::burn() {
	discardDeck->add(mainDeck->draw());
}

void Dealer::discard(Card * card) {
	discardDeck->add(card);
}

void Dealer::discard(Deck * deck) {
	discardDeck->add(deck);
}

void Dealer::deleteAll() {
	//delete remain cards
	discard(mainDeck);
	while (!discardDeck->isEmpty()) {
		delete discardDeck->draw();
	}

}
