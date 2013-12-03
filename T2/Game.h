/**
 * Game.h
 *
 *  Created on: Oct 31, 2013
 *      Authors: Eli Siskind & Kyle Despins
 */

#ifndef GAME_H
#define GAME_H

#include "Bet.h"
#include "Dealer.h"
#include "GameData.h"
#include "GameState.h"
#include "Gui.h"
#include "PlayerList.h"
#include "SmallDeck.h"

class Player;

using namespace std;

class Game {
public:

	Game();
	~Game();

	// game control
	bool startGame(int money);
	bool playRound();
	int endGame();

	// getters
	Player * getWinner(){return winner;}
	Gui getGui(){return gui;}
	int getState(){return state;}
	PlayerList getPlayerList(){return playerList;}
	SmallDeck getCommCards(){return *commCards;}
	int getCardsPlayed() {return cardsPlayed;}

private:

	// Pointers for some things
	SmallDeck * commCards;	// Community cards
	Player * winner;		// Assigned when someone wins the gane
	Player * roundWinner;	// Assigned when someone wins the round
	Player * button;		// For keeping track of who should go next
	Player * current;		// Number of the player whose turn it is

	// Objects in the game
	Gui gui;				// The user interface
	Dealer dealer;			// Holds the main deck and discard pile
	PlayerList playerList;	// List of all the players in the game
	Bet lastBet;			// Set after someone makes a bet

	// Variables for game status information
	GameState state;		// The state of the game
	int minBet;				// The current minimum betting amount
	int roundNum;			// The round number
	int centerPot;			// Amount in the center pot
	int numFolded;			// How many players have folded this round
	bool showCompCards;		// If cards should be shown

	int cardsPlayed;	//store cards played during game

	// Variables for sending to the gui
	GameData gameData; // For sending to the gui

	//functions for game control
	void processBet(Bet bet);
	void goToButton();
	void advanceButton();
	bool initialTurns();
	void givePlayerCards();
	void big();
	void little();
	bool makeBets();
	void blinds();
	bool flop();
	bool turn();
	bool river();
	void compareHands();
	void showCards();
	bool newRound();
	bool purge();
	bool endRound();
	void discardAll();
	void resetPlayerList();
	void setGameData();
	void updateGui(int status);
};

#endif /* GAME_H */
