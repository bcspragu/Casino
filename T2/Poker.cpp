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

#include <cstdlib>

using namespace std;

Display gameDisplay;

int main(int argc, char* argv[]) {

	stringstream ss;

	srand(time(NULL));

	Game game;
	if (game.startGame(atoi(argv[1]))) {
		while (true) {
			if (game.playRound()) {
				continue;
			} else {
				ss << "Current money: " << game.endGame();
				break;
			}
		}
	} else {
		ss << "Current money: " << atoi(argv[0]);
	}

	gameDisplay.eraseScreen(true);

	return 0;
}
