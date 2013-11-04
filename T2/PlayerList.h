/**
 * PlayerList.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYERLIST_H_
#define PLAYERLIST_H_

#include "Player.h"
#include "PlayerNode.h"

using namespace std;

class PlayerList {
private:
	PlayerNode* head;
	PlayerNode* tail;
	PlayerNode* button;	//dealer
	PlayerNode* current;
	int length;	//number of entries in list

public:
	void addPlayer(Player* player);
	PlayerList();
	~PlayerList();
	Player * getCurrentPlayer();
	void next();
	void iterate();
	int purge(int minBet);
	Player * getButton();	
	int getSize();
	void print();
	void remove();
	void removeAll();
	void advanceButton();
	void reset();
};

#endif /* PLAYERLIST_H_ */
