/**
 * HumanPlayer.h
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Bet.h"
#include "Player.h"

using namespace std;

class HumanPlayer : public Player {
public:
	HumanPlayer(int num);
	Bet makeBet(SmallDeck d, int minBet, int state);
};

#endif /* HUMANPLAYER_H_ */
