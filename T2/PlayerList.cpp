/**
 * PlayerList.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: Eli Siskind
 * Description: This class is a circularly linked list of Player objects.
 *
 */

#include "PlayerList.h"
#include "Player.h"

#include <iostream>

PlayerList::PlayerList() {
	current = NULL;
	size = 0;
}

PlayerList::~PlayerList() {

}

/* Adds a player to the list before
 *
 * The new player will be the new current node.
 *
 */
void PlayerList::add(Player* player) {

	if (player == NULL){
		return; // return without changing anything
	}
	else if (isEmpty()) {

		// current is the new player
		current = player;

		// reassign next and prev links to itself
		player->next = player;
		player->prev = player;

	} else {

		// reassign new player's links
		player->prev = current->prev;
		player->next = current;

		//reassign surrounding player's links
		current->prev->next = player;
		current->prev = player;
	}

	size++;
}


/*
 * Remove the current player from the list.
 *
 * The new current player is the next player after the removed player.
 *
 * Returns the removed player.
 */
Player* PlayerList::remove() {

	if (isEmpty()) {

		return NULL;

	} else {

		// reassign next link of prev node
		if (current->prev != current)
			current->prev->next = current->next;
		else	// current is last node left
			current->prev = NULL;

		// reassign prev link of next node
		if (current->next != current)
			current->next->prev = current->prev;
		else	// current is last node left
			current->next = NULL;

		// set new current, decrement size
		Player*temp = current;
		current = current->prev;	// Setting to prev so iterating through playerlist is not interupted
		size--;

		// strip links and return the removed node
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}
}

Player* PlayerList::next(){
	current = current->next;
	return current;
}

Player* PlayerList::peek(){
	return current;
}

int PlayerList::getSize(){
	return size;
}

bool PlayerList::isEmpty(){
	return (size == 0);
}

void PlayerList::print(){
	Player * start = current;
	do {
		current->print();
		current = current->next;
	} while (start != current);
}
