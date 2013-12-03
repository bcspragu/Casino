#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "CardT1.h"
#include "Move.h"

class Dealer;

class Player {
  public:
    Player(int startingAmount);
    std::vector<CardT1> hand;
    int wallet;
    int ID;
    int currentContribution;
    bool allIn;
    string lastMove;

    virtual Move getMove(Dealer* d);
    virtual int getAmountForMove(Dealer* d);
    Move moveFromString(string moveStr);
    string stringFromMove(Move move);
    void updateWallet();
};

#endif
