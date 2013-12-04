/*
 * Deck_Test.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: Eli
 */

#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iostream>
#include <stdio.h>

#include "Card.h"
#include "Deck.h"

using namespace std;

/* Main method
 *
 */
int main(int argc, char* argv[]) {
	srand (time(NULL));int i;

	Card *c;
	Deck * deck1 = new Deck();
	Deck * deck2 = new Deck();

	for (i = 0; i < 10; i++) {
		c = new Card(0, i);
		deck1->add(c);
	}

	deck1->print();
	deck2->print();

	deck2->add(deck1);

	deck1->print();
	deck2->print();

	cout << endl << "Drawing from deck1:" <<endl;
	c = deck1->draw();
	c->print();

	cout << endl << "Drawing from deck2:" <<endl;
	c = deck2->draw();
	c->print();

	cout << endl << "Drawing from deck2:" <<endl;
	c = deck2->draw();
	c->print();

	cout << endl;
	deck1->print();
	deck2->print();

	if(deck1->isEmpty()) {
		cout << "Eli fucked up" << endl;
	}

	delete deck1;
	delete deck2;
	return 0;
}

