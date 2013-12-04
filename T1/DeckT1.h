#ifndef DECK_H
#define DECK_H

#include <vector>
#include "CardT1.h"


class DeckT1 {
  public:
    DeckT1();
    ~DeckT1(void);
    std::vector<CardT1> cards;
    void shuffle();
    CardT1 dealCard();
    int cardCount();
    static string displayHand(std::vector<CardT1> cards);
    void fill();
};

#endif
