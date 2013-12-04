/**
 * PlayerNode.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 *
 *      Stub
 */

#ifndef PLAYERNODE_H_
#define PLAYERNODE_H_

#include "Player.h"
class PlayerList;

class PlayerNode {
private:
	Player* data;
	PlayerNode* next;
	PlayerNode* prev;
public:
	PlayerNode(Player* player);
	~PlayerNode();
	Player* getPlayer();
	friend class PlayerList;
};
#endif /*PLAYERNODE_H_*/
