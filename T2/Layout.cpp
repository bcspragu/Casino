/*
 * Layout.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: Eli Siskind
 */

#include "Layout.h"
#include <sstream>
#include <iostream>

#include "Point.h"
#include "Card.h"

using namespace std;

Layout::Layout() {

}

Layout::~Layout() {

}

// Recalculate each point for the new display size
void Layout::setup(int x, int y) {

	setSize(x, y);
	setCenter();
	setDeckArea();
	setDiscardArea();
	setCommCardArea();
	setCenterPotArea();
	setPlayerInfoArea();
	setPlayerCardArea();
	setPlayerPotArea();

}

//set new size
void Layout::setSize(int x, int y) {
	size.set(x, y);
}

//set new center
void Layout::setCenter() {
	int x = size.getX() / 2;
	int y = size.getY() / 2;
	center.set(x, y);
}

//set new deck area
void Layout::setDeckArea() {
	int x = center.getX() + CARDW;
	int y = center.getY() - (2 + CARDH);
	deckArea.set(x, y);
}

// set the new discard area
void Layout::setDiscardArea() {
	int x = 1;
	int y = size.getY() - CARDH * 2 - 3;
	discardArea.set(x, y);
}

//set the community card areas
void Layout::setCommCardArea() {
	int i;
	int x = center.getX() - 3 * CARDW;
	int y = center.getY();

	commCardArea[0].set(x - 2, y - 1);
	for (i = 1; i <= 5; i++) {
		commCardArea[i].set(x, y);
		x += CARDW;
	}
}

//set the center pot area
void Layout::setCenterPotArea() {
	int x = center.getX() - 3 * CARDW - 2;
	int y = center.getY() - CARDH;
	centerPotArea.set(x, y);
}

//set the player info area
void Layout::setPlayerInfoArea() {
	int i;
	int x = 1;
	int y = 1;

	for (i = 0; i < PLAYERNUM; i++) {
		playerInfoArea[i].set(x, y);
		x += 2 * CARDW + 2;
	}
}

//set the player card area
void Layout::setPlayerCardArea() {
	int i;
	int x = center.getX() - 2 * CARDW;
	int y = size.getY() - CARDH - 2;

	playerCardArea[0].set(0, y - 1);
	for (i = 1; i <= 2; i++) {
		playerCardArea[i].set(x, y);
		x += CARDW;
	}
}

//set the player pot area
void Layout::setPlayerPotArea() {
	int x = center.getX() + CARDW;
	int y = size.getY() - CARDH - 2;
	playerPotArea.set(x, y);
}

Point Layout::getSize() {
	return size;
}

Point Layout::getCenter(){
	return center;
}

Point Layout::getDeckArea() {
	return deckArea;
}

Point Layout::getDiscardArea() {
	return discardArea;
}

Point Layout::getCommCardArea(int i) {
	return commCardArea[i];
}

Point Layout::getPlayerInfoArea(int i) {
	return playerInfoArea[i];
}

Point Layout::getPlayerCardArea(int i) {
	return playerCardArea[i];
}

Point Layout::getCenterPotArea() {
	return centerPotArea;
}

Point Layout::getPlayerPotArea() {
	return playerPotArea;
}

