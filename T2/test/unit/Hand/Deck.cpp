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
	Card* card = top;
	top = top->next;
	if (top != NULL)
		top->prev = NULL;
	return card;
}

void Deck::print() {
	Card* current = top;
	while (current != NULL) {
		current->print();
		current = current->next;
	}
}

void Deck::shuffle() {
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


void Deck::swap(Card * source, Card * target) {
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
