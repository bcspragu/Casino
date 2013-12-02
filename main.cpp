//includes for T2
#include "T2/T2Display.h"
#include "T2/Game.h"
#include "T2/Layout.h"

#define INITIAL_BALANCE 500;	//amount the player starts with

void runT2();

//variables for T2
T2Display GAME_DISPLAY_T2;

int main (void) {

	//test running game
	runT2();
	
	return 0;
}

/*
 * function to run Texas Holdem 2
 */
void runT2(void) {

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

	GAME_DISPLAY_T2.eraseScreen(true);
}
