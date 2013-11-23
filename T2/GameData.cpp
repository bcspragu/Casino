/*
 * GameData.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Eli Siskind
 * Description: This class stores game data to pass to the game display.
 */

#include "GameData.h"

#include <iostream>
#include <string>

#include "Card.h"
//#include "Game.h"
#include "GameState.h"
#include "Player.h"
#include "PlayerList.h"
#include "SmallDeck.h"

using namespace std;

GameData::GameData() {

	button = 0;
	current = 0;
	centerPot = 0;
	minBet = 0;

}

GameData::~GameData() {

}

/*
 * Update the arrays of player money and cards to match playerList.
 *
 * If showCards is set to false, it only shows the back of cards for computer
 * players.
 */
void GameData::updatePlayers(PlayerList pList, bool showCards) {

	int pNum;
	Card card;

	Player * start = pList.peek();
	do {
		Player player = *pList.peek();
		pNum = player.getNum() - 1;
		setPlayerMoney(pNum, player.getMoney());
		if (player.isFolded()) {
			playerCards[pNum][0] = Card(0, 0);
			playerCards[pNum][1] = Card(0, 0);
		} else {
			for (int i = 0; i < 2; i++) {
				card = player.getPocket()->getCard(i);
				if (showCards || (pNum == 0) || card.isBlank())
					playerCards[pNum][i] = card;
				else
					playerCards[pNum][i] = Card(1, 1); // Show a face down card
			}
		}
	} while (pList.next() != start);
}

void GameData::updateCommunityCards(SmallDeck community, GameState state) {

	// First set all blank cards
	for (int i = 0; i < 3; i++) {
		communityCards[i] = community.getCard(i);
	}
	if (state == FLOP ) {
		for (int i = 0; i < 3; i++) {
			communityCards[i] = community.getCard(i);
		}

	}
	else if (state == TURN){
		for (int i = 0; i < 3; i++) {
			communityCards[i] = community.getCard(i+1);
		}
		communityCards[3] = community.getCard(0);
	}
	else if (state == RIVER){
		for (int i = 0; i < 3; i++) {
			communityCards[i] = community.getCard(i+2);
		}
		communityCards[3] = community.getCard(1);
		communityCards[4] = community.getCard(0);
	}
}

void GameData::updateButton(Player * buttonPlayer){
	if (buttonPlayer != NULL)
		button = buttonPlayer->getNum();
	else
		button =  -1;
}

void GameData::updateCurrent(Player * currentPlayer){
	if (currentPlayer != NULL)
		current = currentPlayer->getNum();
	else
		current = -1;
}

/*
 * Getters and setters for array objects are here instead of in the header file.
 */

void GameData::setPlayerCard(int playerNum, int cardNum, Card newCard) {
	playerCards[playerNum][cardNum] = newCard;
}

void GameData::setCommunityCard(int cardNum, Card newCard) {
	communityCards[cardNum] = newCard;
}

Card GameData::getPlayerCard(int playerNum, int cardNum) {
	return playerCards[playerNum][cardNum];

}

Card GameData::getCommunityCard(int cardNum) {
	return communityCards[cardNum];
}

void GameData::setPlayerMoney(int playerNum, int amount) {
	playerMoney[playerNum] = amount;
}

int GameData::getPlayerMoney(int playerNum) {
	return playerMoney[playerNum];
}

