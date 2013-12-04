#ifndef DEALER_H
#define DEALER_H

#include <vector>
#include "SuitValue.h"
#include "Deck.h"

class Player;
class User;
class CardT1;
class Computer; 
const int smallBlind = 25;
const int largeBlind = 50;

class Dealer {
  public:
    Dealer();
    Deck deck;
    std::vector<CardT1> community;
    int pot;
    int betValue;
    int smallBlindLoc;
    int largeBlindLoc;
    int numPlayers;
    std::vector<Player*> determineWinner();
    std::vector<Player*> players;
    std::vector<Player*> currentRound;
    void updateValuesOnScreen();
    void dealHands();
    void dealFlop();
    void dealRiver();
    void dealTurn();
    void kick(Player playerToKick);
    void startGame();
    void endGame();
    void restartGame();
    void showAllCards();
    void hideAllCards();
    bool userStillAlive(User user);
    static bool royalFlush(std::vector<CardT1> hand);
    static bool straightFlush(std::vector<CardT1> hand);
    static bool fourOfAKind(std::vector<CardT1> hand);
    static Value valueOfFourOfAKind(std::vector<CardT1> hand);
    static bool fullHouse(std::vector<CardT1> hand);
    static bool flush(std::vector<CardT1> hand);
    static bool straight(std::vector<CardT1> hand);
    static bool threeOfAKind(std::vector<CardT1> hand);
    static Value valueOfThreeOfAKind(std::vector<CardT1> hand);
    static bool twoPair(std::vector<CardT1> hand);
    static Value higherPair(std::vector<CardT1> hand);
    static Value lowerPair(std::vector<CardT1> hand);
    static bool pair(std::vector<CardT1> hand);
    static Value valueOfPair(std::vector<CardT1> hand);
    static Value highestValue(std::vector<CardT1> hand);
    static int scoreHand(std::vector<CardT1> hand);
    int scoreBestHand(std::vector<CardT1> hand);
    std::vector<CardT1> bestHand(std::vector<CardT1> hand);
    Player* nextPlayer(std::vector<Computer> computers, User* user);
  private:
    std::vector<CardT1> fiveCardHand(std::vector<CardT1> sevenCardHand, int index1, int index2);
    void roundOfBetting(int offset);
    void updateBet();
    int playersStillIn(std::vector<Player*> current);
};

#endif
