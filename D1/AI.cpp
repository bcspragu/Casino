#include "AI.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sstream>

using namespace std;
#define DELAY 2
AI::AI(int displayPos, int initialMoney, string name) : PlayerD1(displayPos, initialMoney, name) {
    std::srand(unsigned(std::time(0)));
}


int AI::bet(int minimumbid, displayD1 &gameDisplay)
{
	stringstream bannerText;

    int random = rand() % 10;
    if (random == 0) {
        hasFolded = true;
		bannerText << playerName << " FOLDS";
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
        return PlayerD1::FOLD;
    } else if (random < 7) {
        int bid = min(minimumbid, money);
        money -= bid;
        moneyInPot += bid;
		bannerText << playerName << " bids " << bid;
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
        return bid;
    }
    
    if (money >= minimumbid)
    {
        double multiplier = 1.0 / (double)(rand() % 100 + 1);
        int maxBid = (int) (multiplier * money);
        maxBid = max(minimumbid + 1, maxBid);
        int bid = rand() % (maxBid - minimumbid) + minimumbid;    
        money -= bid;
        moneyInPot += bid;
		bannerText << playerName << " bids " << bid;
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
        return bid;      //AI bets minimum amount each time it is asked to bet
    }
    else
    {
        int bid = money;
        moneyInPot += bid;
        money -= bid;
		bannerText << playerName << " bids " << bid;
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
        return bid;           //Have to go all in once money < minimum bid
    }
    //return minimumbid; //basic functionality. Use this result for testing
}

int AI::discard(displayD1 &gameDisplay)
{
	stringstream bannerText;

	for (int i = 0; i < 5; i++) {		//Reset discard flags just in case
		hand->getCard(i)->setDiscarded(false);
	}

    int discardCount = 2;
    hand->getCard(0)->setDiscarded(true);     //Discard 0th card
    hand->getCard(3)->setDiscarded(true);	//Discard 3rd card
	
	bannerText << playerName << " discarded " << discardCount << " card(s)";
	gameDisplay.bannerBottom(bannerText.str());
	while(!gameDisplay.captureInput())
		;
    return discardCount;
}

int AI::ante(int anteamount, displayD1 &gameDisplay)
{
	stringstream bannerText;

    if (money >= anteamount) {
        moneyInPot += anteamount;
        money -= anteamount;
		bannerText << playerName << " anted";
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
    	return anteamount;
	} else {
		bannerText << playerName << " couldn't ante";
		gameDisplay.bannerBottom(bannerText.str());
		while(!gameDisplay.captureInput())
			;
	    return PlayerD1::FOLD;
    }
}
