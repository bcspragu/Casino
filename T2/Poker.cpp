/*
 * Poker.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli Siskind
 *  Description: Main method
 */

//#include "Gui.h"
#include "Display.h"
#include "Game.h"
#include "Layout.h"
#include "../GameObject.h"

#include <cstdlib>
#include <iostream>

using namespace std;

GameObject *game;

int runGame(GameObject* g) {
  game = g;
	stringstream ss;

	srand(time(NULL));

	Game game;
	if (game.startGame(g->money) {
		while (true) {
			if (game.playRound()) {
				continue;
			} else {
				ss << "Current money: " << game.endGame();
				break;
			}
		}
	} else {
		ss << "Current money: " << g->money;
	}

	t2GameDisplay.eraseScreen(true);

	//save values
	//game.getCardsPlayed();
	
	return 0;
}
