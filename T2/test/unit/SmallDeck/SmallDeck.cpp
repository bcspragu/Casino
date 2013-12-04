/*
 * smallDeck.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#include "SmallDeck.h"

using namespace std;

SmallDeck::SmallDeck() {

}

SmallDeck::~SmallDeck() {
}

Card SmallDeck::getCard(int num) {
	Card card(0, 0);
	int i;

	if (num <= size) {
		card = *top;
		for (i = 0; i < num; i++)
			card = *card.next;
	}
	return card;
}

