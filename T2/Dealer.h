/* Dealer.h
 *
 * Author: Eli Siskind
 *
 */

#ifndef DEALER_H
#define DEALER_H

#include "Card.h"
#include "Deck.h"
#include "MainDeck.h"

using namespace std;

class Dealer
{
public:
	Dealer();
	~Dealer();
	void makeDeck();
	void resetDeck();
	Card* deal();
	void discard(Card * card);
	void discard(Deck * deck);
	void burn();
	void deleteAll();
private:
	MainDeck * mainDeck;
	Deck * discardDeck;
};

#endif
