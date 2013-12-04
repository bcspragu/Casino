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

	T2GameDisplay.eraseScreen(true);

	//save values
	g->cardsPlayed = game.getCardsPlayed();
	
	return 0;
}
