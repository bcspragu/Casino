#include "Player.h"
#include "displayD1.h"

class HumanPlayer: public Player {

    public:
		HumanPlayer(int displayPos, int initialMoney, string name);
        int ante(int minimumAnte, displayD1 gameDisplay);
        int bet(int minimumBet, displayD1 gameDisplay);
        int discard(displayD1 gameDisplay);
};
