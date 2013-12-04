/*
 * Poker.cpp
 *
 *  Created on: Oct 28, 2013
 *      Author: Eli Siskind
 *  Description: Main method
 */

#include "T2Poker.h"

using namespace std;

int T2Poker::runGame(GameObject* g) {
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

	//pass values back to menu
	g->cardsPlayed += game.getCardsPlayed();

	g->cash = game.getPlayerMoney();
	//game.getGui();

	return 0;
}
