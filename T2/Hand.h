/**
 * Hand.h
 *
 *  Created on: Oct 31, 2013
 *      Author: Kyle Despins
 */

#ifndef HAND_H
#define HAND_H

class SmallDeck;

class Card;
class Deck;
class Player;

class Hand
{
	public:
		Hand();
		~Hand();
		int operator > (Hand);
		Card* cardArray;
		void evaluate(SmallDeck pocket, SmallDeck community);
		int getType(){return type;}

	private:
		int length;
		int valid;
		int type;
		int tieBreaker;
		void solve();
		int pair();
		int twoPair();
		int threeOfaKind();
		int straight();
		int flush();
		int fullHouse();
		int fourOfaKind();
		void quickSort(Card arr[], int left, int right);

};

#endif
