#include "PlayerT1.h"
#include <assert.h>

PlayerT1::PlayerT1(int startingAmount){
  wallet = startingAmount;
  lastMove = "Waiting";
}

Move PlayerT1::getMove(Dealer* d){
  assert(false);
};

int PlayerT1::getAmountForMove(Dealer* d){
  assert(false);
};
