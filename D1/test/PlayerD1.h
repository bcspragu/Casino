#pragma once

#include "displayD1.h"
#include "HandD1.h"
#include <string>

class PlayerD1 {

    protected:
        int displayPosition;
        int money;
        int moneyInPot;
        bool hasFolded;
        HandD1 *hand;
        Frame *frame;
		string playerName;

    public:
        static const int CALL = 0;
        static const int CHECK = 0;
        static const int FOLD = -1;
        static const int ALL_IN = -2;

    	PlayerD1(int displayPos, int initialMoney, string name);
	    virtual ~PlayerD1();

        virtual int bet(int minimumBid, displayD1 &gameDisplay) = 0;
        virtual int discard(displayD1 &gameDisplay) = 0;

        HandD1* getHand();
        void setHand(HandD1 *newHand);

        int getMoney();
        int getMoneyInPot();
	    int giveMoney(int amount);
	    void setMoney(int amount);
        void setMoneyInPot(int amount);

        bool folded();
        void setFolded(bool fold);

        void setFrame(Frame* newFrame);
        Frame* getFrame();

	    void setDisplayPosition(int position);
	    int getDisplayPosition();

        int ante(int anteAmount, displayD1 &gameDisplay);
	
		string getName();
};
