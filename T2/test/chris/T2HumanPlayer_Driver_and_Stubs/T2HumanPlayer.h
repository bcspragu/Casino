/**
 * HumanPlayer.h
 *
 *  Created on: Oct 26, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef T2HUMANPLAYER_H_
#define T2HUMANPLAYER_H_

#include "Player.h"

class Bet;
class SmallDeck;

using namespace std;

class T2HumanPlayer : public Player {
public:
	T2HumanPlayer(int num, Gui gameGui, int startMoney);
	Bet makeBet(SmallDeck comm, int minBet, GameState state);
private:
	Gui gui;
};

#endif /* T2HUMANPLAYER_H_ */
