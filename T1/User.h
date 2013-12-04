#ifndef USER_H
#define USER_H

#include "PlayerT1.h"

class User: public PlayerT1 {
  public:
    User(int startingAmount);
    Move getMove(Dealer* d);
    int getAmountForMove(Dealer* d);
};

#endif
