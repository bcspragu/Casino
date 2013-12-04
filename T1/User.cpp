#include <iostream>
#include "User.h"
#include "DeckT1.h"

using std::cout;
using std::cin;
using std::endl;

User::User(int startingAmount) : PlayerT1(startingAmount){
  wallet = startingAmount;
  lastMove = "Waiting";
}
