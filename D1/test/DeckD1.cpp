#include "DeckD1.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Constructs an unshuffled deck of card pointers. Call shuffle before use
*/
DeckD1::DeckD1()
{
    std::srand(unsigned(std::time(0)));     //Seed rand()
    deckIndex = 51;
    for (int rank = 2; rank < 15; rank++) {     //14 card rankings
        for (int suit = 0; suit < 4; suit++){   //4 suits
        	CardD1* c1 = new CardD1(suit,rank);
            deck.push_back(c1);
        }
    }
}

/*
Destroys the calling deck object
*/
DeckD1::~DeckD1()
{
    for (int i = 0; i < 52; i++)
    {
    	delete deck.at(i);
    }
    discard.clear();
    deck.clear();
    deckIndex = 51;
}

/*
Sends a pointer to a Card to the discard pile
*/
void DeckD1::discardCard(CardD1* c1)
{
    if (discard.size() < 53)
    {
    	c1->setDiscarded(true);
        discard.push_back(c1);
    }
}

/*
Shuffles the current full deck of cards.
*/
void DeckD1::shuffle()
{
	discard.clear();
	for (int i = 0; i < 52; i++)
	{
		deck.at(i)->setDiscarded(false);
	}
    std::random_shuffle(deck.begin(),deck.end());
    deckIndex = 51;
}

/*
Returns a five card hand from the deck. Used only at the start of new rounds.
*/
HandD1* DeckD1::dealHand()
{
	/*CardD1* temp0 = deck.at(deckIndex);
	CardD1* temp1 = deck.at(deckIndex-1);
	CardD1* temp2 = deck.at(deckIndex-2);
	CardD1* temp3 = deck.at(deckIndex-3);
	CardD1* temp4 = deck.at(deckIndex-4);
	return new HandD1(temp0,temp1,temp2,temp3,temp4);*/
    HandD1 *h1 = new HandD1(deck[deckIndex], deck[deckIndex-1], deck[deckIndex-2], deck[deckIndex-3], deck[deckIndex-4]);
    deckIndex-=5;
    return h1;
}

/*
Draws a single card from a deck that has at least one card remaining. Used for replacement cards.
*/
CardD1* DeckD1::drawCard()
{
    deckIndex--;
    return deck[deckIndex+1];
    //return new CardD1(rand() % 4, 5); //always return a 5 of a random suit. Test.
}

/*
Returns the number of cards left in the deck. A return value of -1 means the deck is empty.
*/
int DeckD1::cardsRemaining()
{
    return deckIndex+1;
    //return rand() % 53;       //used for testing deck under different conditions
}

/*
Returns the number of cards that have been discarded.
*/
int DeckD1::cardsDiscarded()
{
    return discard.size();
    //return 0;     //discard pile not ready yet
}
