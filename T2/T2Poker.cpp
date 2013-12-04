/*
 * Poker.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli Siskind
 *  Description: Main method
 */

//#include "Gui.h"
#include "T2Display.h"
#include "Game.h"
#include "Layout.h"
#include "../GameObject.h"

#include <cstdlib>
#include <iostream>

using namespace std;

extern T2Display T2GameDisplay;

int runGame(GameObject* g) {
	stringstream ss;

	srand(time(NULL));

	Game game;
	if (game.startGame(g->cash)) {
		while (true) {
			if (game.playRound()) {
				continue;
			} else {
				ss << "Current money: " << game.endGame();
				break;
			}
		}
	} else {
		ss << "Current money: " << g->cash;
	}

	T2GameDisplay.eraseScreen(true);

	//save values
	g->cardsPlayed = game.getCardsPlayed();
	
	return 0;
}
