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

using namespace std;

Display gameDisplay;

int main() {

	char key;
	stringstream ss;

	srand(time(NULL));

	Game game;
	int startMoney = 1000;
	if (game.startGame(startMoney)) {
		while (true) {
			if (game.playRound()) {
				continue;
			} else {
				ss << "Current money: " << game.endGame();
				break;
			}
		}
	} else {
		ss << "Current money: " << startMoney;
	}

	gameDisplay.eraseScreen(true);

	return 0;
}
