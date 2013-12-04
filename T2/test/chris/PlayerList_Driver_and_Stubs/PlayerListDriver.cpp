/**
 * PlayerListDriver.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: Christopher J. Cunniff
 *
 *	Driver
 *      tests class PlayerList
 *      functions:
 *      	addPlayer()
 *      	getCurrentPlayer()
 *      	next()
 *      	iterate()
 *      	purge()
 *      	getButton()
 *      	getSize()
 *      	remove()
 *      	removeAll()
 *      	advanceButton()
 *      	reset()
 */

#include <iostream>
#include <assert.h>
#include "PlayerList.h"

#define NUMBER_OF_PLAYERS 8

int main () {
	
	PlayerList list = PlayerList();

	//test for addPlayer(), getSize()
	//create a list of players, size NUMBER_OF_PLAYERS
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getSize() == i);
		list.addPlayer(new Player);
	}
	//the current player and are not initially equal
	assert(list.getCurrentPlayer() != list.getButton());

	//test for function iterate(), getCurrentPlayer(),
	//advanceButton(), getButton()
	//test iterating through the list
	Player* player = list.getCurrentPlayer();
	Player* dealer = list.getButton();
	for(int i = 0; i < NUMBER_OF_PLAYERS + 1; i++) {
		//test that dealer switches to new player until complete cycle
		list.advanceButton();
		if(i != NUMBER_OF_PLAYERS - 1)
			assert(dealer != list.getButton());
		else
			assert(dealer == list.getButton());

		list.iterate();

		//test that same player is reached until complete iteration of list
		if(i != NUMBER_OF_PLAYERS - 1)
			assert(list.getCurrentPlayer() != player);
		else
			assert(list.getCurrentPlayer() == player);
	}

	//test remove()
	//remove automatically iterates when removing
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getSize() == NUMBER_OF_PLAYERS - i);
		list.remove();
	}
	assert(list.getButton() == NULL);
	assert(list.getCurrentPlayer() == NULL);
	assert(list.getSize() == 0);

	//add more players back to list
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getSize() == i);
		list.addPlayer(new Player);
	}

	//test removeAll()
	list.removeAll();
	assert(list.getSize() == 0);

	//add more players to list
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getSize() == i);
		list.addPlayer(new Player);
	}

	//test reset()
	dealer = list.getButton();
	for(int i = 0; i < NUMBER_OF_PLAYERS*4; i++) {
		list.iterate();
		if (i%(NUMBER_OF_PLAYERS/2)) {
			assert(list.getCurrentPlayer() != dealer);
			list.reset();
			assert(dealer == list.getCurrentPlayer());
		}
	}

	//test next()
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		if(i%2) {
			list.getCurrentPlayer()->fold();
			assert(!list.getCurrentPlayer()->inRound());
		}
		list.iterate();
	}
	//make sure players that have folded are skipped
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getCurrentPlayer()->inRound());
		list.next();
	}

	//test purge()
	//set everyone to folded
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		list.getCurrentPlayer()->fold();
		assert(!list.getCurrentPlayer()->inRound());
		list.iterate();
	}
	list.purge(5);
	//test that folded status is reset
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		assert(list.getCurrentPlayer()->inRound());
		list.iterate();
	}
	//take away money from half of players so they
	//don't have enough for minimum bet
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++) {
		if (i % 2 == 0)
			list.getCurrentPlayer()->takeMoney(7);
		list.iterate();
	}
	//half of players have 3 coins
	//5 coins minimum are needed to stay in game
	list.purge(5);
	assert(list.getSize() == NUMBER_OF_PLAYERS / 2);


	std::cout << "-----test complete for PlayerList Driver-----" << std::endl;
	
	return 0;
}
