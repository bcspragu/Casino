/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 *
 *      Stub
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
protected:
	int money;
	bool folded;
public:
	Player();
	Player(int num);
	virtual ~Player();
	bool inRound();
	void fold();
	void takeMoney(int amt);
	int getMoney();
	void unFold();
};

#endif /* PLAYER_H_ */
