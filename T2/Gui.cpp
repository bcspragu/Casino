/* Gui.cpp
 *
 * Author: Eli Siskind
 * Description: Wrapper class for using the functionality of the display class.
 *
 */

#include "Gui.h"

#include <csignal>
#include <memory>
#include <sstream>
#include <string>

#include "Bet.h"
#include "Card.h"
#include "T2Display.h"
#include "GameData.h"
#include "Layout.h"
#include "PlayerList.h"
#include "Point.h"

extern T2Display T2GameDisplay;

Layout Gui::gameLayout;
GameData Gui::gameData;
int Gui::userInputState = 0;
Advertisement Gui::ad;
string Gui::advertisement;

Gui::Gui() {
	advertisement = ad.getAd();
}

Gui::~Gui() {

}

void Gui::newAd() {
	advertisement = ad.getAd();
}

// Function for running the game
bool Gui::startGui(void) {
	// enable resize detection
	signal(SIGWINCH, detectResize);

	// variables
	char key;
	stringstream ss;
	Point loc;
	Point size;

	gameLayout.setup(T2GameDisplay.getCols(), T2GameDisplay.getLines());
	T2GameDisplay.eraseScreen(true);

	// display the new game screen
	T2GameDisplay.bannerTop("New Game!");
	T2GameDisplay.bannerBottom("[Continue: c] [Exit: e]");

	// Draw border
	loc = gameLayout.getCenter();
	size.set(60, 4);
	loc.move(-size.getX() / 2, -2);
	T2GameDisplay.displayBox(loc, size, false, COLOR_PAIR(1));

	// Draw title
	ss.clear();
	ss.str("");
	ss << "New Game!";
	loc = gameLayout.getCenter();
	loc.move(0, -1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(3));

	// Draw line 2
	ss.clear();
	ss.str("");
	ss << "You are player 1.";
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(1));


	// infinite loop for the main program, you can press e to quit
	for (;;) {

		// calls the game display to capture some input
		key = T2GameDisplay.captureInput();

		// if a key was pressed
		if (key > 0) {

			// Return if 'e' or 'c' is pressed
			switch (key) {
			case 'e':	// User wants to exit
				return false;
				break;
			case 'c':	// User wants to continue
				return true;
				break;
			}
		}
	}
	return false;
}

bool Gui::showRoundWinner(int roundWinnerNum, int amount, int roundNum) {

	//variables
	stringstream ss;
	Point loc;
	Point size;
	char key;
	bool continueGame;

	gameLayout.setup(T2GameDisplay.getCols(), T2GameDisplay.getLines());
	T2GameDisplay.eraseScreen(true);

	// Draw border
	loc = gameLayout.getCenter();
	size.set(60, 5);
	loc.move(-size.getX() / 2, -2);
	T2GameDisplay.displayBox(loc, size, false, COLOR_PAIR(1));

	// Draw title
	ss.clear();
	ss.str("");
	ss << "End of round " << roundNum << "!";
	loc = gameLayout.getCenter();
	loc.move(0, -1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(3));

	// Draw line 2
	ss.clear();
	ss.str("");
	ss << "Player " << roundWinnerNum << " won:";
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(1));

	// Draw line 3
	ss.clear();
	ss.str("");
	ss << "$" << amount;
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(1));

	// Display info banners
	T2GameDisplay.bannerTop("Round ended.");
	T2GameDisplay.bannerBottom("[Next round: n]  [Exit: e]");

	// Infinite loop to wait for user input
	for (;;) {

		// Calls the game display to capture some input
		key = T2GameDisplay.captureInput();

		// Break if user presses 'n'
		if (key == 'n') {
			continueGame = true;
			break;
		} else if (key == 'e') {
			continueGame = false;
			break;
		}
	}
	return continueGame;
}

