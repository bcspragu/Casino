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

	//delete remain cards
	Card * current;
	while (!isEmpty()) {
		current = draw();
		delete current;
		cout << "deleting" << endl;
	}

}

bool Deck::isEmpty() {
	return (top == NULL);
}

void Deck::add(Card * newCard) {
	if (isEmpty()) {
		top = newCard;
		top->next = bottom;
	} else {
		top->prev = newCard;
		newCard->next = top;
		top = newCard;
	}
	size++;
}

Card* Deck::draw() {
	if (!isEmpty()) {
		Card* card = top;
		top = top->next;
		if (top != NULL)
			top->prev = NULL;
		size--;
		return card;
	} else
		return NULL;
}

void Deck::print() {
	Card* current = top;
	while (current != NULL) {
		current->print();
		current = current->next;
	}
}
