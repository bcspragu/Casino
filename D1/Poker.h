#include "PlayerD1.h"
#include "AI.h"
#include "Frame.h"
#include "DeckD1.h"
#include "displayD1.h"
#include "HumanPlayer.h"
#include <deque>
#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <algorithm>

using namespace std;
class GameObject;

class Poker {
    public:
        Poker();
        ~Poker();


        int m_InitialPlayers;
        int m_InitialMoney;
        int m_RoundCounter;
        int m_PotMoney;
        int bettingCycle;
        Frame player0Frame;
        Frame player1Frame;
        Frame player2Frame;
        Frame player3Frame;
        string bannerHeader;
        DeckD1 m_Deck;
        HumanPlayer m_HumanPlayer;
        AI m_AiPlayer_1;
        AI m_AiPlayer_2;
        AI m_AiPlayer_3;
        deque<PlayerD1*> m_Players;

		displayD1 GAME_DISPLAY;

        void runAnte();
        void runDeal();
        void runBetting(int bettingCycle);
        int runCardExchange();
        void runShowdown();
        bool roundIsOver();
        bool finishRound();
        void endGame(string endReason);

		void runGame(GameObject *game);

		void mostlyRedraw(int sig);

    protected:
    private:
        void initializeDisplay();
        void setTopBannerText(string text);
        void setBottomBannerText(string text);
        void removePlayer(int position);
        void drawHand(HandD1 *hand, bool hidden, Frame *frame);
        void updateHand(HandD1 *hand, Frame *frame);
        void updateGameInfo();
        void rotatePlayers();
        void removeCurrentPlayer();
        int  getRemainingPotMoney();
        int  unfoldedPlayers();
        void finalizeRound();
        int  ante();
        int  minimumBet(PlayerD1 *player);
        int  maxSinglePlayerMoney();
        bool allPlayersAllIn();
};
