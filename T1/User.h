#ifndef USER_H
#define USER_H

#include "PlayerT1.h"

class User: public PlayerT1 {
  public:
    User(int startingAmount);
    Move getMove(DealerT1* d);
    int getAmountForMove(DealerT1* d);
};

#endif
