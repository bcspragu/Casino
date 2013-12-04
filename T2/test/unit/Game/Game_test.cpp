/*
 * MainDeck_test.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#include "MainDeck.h"

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

#include "Game.h"
#include "Player.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand(time (NULL));

	Game game;
	game.startGame();
	game.playRound();
	game.playRound();
	game.endGame();

	return 0;
}
