/**
 * ComputerPlayer.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Kyle Despins & Chris Cunniff
 */

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Game.h"
#include "Player.h"

class Bet;
class SmallDeck;

class ComputerPlayer : public Player {
public:
	ComputerPlayer(int num);
	Bet makeBet(SmallDeck comm, int minBet, GameState state);
private:
	Bet calculateBet(SmallDeck C, int minBet, GameState state);
};

#endif /* COMPUTERPLAYER_H_ */
