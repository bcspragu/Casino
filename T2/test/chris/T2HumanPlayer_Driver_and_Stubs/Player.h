/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Bet.h"
#include "Player.h"
#include "SmallDeck.h"

class Player {
	public:
	int playerNum;
	int money;
	bool folded;
	Player();
	Player(int num);
	virtual ~Player();
	virtual Bet makeBet(SmallDeck comm, int minBet);
};

#endif /* PLAYER_H_ */
