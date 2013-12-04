/**
 * ComputerPlayer.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

//#include "Bet.h"
#include "Player.h"

class Bet;
class SmallDeck;

class ComputerPlayer : public Player {
public:
	ComputerPlayer(int num);
	Bet makeBet(SmallDeck C, int minBet);
};

#endif /* COMPUTERPLAYER_H_ */
