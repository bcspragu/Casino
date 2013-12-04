/*
 * HumanPlayerDriver.cpp
 *
 *  Created on: Nov 1, 2013
 *      Author: chris
 */

#include <assert.h>
#include "HumanPlayer.h"
#include "Game.h"
#include<iostream>
Game game = Game();

int main() {

	//test makeBet()
	HumanPlayer human = HumanPlayer(1);
	int temp = human.money;
	human.makeBet(SmallDeck(), 30);
	assert(human.money == temp - 30);

	std::cout << "-----test complete for HumanPlayer Driver-----" << endl;

	return 0;
}


