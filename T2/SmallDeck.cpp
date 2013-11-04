/*
 * SmallDeck.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: Eli Siskind
 */

#include "SmallDeck.h"
#include <iostream>

using namespace std;

SmallDeck::SmallDeck() {

}

SmallDeck::~SmallDeck() {
}

Card SmallDeck::getCard(int num) {
	////cout << "Getting card: " << num << endl;
	if (num < size){
		Card * current = top;
		for (int i = 0; i < num; i++){
			current = current->next;
		}
		return *current;
	}
	else
		return Card(0,0);
}

int SmallDeck::getSize(){
	////cout << "Size: " << size << endl;
	return size;
}

