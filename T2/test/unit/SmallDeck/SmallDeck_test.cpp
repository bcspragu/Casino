/*
 * SmallDeck_test.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#include "SmallDeck.h"

#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Card.h"
#include "SmallDeck.h"
//#include "Deck.h"

using namespace std;

int main(int argc, char* argv[]) {
	int i;
	SmallDeck * deck = new SmallDeck();

	// add some cards
	for (i = 0; i < 5; i++) {
		Card * c = new Card(0, i);
		deck->add(c);
	}

	deck->print();
	cout << endl;
	cout<<"Card 3:" <<endl;
	deck->getCard(3).print();
	cout << endl;
	deck->print();

	delete deck;
	return 0;
}

