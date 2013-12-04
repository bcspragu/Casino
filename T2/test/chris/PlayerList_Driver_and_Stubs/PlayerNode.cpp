/**
 * PlayerNode.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 *
 *      Stub
 */

#include "PlayerNode.h"
#include <iostream>

PlayerNode::PlayerNode(Player* player) {
	 data = player;
	 next = NULL;
	 prev = NULL;
}

PlayerNode::~PlayerNode() {
	delete data;
}

Player* PlayerNode::getPlayer() {return data;}
