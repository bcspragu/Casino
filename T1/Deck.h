#ifndef DECK_H
#define DECK_H

#include <vector>
#include "CardT1.h"


class Deck {
  public:
    Deck();
    ~Deck(void);
    std::vector<CardT1> cards;
    void shuffle();
    CardT1 dealCard();
    int cardCount();
    static string displayHand(std::vector<CardT1> cards);
    void fill();
};

#endif
