/**
 * Game.h
 *
 *  Created on: Oct 31, 2013
 *      Authors: Eli Siskind & Kyle Despins
 */

#ifndef GAME_H
#define GAME_H

#include "Bet.h"
#include "Gui.h"
#include "PlayerList.h"
#include "SmallDeck.h"

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

	// game control
	bool startGame();
	bool playRound();
	void endGame();

	// getters
	Player * getWinner();
	int getPot(){return centerPot;}
	Gui getGui(){return gui;}
	int getState(){return state;}
	int getRoundNum(){return roundNum;}
	int getButNum();
	int getMinBet(){return minBet;}
	int getCurrentNum(){return currentPlayer;}
	bool getHandsUp(){return handsUp;}
	int getUserInputState(){return userInputState;}
	PlayerList getPlayerList(){return *playerList;}
	SmallDeck getCommCards(){return *commCards;}
	Bet getCurrentBet(){return currentBet;}

	// setters
	void setUserInputState(int state){userInputState = state;}

	friend class Layout;

private:
	int roundNum;
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
	bool handsUp;

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
	void endRound(int roundWinner);
	void discardAll();
	Hand* findBestHand();
};

#endif /* GAME_H */
