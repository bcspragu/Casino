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

#include "Bet.h"
#include "Card.h"
#include "Display.h"
#include "Game.h"
#include "Layout.h"
#include "Player.h"
#include "PlayerList.h"
#include "Point.h"
#include "SmallDeck.h"

class PlayerList;

#define TIMEDELAY 1

// declare external global objects
extern Display gameDisplay;
extern Layout gameLayout;
extern Game game;

Gui::Gui() {

}

Gui::~Gui() {

}

// Function for running the game
bool Gui::startGui(void) {

	// enable resize detection
	signal(SIGWINCH, detectResize);

	// variables
	char key;
	stringstream messageString;

	for (int i = 0; i < 40; i++) {
		messageString << "STARTED STARTED STARTED" << endl;
	}
	gameDisplay.bannerTop(messageString.str());

	// clear and restart the display
	gameLayout.setup();
	redraw();

	// display the new game screen
	gameDisplay.bannerTop("New Game!");
	// infinite loop for the main program, you can press e to quit
	while (true) {
		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key > 0) {
			// make bottom a banner message saying that a key was pressed
			messageString.str("");
			messageString << "Key " << key << " pressed";
			gameDisplay.bannerBottom(messageString.str());

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

void Gui::update() {
	if (game.getState() > 1) {
		gameLayout.setBlankCards();
	}
	redraw();
}

void Gui::showTurn(int p, Bet b) {

	// variables
	int i;
	char key;
	stringstream messageString;

	// Update status bar;
	messageString << "Player " << p << b.print();
	gameDisplay.bannerTop(messageString.str());

	gameLayout.startTurn(p);
	redraw();
	// infinite loop for the main program, you can press e to quit
	for (i = 0; i < TIMEDELAY; i++) {
		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key > 0) {
			// make bottom a banner message saying that a key was pressed
			messageString.str("");
			messageString << "Key " << key << " pressed";
			gameDisplay.bannerBottom(messageString.str());

			switch (key) {
			case 'e':
				return;
				break;
			}
		}
	}
	gameLayout.endTurn();
	redraw();

	return;
}

/*
 * This is the interrupt service routine called when the resize screen 
 * signal is captured.
 */
void Gui::detectResize(int sig) {
	// update the display class information with the new window size
	gameDisplay.handleResize(sig);

	// re-enable the interrupt for a window resize
	signal(SIGWINCH, detectResize);

	// Redisplay the layout
	gameLayout.setup();
	redraw();
}

// Redraw the layout
void Gui::redraw() {
	clearScreen();
	gameLayout.setup();
	if (game.getState() > 0) {
		if (gameLayout.getSize().getX() < 127
				|| gameLayout.getSize().getY() < 32)
			gameDisplay.bannerBottom(
					"Please enlarge this window to properly view the game.");
		else {
			displayCommon(); // display deck, discard pile, center pot, and community cards
			displayPlayers();		// display player info for computer players
		}
	}
}

// display deck, discard pile, center pot, and community cards
void Gui::displayCommon() {
	int i;
	Point loc;
	Card blank(-1, -1);
	Card card(1, 1);

	//display deck
	loc = gameLayout.getDeckArea();
	gameDisplay.displayDeck(loc);

	//display discard pile
	loc = gameLayout.getDiscardArea();
	gameDisplay.displayDeck(loc);

	//display center pot
	loc = gameLayout.getCenterPotArea();
	int p = gameLayout.getPot();
	gameDisplay.displayPot(loc, "Center", p, A_DIM);

	//display community cards
	loc = gameLayout.getCommCardArea(0);
	SmallDeck d = *game.commCards;
	gameDisplay.drawBox(loc, CARDW * 5 + 4, CARDH + 2, A_DIM);
	for (i = 1; i <= 5; i++) {
		loc = gameLayout.getCommCardArea(i);
		card = d.getCard(i);
		gameDisplay.displayCard(loc, card, A_NORMAL);
	}
}

void Gui::displayPlayers() {

	PlayerList pList = *game.playerList;
	Player * start = pList.getCurrentPlayer();
	Player * p;
	do {
		p = pList.getCurrentPlayer();
		if (p->getNum() == 0) {
			displayUserRegion(*p);
		} else
			gameDisplay.displayPlayerInfo(*p);
		pList.next();
	} while (pList.getCurrentPlayer() != start);

}

void Gui::displayUserRegion(Player p) {
	int i;
	Point loc;
	SmallDeck pocket;

	//display player's cards
	pocket = *p.getPocket();
	loc = gameLayout.getPlayerCardArea(0);
	gameDisplay.drawBox(loc, gameDisplay.getCols(), CARDH + 2, A_DIM);
	for (i = 0; i < 2; i++) {
		loc = gameLayout.getPlayerCardArea(i);
		gameDisplay.displayCard(loc, pocket.getCard(i), A_NORMAL);
	}

	//display player's pot
	loc = gameLayout.getPlayerPotArea();
	gameDisplay.displayPot(loc, "Your ", p.getMoney(), A_NORMAL);
}

// Clear the entire screen
void Gui::clearScreen() {
	gameDisplay.eraseScreen();

}
