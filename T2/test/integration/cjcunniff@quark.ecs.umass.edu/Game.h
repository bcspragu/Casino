/*
 * Game.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Eli
 */

#ifndef GAME_H_
#define GAME_H_

//#include "Bet.h"
//#include "Dealer.h"
#include "Gui.h"
//#include "Hand.h"
//#include "PlayerList.h"

class Dealer;
class Hand;
class PlayerList;
class SmallDeck;

class Player;

class Game {
public:
	Game();
	~Game();
	bool startGame();
	void playRound();
	void endGame();
	Player * getWinner();
	Gui getGui(){return gui;}
	int getState(){return state;}
	friend class Layout;
	friend class Gui;
private:
	Gui gui;
	Dealer * dealer;
	PlayerList * playerList;
	SmallDeck * commCards;
	Player * winner;
	int minBet;
	int centerPot;

	//functions for game control
	void initialTurns();
	void initialBets();
	void givePlayerCards();
	void big();
	void little();
	void makeBets();
	void blinds();
	void flop();
	void turn();
	void river();
	void endRound();
	void discardAll();
	Hand* findBestHand();
	int state;
};

#endif /* GAME_H_ */
