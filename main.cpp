#include "Balance.h"

//includes for T2
#include "T2/Display.h"
#include "T2/Game.h"
#include "T2/Layout.h"

#define INITIAL_BALANCE 500;	//amount the player starts with

int Balance::balance = INITIAL_BALANCE;

void runT2();

//variables for T2
Display gameDisplay;

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

	gameDisplay.eraseScreen(true);
	gameDisplay.bannerBottom(ss.str());
	// Infinite loop to wait for user input
	for (;;) {

		// Calls the game display to capture some input
		key = gameDisplay.captureInput();

		// Break if user presses 'n'
		if (key > 0)
			break;
	}
}
