/*
 * GameData.h
 *
 *  Created on: Nov 7, 2013
 *      Author: Eli Siskind
 * Description: This class stores game data to pass to the game display.
 */

#ifndef GAMEDATA_H
#define GAMEDATA_H

using namespace std;

#include "GameState.h"
#include "Bet.h"
#include "Card.h"

class Player;
class PlayerList;
class SmallDeck;

class GameData {
public:

	// Default constructor and destructor
	GameData();
	~GameData();

	// Update functions called by game
	void updatePlayers(PlayerList pList, bool showCards);
	void updateCommunityCards(SmallDeck community, GameState state);
	void updateButton(Player * buttonPlayer);
	void updateCurrent(Player * currentPlayer);

	// Setters
	void setPlayerCard(int playerNum, int cardNum, Card newCard);
	void setCommunityCard(int cardNum, Card newCard);
	void setCenterPot(int amount){centerPot = amount;}
	void setPlayerMoney(int playerNum, int amount);
	void setButton(int buttonNum){button = buttonNum;}
	void setCurrent(int currentNum){current = currentNum;}
	void setBet(Bet newBet){currentBet = newBet;}
	void setMinBet(int amount){minBet = amount;}

	// Getters
	Card getPlayerCard(int playerNum, int cardNum);
	Card getCommunityCard(int cardNum);
	int getCenterPot(){return centerPot;}
	int getButton(){return button;}
	int getCurrent(){return current;}
	int getPlayerMoney(int playerNum);
	int getMinBet(){return minBet;}
	Bet getBet(){return currentBet;}

private:

	// Variables for storing game information
	Card communityCards[5];
	Card playerCards[9][2];
	int centerPot;
	int playerMoney[9];
	int button;
	int current;
	int minBet;
	Bet currentBet;
};

#endif /* GAMEDATA_H */
