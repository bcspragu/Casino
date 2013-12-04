/* Module of functions for running the game and changing the display
 *
 * NOTES:
 *      * Requires the terminal (Putty) to be set to UTF-8.
 *      * Does not function when running a screen session.
 */

#include "Gui.h"

#include <unistd.h>
#include <csignal>
#include <sstream>
#include <string>
#include <iostream>

#include "Bet.h"
#include "Card.h"
#include "Game.h"
#include "Player.h"
#include "PlayerList.h"
#include "SmallDeck.h"

// declare external global objects
extern Game game;

Gui::Gui() {

}

Gui::~Gui() {

}

// Function for running the game
bool Gui::startGui(void) {

	// variables
	char key;
	stringstream messageString;

	// clear and restart the display
	update(0);

	cout << "New Game!" << endl << "[Continue: c] [Exit: e]" << endl;
	// infinite loop for the main program, you can press e to quit
	for (;;) {
		// calls the game display to capture some input
		cin.get(key);

		// if a key was pressed
		if (key > 0) {

			switch (key) {
			case 'e':
				return false;
				break;
			case 'c':
				return true;
				break;
			}
		}
	}
	return false;
}

Bet Gui::getBetInput(int minBet) {
	cout << "Your turn to make a bet." << endl;
	int amount;
	int type = getBetType(minBet);
	if (type < 1)
		amount = 0;
	else if (type == 1)
		amount = minBet;
	else {
		amount = getBetAmount() + minBet;
	}

	// reset input state flag
	game.userInputState = 0;
	return Bet(type, amount);
}

int Gui::getBetType(int minBet) {

	// variables
	char key;
	stringstream messageString;

	// set flag in case of resize
	game.userInputState = 1;

	// display prompt
	messageString << "Make a bet. [fold: f] [call ";
	messageString << minBet << ": c ] [raise: r]";

	cout << messageString.str() << endl;

// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		cin.get(key);

		// if a key was pressed
		if (key > 0) {

			//return a bet action depending on the key pressed
			switch (key) {
			case 'f':
				return -1;
				break;
			case 'c':
				return 1;
				break;
			case 'r':
				return 2;
				break;
			}
		}
	}

	return false;
}

int Gui::getBetAmount() {

	// variables
	char key;
	stringstream messageString;

	// set flag in case of resize
	game.userInputState = 2;

	// display prompt
	messageString << "Choose an amount. [5: f] [10: t] [50: h] [100: a]";
	cout << messageString << endl;

	// infinite loop to wait for user input
	for (;;) {
		// calls the game display to capture some input
		cin.get(key);

		// if a key was pressed
		if (key > 0) {

			switch (key) {
			case 'f':
				return 5;
				break;
			case 't':
				return 10;
				break;
			case 'h':
				return 50;
				break;
			case 'a':
				return 100;
			}
		}
	}
	return false;
}

void Gui::update(int status) {

	stringstream ss;
	int timeDelay = 0;

	if (game.userInputState == 1) { // user is making a bet

		//redraw();

		// display prompt
		ss << "Make a bet. [fold: f] [call ";
		ss << game.minBet << ": c ] [raise: r]";
		cout << ss.str() << endl;

	} else if (game.userInputState == 2) { // User is choosing raise amount

		//redraw();

		// display prompt
		ss << "Choose an amount. [5: f] [10: t] [50: h] [100: a]";
		cout << ss.str() << endl;

	} else {

		Bet bet = game.currentBet;
		int current = game.currentPlayer;

		switch (status) {
		case 0:	// No message or delay
			break;
		case 1:	// Dealing cards
			timeDelay = 1;
			ss << "Dealing cards.";
			break;
		case 2: //A player's turn
			timeDelay = 15;
			ss << "Player " << current << " " << bet.print();
			break;
		default:
			break;
		}

		if (status == 2) {
			cout << ss.str() << endl;
			redraw();
		}
		delay(timeDelay);

	}

}

void Gui::delay(int timeDelay) {

	cout << endl;

}

/*
 * This is the interrupt service routine called when the resize screen 
 * signal is captured.
 */
//void Gui::detectResize(int sig) {
//	// update the display class information with the new window size
//	gameDisplay.handleResize(sig);
//
//	// re-enable the interrupt for a window resize
//	signal(SIGWINCH, detectResize);
//
//	// Redisplay the layout
//	update(-1);
//}
// Redraw the layout
void Gui::redraw() {

	displayCommon(); // display deck, discard pile, center pot, and community cards
	displayPlayers(); // display player info for computer players

}

// display deck, discard pile, center pot, and community cards
void Gui::displayCommon() {

	//display center pot
	cout << "Center pot: " << game.centerPot << endl;

	//display community cards
	cout << "Community cards: ";
	game.commCards->print();
	cout << endl;
}

void Gui::displayPlayers() {
	game.playerList->print();

}
