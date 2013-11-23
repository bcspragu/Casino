/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

#include "Card.h"
#include "Bet.h"
#include "Player.h"
#include "Deck.h"
#include "SmallDeck.h"
#include "Game.h"

class Player {
protected:

	// for playerlist linked list
	Player* next;
	Player* prev;

	// member variables for gameplay
	int playerNum;
	int money;
	bool folded;
	SmallDeck * pocket;

public:

	// constructors and destructors
	Player();
	Player(int num);
	virtual ~Player();

	// functions for game play
	virtual Bet makeBet(SmallDeck comm, int minBet, GameState state);
	Bet makeBig(int minBet);
	Bet makeLittle(int minBet);
	void giveCard(Card * card);
	SmallDeck* fold();
	void takePot(int pot);
	void unFold();

	// getters
	int getNum() {return playerNum;}
	int getMoney(){return money;}
	SmallDeck* getPocket(){return pocket;}
	bool isFolded(){return folded;}

	// print for debugging
	void print();

	// playerList can access prev and next
	friend class PlayerList;
};

#endif /* PLAYER_H */
