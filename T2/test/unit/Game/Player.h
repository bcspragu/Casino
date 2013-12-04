/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
#include "Bet.h"
#include "Player.h"
#include "Deck.h"
#include "SmallDeck.h"

class Player {
protected:
	int playerNum;
	int money;
	bool folded;
	SmallDeck * pocket;
public:
	Player();
	Player(int num);
	virtual ~Player();
	int getNum() {
		return playerNum;
	}
	bool inRound();
	void giveCard(Card * card);
	SmallDeck* getPocket();
	SmallDeck* fold();
	int getMoney();
	void takePot(int pot);
	void unFold();
	virtual Bet makeBet(SmallDeck comm, int minBet, int state);
	Bet makeBig(int minBet);
	Bet makeLittle(int minBet);
	void print();
};

#endif /* PLAYER_H_ */
