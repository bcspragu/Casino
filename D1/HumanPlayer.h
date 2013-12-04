#include "PlayerD1.h"
#include "displayD1.h"

class HumanPlayer: public PlayerD1 {

    public:
		HumanPlayer(int displayPos, int initialMoney, string name);
        int ante(int minimumAnte, displayD1 &gameDisplay);
        int bet(int minimumBet, displayD1 &gameDisplay);
        int discard(displayD1 &gameDisplay);
		bool within(int mouse_x, int mouse_y, int box_x, int box_y, int box_width, int box_height); 
};
