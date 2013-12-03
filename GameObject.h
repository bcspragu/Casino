#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Advertisement.h"
#include "Timer.h"

class GameObject {
  public:
    GameObject(int cash,int cardsPlayed);
    Timer timer;
    Advertisement advertisement;
    int cash;
    int cardsPlayed;
};

#endif
