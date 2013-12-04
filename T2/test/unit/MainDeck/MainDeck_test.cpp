/*
 * MainDeck_test.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#include "MainDeck.h"

#include <iostream>

#include "Card.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));
	int i;
	MainDeck * deck = new MainDeck();
	for (i = 0; i < 10; i++) {
		Card * c = new Card(0, i);
		deck->add(c);
	}

	deck->print();
	deck->shuffle();
	cout << endl;
	deck->print();
	delete deck->draw();
	delete deck->draw();
	cout << endl;
	deck->print();
	delete deck;
	return 0;
}
