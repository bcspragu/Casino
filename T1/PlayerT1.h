#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "CardT1.h"
#include "Move.h"

class DealerT1;

class PlayerT1 {
  public:
    PlayerT1(int startingAmount);
    std::vector<CardT1> hand;
    int wallet;
    int ID;
    int currentContribution;
    bool allIn;
    string lastMove;

    virtual Move getMove(DealerT1* d);
    virtual int getAmountForMove(DealerT1* d);
    Move moveFromString(string moveStr);
    string stringFromMove(Move move);
    void updateWallet();
};

#endif
