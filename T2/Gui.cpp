/* Gui.cpp
 *
 * Author: Eli Siskind
 * Description: Wrapper class for using the functionality of the display class.
 *
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

// declare external global objects
extern Layout gameLayout;
extern Display gameDisplay;
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

	// clear and restart the display
	update(0);

	// display the new game screen
	gameDisplay.bannerTop("New Game!");
	gameDisplay.bannerBottom("[Continue: c] [Exit: e]");
	// infinite loop for the main program, you can press e to quit
	for (;;) {
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

void Gui::showRoundWinner(int roundWinner) {

	//variables
	string title;
	string text1;
	string text2;
	stringstream ss;
	Point loc;
	char key;

	clearScreen();

	ss << "End of round " << game.getRoundNum() << "!";
	title = ss.str();
	ss.clear();
	ss.str("");

	ss << "Player " << roundWinner << " won:  ";
	text1 = ss.str();
	ss.clear();
	ss.str("");

	ss << "$" << game.getPot() << "      ";
	text2 = ss.str();

	loc = gameLayout.getCommCardArea(0);
	gameDisplay.displayInfoBox(loc, title, text1, text2, COLOR_PAIR(3));


	gameDisplay.bannerTop("Round ended.");
	gameDisplay.bannerBottom("[Next round: n]");

	// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key == 'n')
			break;
	}
}

void Gui::showWinner(int winner) {

	//variables
	string title;
	string text1;
	string text2;
	stringstream ss;
	Point loc;
	char key;

	clearScreen();

	ss << "Game over!  ";
	title = ss.str();
	ss.clear();
	ss.str("");

	ss << "The winner is:";
	text1 = ss.str();
	ss.clear();
	ss.str("");

	ss << "Player " << winner << ".   ";
	text2 = ss.str();

	loc = gameLayout.getCommCardArea(0);
	gameDisplay.displayInfoBox(loc, title, text1, text2, COLOR_PAIR(1));


	gameDisplay.bannerTop("Round ended.");
	gameDisplay.bannerBottom("[Exit: e]");

	// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key == 'e')
			break;
	}
}

Bet Gui::getBetInput(int minBet) {
	update(0);
	gameDisplay.bannerTop("Your turn to make a bet.");
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
	game.setUserInputState(0);
	return Bet(type, amount);
}

int Gui::getBetType(int minBet) {

	// variables
	char key;
	stringstream messageString;

	// set flag in case of resize
	game.setUserInputState(1);

	// display prompt
	messageString << "Make a bet. [fold: f] [call ";
	messageString << minBet << ": c ] [raise: r]";
	gameDisplay.bannerBottom(messageString.str());

// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = gameDisplay.captureInput();

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
	int amount = 0;

	// set flag in case of resize
	game.setUserInputState(2);

	// infinite loop to wait for user input
	for (;;) {

		clearScreen();
		update(0);

		// display prompt
		messageString << "Choose the amount to raise. Current amount: ";
		messageString << amount + game.getMinBet();
		messageString << " [+5: f] [+10: t] [+50: h] [+100: a] [Enter: e]";
		gameDisplay.bannerBottom(messageString.str());
		messageString.clear();
		messageString.str("");

		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key > 0) {

			switch (key) {
			case 'f':
				amount += 5;
				break;
			case 't':
				amount += 10;
				break;
			case 'h':
				amount += 50;
				break;
			case 'a':
				amount += 100;
				break;
			case 'e':
				return amount;
			}
		}
	}
	return false;
}


void Gui::update(int status) {

	stringstream ss;
	int timeDelay = 0;

	//clear screen before redraw
	gameLayout.setup(gameDisplay.getCols(), gameDisplay.getLines());
	clearScreen();

	//only draw if screen is large enough{
	if (gameLayout.getSize().getX() < 127 || gameLayout.getSize().getY() < 32) {

		ss << "Please enlarge this window to properly view the game.";
		gameDisplay.bannerBottom(ss.str());

	} else if (game.getUserInputState() == 1) { // user is making a bet

		redraw();

		// display prompt
		ss << "Make a bet. [fold: f] [call ";
		ss << game.getMinBet() << ": c ] [raise: r]";
		gameDisplay.bannerBottom(ss.str());

	} else if (game.getUserInputState() == 2) { // User is choosing raise amount

		redraw();

		// display prompt
		ss << "Choose an amount. [5: f] [10: t] [50: h] [100: a]";
		gameDisplay.bannerBottom(ss.str());

	} else {

		Bet bet = game.getCurrentBet();
		int current = game.getCurrentNum();

		switch (status) {
		case 0:	// No message or delay
			break;
		case 1:	// Dealing cards
			timeDelay = 1;
			ss << "Dealing cards.";
			break;
		case 2: // A player's turn
			timeDelay = 15;
			ss << "Player " << current << " " << bet.print();
			break;
		case 3: // Show hands
			timeDelay = 5000;
			ss << "Round ended.";
			break;
		default:
			break;
		}

		redraw();
		if (status > 0)
			gameDisplay.bannerTop(ss.str());
		if (status == 3)
			gameDisplay.bannerBottom("[Continue: c]");
		delay(timeDelay);

	}

}

void Gui::delay(int timeDelay) {
	char key;

	//gameDisplay.bannerBottom("[Continue: c]");

	if (timeDelay >= 0) {
		for (int i = 0; i < timeDelay; i++) {
			// calls the game display to capture some input
			key = gameDisplay.captureInput();

			// if a key was pressed
			if (key == 'c')
				return;
		}
	} else {
		redraw();
	}
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
	update(-1);
}

// Redraw the layout
void Gui::redraw() {

	displayCommon(); // display deck, discard pile, center pot, and community cards
	displayPlayers(); // display player info for computer players

}

// display deck, discard pile, center pot, and community cards
void Gui::displayCommon() {
	int i;
	int attr = A_NORMAL;
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
	gameDisplay.displayPot(loc, "Center", game.getPot(), attr);

	//display community cards
	loc = gameLayout.getCommCardArea(0);
	SmallDeck d = game.getCommCards();
	attr = A_NORMAL | COLOR_PAIR(1);
	gameDisplay.drawBox(loc, CARDW * 5 + 4, CARDH + 2, false, attr);

	attr = A_NORMAL;
	for (i = 0; i < 5; i++) {
		loc = gameLayout.getCommCardArea(i + 1);
		card = d.getCard(i);
		gameDisplay.displayCard(loc, card, attr);
	}
}

void Gui::displayPlayers() {

	PlayerList pList = game.getPlayerList();
	Player * p;
	bool turn;
	bool button;
	bool faceUp;
	Point loc;

	for (int i = 0; i < pList.getSize(); i++) {
		p = pList.getCurrentPlayer();
		if (p->getNum() == 0) {
			displayUserRegion(*p);
		} else {
			turn = (p->getNum() == game.getCurrentNum());
			button = (p->getNum() == game.getButNum());
			faceUp = game.getHandsUp();
			loc = gameLayout.getPlayerInfoArea(p->getNum() - 1);
			gameDisplay.displayPlayerInfo(*p, turn, button, faceUp, loc);
		}
		pList.iterate();
	}

}

void Gui::displayUserRegion(Player p) {
	int i;
	int attr = A_NORMAL | COLOR_PAIR(4);
	Point loc;
	SmallDeck pocket;
	bool button;

	if (game.getCurrentNum() == 0) {
		attr = A_NORMAL | COLOR_PAIR(2);
	}

//display player's cards
	pocket = *p.getPocket();
	loc = gameLayout.getPlayerCardArea(0);
	button = (game.getButNum() == 0);
	gameDisplay.drawBox(loc, gameDisplay.getCols(), CARDH + 2, button, attr);
	for (i = 0; i < 2; i++) {
		loc = gameLayout.getPlayerCardArea(i + 1);
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
