/*
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include "Bet.h"
//#include "Hand.h"
//#include "Pot.h"
#include "Player.h"
#include "Deck.h"
#include "SmallDeck.h"

class Player {
protected:
	Card* cards;
	int money;
	bool folded;
	SmallDeck deck;
public:
	Player();
	~Player();
	bool inRound();
	void giveCard(Card * card);
	SmallDeck show();
	virtual Bet * makeBet(int amount);
	void fold();
	int getMoney();
//	void takePot(Pot p);
	void unFold();
	Card* discard();
};

#endif /* PLAYER_H_ */
