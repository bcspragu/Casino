/* Module of functions for running the game and changing the display
 *
 * NOTES:
 *      * Requires the terminal (Putty) to be set to UTF-8.
 *      * Does not function when running a screen session.
 */

#include "Gui.h"

#include <iostream>

#include "Bet.h"
#include "Game.h"
#include "PlayerList.h"
#include "Player.h"

using namespace std;

extern Game game;

Gui::Gui() {

}

Gui::~Gui() {

}

// Function for running the game
bool Gui::startGui(void) {
	return true;
}

void Gui::showTurn(int player, Bet bet){
	cout << bet.getAmount() << endl;
	cout << "Player " << player << " " << bet.print() << endl;
}

void Gui::update(){
	cout << endl;
	game.playerList->print();
	cout << "Center Pot: " << game.centerPot << endl;
	game.commCards->print();
}
