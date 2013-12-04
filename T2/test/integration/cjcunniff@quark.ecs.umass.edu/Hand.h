#ifndef HAND_H
#define HAND_H

class SmallDeck;

class Card;
class Deck;
class Player;

class Hand
{
	public:
		Hand(Player * p);
		Hand();
		~Hand();
		int operator > (Hand);
		Card* cardArray;
		void putInCards(SmallDeck pocket, SmallDeck community);
		void evaluateCards();
		Player * getPlayer();

	private:
		Player * player;
		int length;
		int valid;
		int type;
		int tieBreaker;
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
