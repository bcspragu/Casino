/**
 * PlayerList.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "PlayerList.h"
#include "PlayerNode.h"
#include <iostream>

#define NUMBER_OF_PLAYERS 8

PlayerList::PlayerList() {
	head = NULL;
	tail = NULL;
	length = 0;
	current = NULL;
	button = NULL;

}

PlayerList::~PlayerList() {

}

Player * PlayerList::getCurrentPlayer() {
	if (current == NULL)
		return NULL;
	else
		return current->getPlayer();
}

void PlayerList::next() {
	do {
		if (current->next == NULL)
			current = head;
		else
			current = current->next;
	} while (!(current->getPlayer()->inRound()));	//skip folded players
}

void PlayerList::iterate() {

	if (current->next == NULL)
		current = head;
	else
		current = current->next;

}

/*
 * reset folded status
 * advance dealer
 * remove players without enough money from game
 */
int PlayerList::purge(int minBet) {

	// variables
	int leftover = 0;
	Player * p;
	PlayerNode *oldButton=button;

	current = head;
	int k;
	int L=length;
	for(k=0; k<L;k++){
		p = current->getPlayer();
		p->print();
		p->unFold();
		if (p->getMoney() <= minBet) {
			leftover += p->getMoney();
			remove();
		} 
		else {
			iterate();
		}
	}
	iterate();	

	// advance button and set current player
	if(oldButton==button)
		advanceButton();
	current = button;
	next();

	return leftover;
}

void PlayerList::advanceButton() {

	if (button->next == NULL) {
		button = head;
	} else {
		button = button->next;
	}

}

Player * PlayerList::getButton() {
	if (button != NULL)
		return button->getPlayer();
	else
		return NULL;
}

void PlayerList::addPlayer(Player* player) {
	if (head == NULL)
		head = tail = new PlayerNode(player);
	else {
		PlayerNode* newNode = new PlayerNode(player);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		tail->next = NULL;
		head->prev = NULL;
	}
	button = head;
	if (head->next != NULL) {
		current = head->next;
	} else
		current = head;
	length++;
}

void PlayerList::remove() {

	PlayerNode * pNode = current;

	if (pNode == button && length > 1) {
		advanceButton();
	}
	if (length == 0) {
		length++;
	} else if (length == 1) {

		current = head = tail = button = NULL;
	} else if (pNode == head) {

		head = head->next;
		current = head;
		head->prev = NULL;

	} else if (pNode == tail) {

		tail = tail->prev;
		tail->next = NULL;
		current = head;

	} else {
		current = current->next;
		pNode->prev->next = pNode->next;
		pNode->next->prev = pNode->prev;

	}
	length--;
	delete pNode;
}

int PlayerList::getSize() {
	return length;
}

void PlayerList::reset() {
	current = head;
	//cout << "Reset" << endl;
}

void PlayerList::print() {
	// print each node
	for (int i = 0; i < length; i++) {
		if (current != NULL)
			current->print();
		iterate();
	}

	// print the head
	cout << "Head: ";
	if (head != NULL)
		head->print();

	// print the tail
	cout << "Tail: ";
	if (tail != NULL)
		tail->print();

	// print the button
	cout << "Butt: ";
	if (button != NULL)
		button->print();
		
	// print the current
	cout << "Curr: ";
	if (current != NULL)
		current->print();
		
	// print the length
	cout << "Length: " << length << endl;
}

void PlayerList::removeAll() {
	while (length > 0) {
		remove();
	}
}
