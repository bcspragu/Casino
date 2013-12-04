/*
 * Gui_test.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli
 */

#include "Game.h"

using namespace std;

Game game;

int main(int argc, char* argv[]) {

	srand (time(NULL));

	game.startGame();
	while(game.playRound()){}
	game.endGame();

	return 0;
}
