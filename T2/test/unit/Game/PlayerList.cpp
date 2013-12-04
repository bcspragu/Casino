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

/*
 * reset folded status
 * advance dealer
 * remove players without enough money from game
 */
int PlayerList::purge(int minBet) {

	// variables
	int leftover = 0;
	Player * p;

	//advanceButton();

	// iterate through entire list
	current = head;
	do {
		p = current->getPlayer();
		p->unFold();
		if (p->getMoney() <= minBet) {
			leftover += p->getMoney();
			remove();
		} else
			next();
	} while (current->next != NULL);

	// advance button and set current player
	current = button;
	next();

	return leftover;
}

void PlayerList::advanceButton() {
	cout << endl << "Advancing button" << endl;
	if (button->next == NULL){
		button = head;
	}
	else{
		button = button->next;
	}
	cout << endl;
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
	cout << "Removing: ";
	current->print();
	PlayerNode * pNode = current;

	if (pNode == button && length > 1) {
		advanceButton();
	}
	if (length == 0) {
		length++;
	} else if (length == 1) {
		cout << "Removing the last node: ";
		current = head = tail = button = NULL;
	} else if (pNode == head) {

		cout << "Removing head: ";
		head = head->next;
		current = head;
		head->prev = NULL;

	} else if (pNode == tail) {

		cout << "Removing tail: ";
		tail = tail->prev;
		tail->next = NULL;
		current = head;

	} else {
		cout << "Removing node: ";
		current = current->next;
		pNode->prev->next = pNode->next;
	}
	length--;
	delete pNode;
}

int PlayerList::getSize() {
	return length;
}

void PlayerList::reset(){
	current = head;
	cout << "Reset" << endl;
}

void PlayerList::print() {
	// print each node
	cout << endl << "Playerlist: ";
	for (int i = 0; i < length; i++) {
		if (current != NULL)
			current->print();
		next();
	}

	// print the head
	cout << endl << "Head: ";
	if (head != NULL)
		head->print();
	cout << endl;

	// print the tail
	cout << "Tail: ";
	if (tail != NULL)
		tail->print();
	cout << endl;

	// print the button
	cout << "Button: ";
	if (button != NULL)
		button->print();
	cout << endl;

	// print the length
	cout << "Length: " << length << endl;
}

void PlayerList::removeAll() {
	while (length > 0) {
		remove();
	}
}
