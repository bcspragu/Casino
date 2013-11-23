/**
 * PlayerList.h
 *
 *  Created on: Nov 5, 2013
 *      Author: Eli Siskind
 * Description: This defines the members of the PlayerList class, a circularly
 * 				linked list of Player objects.
 */

#ifndef PLAYERLIST_H
#define PLAYERLIST_H

//#include "Player.h"

class Player;

using namespace std;

class PlayerList {
private:
	Player* current;	// Current node
	int size;			// Number of entries in list
public:

	// constructor and destructor
	PlayerList();
	~PlayerList();

	// functions for manipulating list
	void add(Player* player);
	Player * remove();
	Player * next();

	// functions for getting information from list
	Player * peek();
	int getSize();
	bool isEmpty();

	// print function for debugging
	void print();
};

#endif /* PLAYERLIST_H_ */
