#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include <map>
#include <algorithm>
#include "CardT1.h"
#include "DeckT1.h"
#include "SuitValue.h"
#include "PlayerT1.h"

class DealerT1;
class Computer: public PlayerT1 {
  public:
    Computer(int startingAmount);
    static int ratePocketCards(std::vector<CardT1> hand);

    Move getMove(DealerT1* d);
    int getAmountForMove(DealerT1* d);    
    int getRaiseAmount(DealerT1* d);
    static int getDecision(int handValue);
    int raiseAmount;
    bool alreadyFolded;
    int handValue;
};

#endif
