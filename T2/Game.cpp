/**
 * Game.cpp
 *
 *  Created on: Oct 31, 2013
 *      Authors: Eli Siskind & Kyle Despins
 */

#include "Game.h"

#include <cmath>
#include <iostream>
#include <assert.h>

#include "Bet.h"
#include "ComputerPlayer.h"
#include "Dealer.h"
#include "Deck.h"
#include "GameData.h"
#include "Gui.h"
#include "Hand.h"
#include "HumanPlayer.h"
#include "Player.h"
#include "PlayerList.h"
#include "SmallDeck.h"

using namespace std;

Game::Game() {
	state = NEWGAME;
	centerPot = 0;
	minBet = 20;
	numFolded = 0;
	showCompCards = true;
	button = NULL;
	winner = NULL;
	current = NULL;
	roundWinner = NULL;
	commCards = new SmallDeck();
	roundNum = 0;
	lastBet = Bet(INVALID, 0);
	cardsPlayed = 0;

}

Game::~Game() {

}

/*
 * Prompt user for a new game; if yes, create players and dealer.
 *
 * Player 1 is the human player, players 2 - 9 are computer.
 *
 * Returns true if a new game is started, and returns false otherwise.
 *
 */
bool Game::startGame(int startMoney) {

	// Make sure user wants to start a new game
	if (gui.startGui()) {

		// Dealer populates the deck
		dealer.makeDeck();

		// Create and add human player, make it the button
		HumanPlayer * human = new HumanPlayer(1, gui, startMoney); // Player 1
		playerList.add(human);
		button = human;

		// Make and add 8 computer players
		int i;
		for (i = 2; i <= 9; i++) {
			ComputerPlayer * computer = new ComputerPlayer(i);
			playerList.add(computer);
		}
		state = NEWGAME;
		return true; // Start a game
	}
	return false; // Don't start a game
}

/*
 * Plays another round if no one has one yet.
 *
 * Returns true if a new game is started, and returns false otherwise.
 *
 */
bool Game::playRound() {
	numFolded = 0;
	gui.newAd();
	if (newRound()) {
		if (!initialTurns()) {
			if (!flop()) {
				if (!turn()) {
					if (!river()) {
						updateGui(3);	// Show cards
						compareHands();
					}
				}
			}
		}
		return endRound();
	}

	return false;
}

/*
 * Checks if someone has won the game. If not, resets some variables for
 * a new round.
 *
 * First it sets the new min bet, then removes losers. If only one player
 * is left, they are the winner. Otherwise, state is set to 0, dealer shuffles
 * the deck, the round number is incremented, and the button is advanced.
 *
 *
 * Returns true if no one has won the game yet.
 */
bool Game::newRound() {

	bool gameOver;

	// Reset minBet. Doubles every five turns.
	minBet = 20 * pow(2, floor(roundNum / 5));

	// Remove the losers and advance the button
	purge();
	advanceButton();

	// Check if there is only one player left
	if (playerList.getSize() > 1) {

		// Reset everything for a new round
		state = NEWROUND;
		dealer.resetDeck();
		roundNum++;
		updateGui(0);
		button = playerList.next();
		gameOver = false;

	} else {
		winner = playerList.peek();
		gameOver = true;
	}
	return !gameOver;
}

bool Game::initialTurns() {

	//Start at the button
	goToButton();

	// Make big and little
	little();
	big();

	// Deal cards and bet
	givePlayerCards();
	return makeBets();

}

/*
 * Give each player a card, one at a time, and update the gui each time.
 */
void Game::givePlayerCards() {

	current = NULL;
	for (int i = 0; i < playerList.getSize() * 2; i++) {
		playerList.next()->giveCard(dealer.deal());
		updateGui(1);
	}
	cardsPlayed += 2;
}

void Game::little() {

	// Set current player and process their bet
	current = playerList.next();
	Bet bet = current->makeLittle(minBet);
	processBet(bet);

}

void Game::big() {

	// Set current player and process their bet
	current = playerList.next();
	Bet bet = current->makeBig(minBet);
	processBet(bet);

}

bool Game::flop() {

	minBet = 0;			// Players can check (AKA call 0) now
	state = FLOP;		// Update state
	goToButton();		// Make sure betting starts after the button

	// Dealer puts out three community cards
	dealer.burn();
	commCards->add(dealer.deal());
	updateGui(1);
	commCards->add(dealer.deal());
	updateGui(1);
	commCards->add(dealer.deal());
	updateGui(1);

	// Make bets, returning true if there is a winner
	return makeBets();

}

bool Game::turn() {

	minBet = 0;			// Players can check (AKA call 0) now
	state = TURN;		// Update state
	goToButton();		// Make sure betting starts after the button

	// Dealer puts out a community card
	dealer.burn();
	commCards->add(dealer.deal());
	updateGui(1);

	// Make bets, returning true if there is a winner
	return makeBets();

}

