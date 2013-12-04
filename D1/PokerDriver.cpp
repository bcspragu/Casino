#include "Poker.h"
#include "../GameObject.h"

int main() {
	Poker poker;
    while (poker.m_Players.size() > 1) {
    //enter ante loop
        poker.runAnte();
        if (poker.roundIsOver()) continue;
    //enter deal loop
        poker.runDeal();
    //enter first betting loop
        poker.runBetting(1);
        if (poker.roundIsOver()) continue;
    //enter card exchnage loop
    //enter second betting loop
        poker.runBetting(2);
        if (poker.roundIsOver()) continue;
    //enter showdown loop
        poker.runShowdown();
        poker.finishRound();
    }

    poker.endGame("You didn't lose! Hooray!");
}