void Gui::showWinner(int winnerNum) {

	//variables
	stringstream ss;
	Point size;
	Point loc;
	char key;

	// Clear screen first
	T2GameDisplay.eraseScreen(true);

	// Draw border
	loc = gameLayout.getCenter();
	size.set(60, 5);
	loc.move(-size.getX() / 2, -2);
	T2GameDisplay.displayBox(loc, size, false, COLOR_PAIR(1));

	// Draw title
	ss.clear();
	ss.str("");
	ss << "Game over!";
	loc = gameLayout.getCenter();
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(3));

	// Draw line 2
	ss.clear();
	ss.str("");
	ss << "The winner is:";
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(1));
	ss.clear();

	// Draw line 3
	ss.clear();
	ss.str("");
	ss << "Player " << winnerNum;
	loc.move(0, 1);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, COLOR_PAIR(1));
	ss.clear();

	// Draw info banners
	T2GameDisplay.bannerTop("Game over.");
	T2GameDisplay.bannerBottom("[Exit: e]");

	// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = T2GameDisplay.captureInput();

		// if a key was pressed
		if (key == 'e')
			break;
	}
}

Bet Gui::getBetInput() {

	// Bet variables
	int amount;
	BetAction action;

	// Redraw and show top banner
	redraw();
	T2GameDisplay.bannerTop("Your turn to make a bet.");

	// Get action from user
	action = getBetAction();

	// Get amount based on action
	if (action == RAISE)
		amount = getBetAmount();
	else if (action == CALL)
		amount = gameData.getMinBet();
	else
		amount = 0;

	// reset input state flag
	userInputState = 0;

	return Bet(action, amount);
}

BetAction Gui::getBetAction() {

	// Variables
	char key;
	stringstream messageString;

	// Set flag in case of resize
	userInputState = 1;
	redraw();

	T2GameDisplay.bannerAd(advertisement);
	// Display prompt
	if (gameData.getMinBet() == 0)
		messageString << "Make a bet. [fold: f] [check: c ] [raise: r]";
	else
		messageString << "Make a bet. [fold: f] [call " << gameData.getMinBet()
				<< ": c ] [raise: r]";
	T2GameDisplay.bannerBottom(messageString.str());

	// Infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = T2GameDisplay.captureInput();

		// if a key was pressed
		if (key > 0) {

			//return a bet action depending on the key pressed
			switch (key) {
			case 'f':
				return FOLD;
				break;
			case 'c':
				return CALL;
				break;
			case 'r':
				return RAISE;
				break;
			}
		}
	}

	return INVALID;
}

