/*
 * MainDeck.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: Eli Siskind
 */

#include "MainDeck.h"

#include "Card.h"
#include "Deck.h"
#include <cstdlib>

using namespace std;

MainDeck::MainDeck()
{

}

MainDeck::~MainDeck()
{

}

//
void MainDeck::shuffle() {
	int i;
	int j;
	int random;
	Card * target;
	Card * source;

	// loop to iterate through all nodes in the list
	for (i = 0; i < size; i++) {

		// go to the source
		source = top;
		for (j = 0; j < i; j++) {
			source = source->next;
		}

		//find a random target
		random = rand() % size;
		target = top;
		for (j = 0; j < random; j++) {
			target = target->next;
		}

		//swap their data
		swap(source, target);
	}
}

void MainDeck::swap(Card * source, Card * target) {
	Card temp = *target;
	if (source != NULL && target != NULL) {
		temp.suit = source->suit;
		temp.value = source->value;
		source->suit = target->suit;
		source->value = target->value;
		target->suit = temp.suit;
		target->value = temp.value;
	}
}
