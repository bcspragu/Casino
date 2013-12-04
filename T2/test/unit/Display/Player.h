/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Card.h"
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
	int getMoney();
	void print();
};

#endif /* PLAYER_H_ */
