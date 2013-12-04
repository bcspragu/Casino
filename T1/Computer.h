#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include <map>
#include <algorithm>
#include "CardT1.h"
#include "DeckT1.h"
#include "SuitValue.h"
#include "PlayerT1.h"

class Dealer;
class Computer: public PlayerT1 {
  public:
    Computer(int startingAmount);
    static int ratePocketCards(std::vector<CardT1> hand);

    Move getMove(Dealer* d);
    int getAmountForMove(Dealer* d);    
    int getRaiseAmount(Dealer* d);
    static int getDecision(int handValue);
    int raiseAmount;
    bool alreadyFolded;
    int handValue;
};

#endif
