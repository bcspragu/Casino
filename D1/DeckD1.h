#pragma once

#include "HandD1.h"
#include "Card.h"
#include <vector>
#include <algorithm>

class DeckD1
{
public:
    DeckD1();
    ~DeckD1();
    void discardCard(Card *c1);
    void shuffle();
    HandD1* dealHand();
    Card* drawCard();
    int cardsRemaining();
    int cardsDiscarded();
    int deckIndex;

private:
    vector<Card*> deck;
    vector<Card*> discard; 
};
