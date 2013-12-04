/*
 * Deck.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli
 */

#include "Deck.h"

#include <cstdlib>
#include <iostream>
#include "Card.h"

using namespace std;

Deck::Deck() {
	top = NULL;
	bottom = NULL;
	size = 0;
}

Deck::~Deck() {

}

bool Deck::isEmpty() {
	return (size == 0);
}

void Deck::add(Card * newCard) {
	if (isEmpty()) {
		top = newCard;
		top->next = bottom;
		top->prev = NULL;
	} else {
		top->prev = newCard;
		newCard->next = top;
		top = newCard;
		top->prev = NULL;
	}
	size++;
	////cout << "Added card. New size:" << size << endl;
}

//void Deck::add(Deck d) {
//	while (!d.isEmpty()) {
//		add(d.draw());
//	}
//}

void Deck::add(Deck * d) {
	while (!d->isEmpty()) {
		add(d->draw());
	}
}

Card* Deck::draw() {
	if (!isEmpty()) {
		Card * card = top;
		top = top->next;
		if (top != NULL)
			top->prev = NULL;
		size--;
		////cout << "Drew card. New size:" << size << endl;

		//strip pointers
		card->next = NULL;
		card->prev = NULL;

		return card;
	} else {
		////cout << "EMPTY" << endl;
		return NULL;
	}
}

void Deck::print() {
	Card* current = top;
	while (current != NULL) {
		current->print();
		current = current->next;
	}
}
