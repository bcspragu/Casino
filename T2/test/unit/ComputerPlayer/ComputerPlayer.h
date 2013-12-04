/*
 * ComputerPlayer.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Bet.h"
#include "Player.h"
#include "Card.h"
#include "Hand.h"

class ComputerPlayer : public Player {
public:
	//ComputerPlayer ();
	Bet* makeBet(SmallDeck C, int min);
};

#endif /* COMPUTERPLAYER_H_ */
