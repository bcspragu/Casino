/*
 * Game.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Eli
 */

#ifndef GAME_H
#define GAME_H

#include "Bet.h"
#include "Gui.h"

class Dealer;
class Hand;
class PlayerList;
class SmallDeck;
class Bet;
class Player;

class Game {
public:
	Game();
	~Game();
	bool startGame();
	bool playRound();
	void endGame();
	Player * getWinner();
	Gui getGui(){return gui;}
	int getState(){return state;}
	int getButNum();
	friend class Gui;
	friend class Layout;
private:
	Gui gui;
	Dealer * dealer;
	PlayerList * playerList;
	SmallDeck * commCards;
	Player * winner;
	int minBet;
	int centerPot;
	int numFolded;
	int state;
	int userInputState;
	int currentPlayer;
	Bet currentBet;

	//functions for game control
	void processBet(Bet bet, Player * p);
	void initialTurns();
	void initialBets();
	void givePlayerCards();
	void big();
	void little();
	bool makeBets();
	void blinds();
	bool flop();
	bool turn();
	bool river();
	void endRound();
	void discardAll();
	Hand* findBestHand();
};

#endif /* GAME_H */
