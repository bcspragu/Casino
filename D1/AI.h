#include "Player.h"
#include "displayD1.h"


class AI: public Player {
	
public:
	AI(int displayPos, int startingMoney, string name);
	int bet(int minimumBid, displayD1 gameDisplay);
	int discard(displayD1 gameDisplay);
	int ante(int anteamount, displayD1 gameDisplay);
};
