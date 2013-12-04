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

Display gameDisplay;
GameObject *game_object;

int runGame(GameObject* g) {
  game_object = g;
	stringstream ss;

	srand(time(NULL));

	Game game;
	if (game.startGame(game_object->cash)) {
		while (true) {
			if (game.playRound()) {
				continue;
			} else {
				ss << "Current money: " << game.endGame();
				break;
			}
		}
	} else {
		ss << "Current money: " << game_object->cash;
	}

	gameDisplay.eraseScreen(true);

	//save values
	g->cardsPlayed = game.getCardsPlayed();
	
	return 0;
}
