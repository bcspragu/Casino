/**
 * HumanPlayer.h
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class Bet;
class SmallDeck;

using namespace std;

class HumanPlayer : public Player {
public:
	HumanPlayer(int num, Gui gameGui, int startMoney);
	Bet makeBet(SmallDeck comm, int minBet, GameState state);
private:
	Gui gui;
};

#endif /* HUMANPLAYER_H_ */