int Gui::getBetAmount() {

	// variables
	char key;
	stringstream messageString;
	int amount;
	Point bannerLoc;
	Point bannerSize;

	amount = gameData.getMinBet();
	bannerLoc.set(0, T2GameDisplay.getLines() - 1);
	bannerSize.set(T2GameDisplay.getCols(), 1);

	// set flag in case of resize
	userInputState = 2;
	redraw();

	// infinite loop to wait for user input
	for (;;) {

		// Erase previous prompt
		T2GameDisplay.eraseBox(bannerLoc, bannerSize);

		// Display current prompt
		messageString << "Choose the amount to raise. Current amount: ";
		messageString << amount;
		messageString << " [+5: f] [+10: t] [+50: h] [+100: a] [Enter: e]";
		T2GameDisplay.bannerBottom(messageString.str());
		messageString.clear();
		messageString.str("");

		// calls the game display to capture some input
		key = T2GameDisplay.captureInput();

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

void Gui::update(GameData data, int status) {

	stringstream ss;
	unsigned int sec = 0;

	//set layout and game data, and clear screen
	gameData = data;
	redraw();

	switch (status) {
	case 0:	// No message or delay
		break;
	case 1:	// Dealing cards
		sec = 1;
		ss << "Dealing cards.";
		break;
	case 2: // A player's turn - show their bet
		sec = 15;
		ss << "Player " << gameData.getCurrent() << " "
				<< gameData.getBet().print();
		break;
	case 3: // Show hands
		sec = 30;
		ss << "Round ended.";
		break;
	default:
		break;
	}

	T2GameDisplay.bannerTop(ss.str());

	sleep(secs);

}

/*
 * This is the interrupt service routine called when the resize screen
 * signal is captured.
 */
void Gui::detectResize(int sig) {

	stringstream ss;

	// update the display class information with the new window size
	T2GameDisplay.handleResize(sig);

	// re-enable the interrupt for a window resize
	signal(SIGWINCH, detectResize);

	// Redisplay the layout
	redraw();

	if (userInputState == 1) {
		if (gameData.getMinBet() == 0)
			ss << "Make a bet. [fold: f] [check: c ] [raise: r]";
		else
			ss << "Make a bet. [fold: f] [call " << gameData.getMinBet()
					<< ": c ] [raise: r]";
		T2GameDisplay.bannerBottom(ss.str());
		T2GameDisplay.bannerTop("Your turn to make a bet.");
	} else if (userInputState == 2) {
		T2GameDisplay.bannerTop("Your turn to make a bet.");
	}

}

// Redraw the layout
void Gui::redraw() {

	gameLayout.setup(T2GameDisplay.getCols(), T2GameDisplay.getLines());
	T2GameDisplay.eraseScreen(false);
	string message;

	//only draw if screen is large enough
	if (gameLayout.getSize().getX() < 127 || gameLayout.getSize().getY() < 15) {

		message = "Please enlarge this window to properly view the game.";
		T2GameDisplay.bannerBottom(message);

	} else {

		// Redraw all elements on screen
		drawComputerPlayers();
		drawHumanPlayer();
		drawCommon();
		T2GameDisplay.bannerAd(advertisement);
	}

}

void Gui::drawComputerPlayers() {

	//variables
	int i;
	int color;
	stringstream ss;
	Point loc;
	Point size;
	Card card1;
	Card card2;

	size.set(2 * CARDW + 2, CARDH + 3);

	// Loop for drawing each player
	for (i = 1; i < 9; i++) {

		ss.clear();
		ss.str("");

		// Draw border
		if (i + 1 == gameData.getCurrent()) // Set different color for current player
			color = COLOR_PAIR(3);
		else
			color = COLOR_PAIR(1);
		loc = gameLayout.getPlayerInfoArea(i - 1);
		T2GameDisplay.displayBox(loc, size, (i + 1 == gameData.getButton()),
				color);

		// Draw title
		loc.move(size.getX() / 2, 1);
		ss << "P" << i + 1 << " $" << gameData.getPlayerMoney(i);
		T2GameDisplay.displayText(loc, ss.str(), CENTER, color);

		// Draw cards
		loc = gameLayout.getPlayerInfoArea(i - 1);
		card1 = gameData.getPlayerCard(i, 0);
		card2 = gameData.getPlayerCard(i, 1);
		loc.move(1, 2);
		T2GameDisplay.displayCard(loc, card1);
		loc.move(CARDW, 0);
		T2GameDisplay.displayCard(loc, card2);
	}
}

void Gui::drawHumanPlayer() {
	int color = COLOR_PAIR(1);
	Point loc;
	Point size;
	stringstream ss;

	// Draw border
	if (gameData.getCurrent() == 1)
		color = COLOR_PAIR(3);
	loc = gameLayout.getPlayerCardArea(0);
	size.set(T2GameDisplay.getCols(), CARDH + 2);
	T2GameDisplay.displayBox(loc, size, (gameData.getButton() == 1), color);

	//display player's cards
	for (int i = 0; i < 2; i++) {
		loc = gameLayout.getPlayerCardArea(i + 1);
		T2GameDisplay.displayCard(loc, gameData.getPlayerCard(0, i));
	}

	// Draw money info border
	size.set(20, 4);
	loc.move(10, 0);
	T2GameDisplay.displayBox(loc, size, false, COLOR_PAIR(2));

	// Draw money info text
	loc.move(size.getX() / 2, 1);
	ss << "Your money: " << gameData.getPlayerMoney(0);
	T2GameDisplay.displayText(loc, ss.str(), CENTER, color);
}

// display deck, discard pile, center pot, and community cards
void Gui::drawCommon() {
	int i;
	int color = COLOR_PAIR(1);
	Card card;
	Point loc;
	Point size;
	stringstream ss;

	// Draw center pot border
	size.set(CARDW * 5 + 4, 3);
	loc = gameLayout.getCenterPotArea();
	T2GameDisplay.displayBox(loc, size, false, COLOR_PAIR(2));

	// Draw center pot description
	loc.move(size.getX() / 2, 1);
	ss << "Center Pot: " << gameData.getCenterPot();
	T2GameDisplay.displayText(loc, ss.str(), CENTER, color);

	// Draw community card area
	loc = gameLayout.getCommCardArea(0);
	size.set(CARDW * 5 + 4, CARDH + 2);
	T2GameDisplay.displayBox(loc, size, true, color);

	// Draw community cards
	for (i = 0; i < 5; i++) {
		loc = gameLayout.getCommCardArea(i + 1);
		card = gameData.getCommunityCard(i);
		T2GameDisplay.displayCard(loc, card);
	}
}
