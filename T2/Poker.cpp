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

Game game;
Display gameDisplay;
Layout gameLayout;

int main(int argc, char* argv[]) {

	srand (time(NULL));

	game.startGame();
	while(game.playRound()){}
	game.endGame();

	return 0;
}