bool Game::river() {

	minBet = 0;			// Players can check (AKA call 0) now
	state = RIVER;		// Update state
	goToButton();		// Make sure betting starts after the button

	// Dealer puts out a community card
	dealer.burn();
	commCards->add(dealer.deal());
	updateGui(1);

	// Make bets, returning true if there is a winner
	return makeBets();
}

bool Game::makeBets() {
	Bet bet;

	// Each non-folded player makes a bet
	for (int i = 0; i < playerList.getSize(); i++) {

		current = playerList.next();
		updateGui(0);

		if (!current->isFolded()) {
			bet = current->makeBet(*commCards, minBet, state);
			processBet(bet);
			// If there is only one player left, the round is over
			if (numFolded > (playerList.getSize()) - 2) {
				while (playerList.peek()->isFolded()) {
					playerList.next();
				}
				roundWinner = playerList.peek();
				assert(roundWinner != NULL);
				assert(!roundWinner->isFolded());
				return true;
			}
		}
	}
	return false; // More than one player left
}

void Game::processBet(Bet bet) {

	// Fold the current player if their bet was to fold
	if (bet.getAction() == FOLD) {
		dealer.discard(current->fold());
		numFolded++;
	}

	// Add to the center pot, and change minimum bet if someone raised
	centerPot += bet.getAmount();
	minBet = minBet < bet.getAmount() ? bet.getAmount() : minBet;

	// Update the gui
	lastBet = bet;
	updateGui(2);
}
/*
 * Gives the roundwinner the pot, discards all the cards, and updates the GUI.
 */
bool Game::endRound() {

	if (gui.showRoundWinner(roundWinner->getNum(), centerPot, roundNum)) {
		roundWinner->takePot(centerPot);
		centerPot = 0;
		discardAll();
		updateGui(0);
		roundWinner = NULL;
		state = NEWROUND;
		return true;
	}
	return false;
}

/*
 * Compares the hands of each player, and sets roundWinner to
 * the player with the best hand
 */
void Game::compareHands() {

	Hand best;
	Hand temp;

	// First assume the first non folded player has the best hand
	current = playerList.peek();
	while (current->isFolded())
		current = playerList.next();
	roundWinner = current;
	best.evaluate(*current->getPocket(), *commCards);

	// Loop around the player list once and compare each hand
	for (int i = 0; i < playerList.getSize(); i++) {
		current = playerList.next();

		// only evaluate non-folded players
		if (!current->isFolded()) {

			// replace best if the current hand is better
			temp.evaluate(*current->getPocket(), *commCards);
			if (!(best > temp)) {
				best = temp;
				roundWinner = current;
			}
		}
	}
}

void Game::discardAll() {

	// Discard each player's pocket
	Player * start = playerList.peek();
	dealer.discard(playerList.peek()->getPocket());
	while (playerList.next() != start) {
		dealer.discard(playerList.peek()->getPocket());
	}

	// Discard community cards
	dealer.discard(commCards);
}

/*
 * Removes all players who cannot make the minimum bet, and adds their
 * money to the center pot.
 *
 * Returns true if the button has been removed.
 */
bool Game::purge() {
	int i;
	bool removedButton = false;
	Player * player = playerList.peek();	// Start at the first player
	int size = playerList.getSize();		// Save size since it changes

	// Loop around the player list once and remove players
	for (i = 0; i < size; i++) {
		if (player->getMoney() < minBet) {
			centerPot += player->getMoney();
			if (playerList.remove() == button) {	// advance the button
				removedButton = true;
				player = playerList.next();
				button = player;
			} else {
				player = playerList.next();
			}
		} else {
			player->unFold();
			player = playerList.next();
		}
	}

	return removedButton;
}

/*
 * Advances the button to the player after the current button.
 */
void Game::advanceButton() {

	// Go to the button
	goToButton();
	button = current;
}

/*
 * Advances the playerlist and until the button, and sets current to it.
 */
void Game::goToButton() {

	// Go to the button
	while (playerList.peek() != button)
		current = playerList.next();
}

//show winner and delete pointers for cards and players
int Game::endGame() {

	int humanMoney;

	// Show the winner
	if (winner != NULL) {
		gui.showWinner(winner->getNum());
	}
	// Remove players, discard their cards, and delete their pointers
	Player * player;
	while (playerList.peek() != NULL) {
		player = playerList.remove();
		if (player->getNum() == 1) {
			humanMoney = player->getMoney();
		}
		dealer.discard(player->getPocket());
		delete player;
	}

	// Discard community cards and delete all the card pointers
	dealer.discard(commCards);
	dealer.deleteAll();

	return humanMoney;
}

void Game::updateGui(int status) {

	// Update the game data object
	gameData.updateButton(button);
	gameData.updateCurrent(current);
	gameData.updatePlayers(playerList, (status == 3));
	gameData.updateCommunityCards(*commCards, state);
	gameData.setCenterPot(centerPot);
	gameData.setMinBet(minBet);
	gameData.setBet(lastBet);

	// Update the gui
	gui.update(gameData, status);

}
