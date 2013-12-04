/**
 * Player.h
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#ifndef PLAYER_H
#define PLAYER_H

//#include "Card.h"
//#include "Bet.h"
//#include "Player.h"
//#include "Deck.h"
//#include "SmallDeck.h"

using namespace std;

class Player {
protected:
	int playerNum;
	//int money;
	bool folded;
	//SmallDeck * deck;
public:
	Player();
	Player(int num);
	virtual ~Player();
	int getNum() {
		return playerNum;
	}
	bool inRound();
	//void giveCard(Card * card);
	//SmallDeck* getDeck();
	void fold();
	//int getMoney();
	//void takePot(int pot);
	void unFold();
	//virtual Bet makeBet(int minBet);
	//Bet makeBig(int minBet);
	//Bet makeLittle(int minBet);
	void print();
};

#endif /* PLAYER_H */
