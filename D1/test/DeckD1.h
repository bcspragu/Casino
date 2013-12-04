#pragma once

#include "HandD1.h"
#include "CardD1.h"
#include <vector>
#include <algorithm>

class DeckD1
{
public:
    DeckD1();
    ~DeckD1();
    void discardCard(CardD1 *c1);
    void shuffle();
    HandD1* dealHand();
    CardD1* drawCard();
    int cardsRemaining();
    int cardsDiscarded();
    int deckIndex;

private:
    vector<CardD1*> deck;
    vector<CardD1*> discard; 
};
