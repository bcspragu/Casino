#include "Balance.h"

//includes for T2
#include "T2/Display.h"
#include "T2/Game.h"
#include "T2/Layout.h"

#define INITIAL_BALANCE 500;	//amount the player starts with

int Balance::balance = INITIAL_BALANCE;

void runT2();

//variables for T2
Game game;
Display gameDisplay;
Layout gameLayout;

int main (void) {

	//test running game
	runT2();
	
	return 0;
}

/*
 * function to run Texas Holdem 2
 */
void runT2(void) {

	srand (time(NULL));

	game.startGame();
	while(game.playRound()){}
	game.endGame();

}
