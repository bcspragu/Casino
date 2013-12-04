/* Title: Project 1 ECE373 Example driver artifact for Display class
 * Author: John Shield
 * Description: Demonstrates Unix Signal capturing and the Display class
 *		functionality.
 *
 * NOTES:
 *      * Requires the terminal (Putty) to be set to UTF-8.
 *      * Does not function when running a screen session.
 */
#include "displayT1.h"
#include "DealerT1.h"
#include "../GameObject.h"
#include "User.h"
#include "T1.h"
#include "Computer.h"
#include <signal.h>
#include <ncursesw/ncurses.h>
#include <assert.h>
#include <cstdlib>
#include <sstream>

string b11 = "Check/Call";
string b12 = "Start Game";
string b21 = "Raise";
string b22 = "All In";
string b31 = "Fold";
string b32 = "Quit";
/* No Header file for this example driver artifact
 * function declaration here instead.
 */
// Signal Subroutine for Window Resize
static void detectResize (int sig); 
// stub artifact for what the game does when the screen resizes
void resizeT1(void); 
void redrawEverything(void); 
void mvprint_with_offset(int y, int x, string str); 
bool hit(int cardX, int cardY, int x1, int x2, int y1, int y2);

std::map<string,int> longestStrings;
// The gameDisplay object is global, because the static signal handler object
// needs to access the dynamic object.
displayT1 gameDisplay;
DealerT1* dealer;
stringstream messageString;
GameObject* go;

int keynew = 0;
int bet = 0;
char key;
char key2;
int cardX = 0;
int cardY = 0;
bool onGoing = true;
bool duringHand = false;
/*
 * This is the main function that starts the driver artifact.
 * This function demonstrates some of the abilities of the Display class
 */
void T1::runGame(GameObject* g)
{
  go = g;

  signal(SIGWINCH, detectResize); // enable the window resize signal

  // Player 1
  gameDisplay.drawBox(35, 33, 13, 3, 0);		// Money
  gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
  gameDisplay.displayCard(35,29,0,0, A_BOLD);
  gameDisplay.displayCard(42,29,0,0, A_BOLD);

  // Player 2
  gameDisplay.drawBox(10, 23, 13, 3, 0);		// Money
  gameDisplay.drawBox(10, 25, 13, 3, 0);		// Last action
  gameDisplay.displayCard(10,19,0,0, A_BOLD);
  gameDisplay.displayCard(17,19,0,0, A_BOLD);

  // Player 3
  gameDisplay.drawBox(10, 11, 13, 3, 0);		// Money
  gameDisplay.drawBox(10, 13, 13, 3, 0);		// Last action
  gameDisplay.displayCard(10,7,0,0, A_BOLD);
  gameDisplay.displayCard(17,7,0,0, A_BOLD);

  // Player 4
  gameDisplay.drawBox(47, 6, 13, 3, 0);		// Money
  gameDisplay.drawBox(47, 8, 13, 3, 0);		// Last action
  gameDisplay.displayCard(47,2,0,0, A_BOLD);
  gameDisplay.displayCard(54,2,0,0, A_BOLD);

  // Player 5
  gameDisplay.drawBox(78, 11, 13, 3, 0);		// Money
  gameDisplay.drawBox(78, 13, 13, 3, 0);		// Last action
  gameDisplay.displayCard(78,7,0,0, A_BOLD);
  gameDisplay.displayCard(85,7,0,0, A_BOLD);

  // Player 6
  gameDisplay.drawBox(78, 23, 13, 3, 0);		// Money
  gameDisplay.drawBox(78, 25, 13, 3, 0);		// Last action
  gameDisplay.displayCard(78,19,0,0, A_BOLD);
  gameDisplay.displayCard(85,19,0,0, A_BOLD);


  // Choices
  mvprint_with_offset(34,74,"Options");

  gameDisplay.drawBox(50, 28, 19, 6, 0);		// Top Left
  T1::setText("B11","Check/Call");
  b11 = "Check/Call";
  gameDisplay.drawBox(50, 35, 19, 6, 0);		// Bottom Left
  T1::setText("B12","Start Game");
  b12 = "Start Game";
  gameDisplay.drawBox(69, 28, 18, 6, 0);		// Top Middle
  T1::setText("B21","Raise");
  b21 = "Raise";
  gameDisplay.drawBox(69, 35, 18, 6, 0);		// Bottom Middle
  T1::setText("B22","All In");
  b22 = "All In";
  gameDisplay.drawBox(87, 28, 19, 6, 0);		// Top Right
  T1::setText("B31","Fold");
  b31 = "Fold";
  gameDisplay.drawBox(87, 35, 19, 6, 0);		// Bottom Right
  T1::setText("B32","Quit");
  b32 = "Quit";

  //Draw blank community cards
  gameDisplay.displayCard(38,16,0,0, A_BOLD);
  gameDisplay.displayCard(44,16,0,0, A_BOLD);
  gameDisplay.displayCard(50,16,0,0, A_BOLD);
  gameDisplay.displayCard(56,16,0,0, A_BOLD);
  gameDisplay.displayCard(62,16,0,0, A_BOLD);
  
  gameDisplay.drawBox(46, 23, 15, 3, 0);    // Money in current bet cost
  gameDisplay.bannerAd(go->advertisement.getAd());
  while(onGoing){
    key = gameDisplay.captureInput();
    keynew = key - 48;
    // if a mouse event occurred
    if (key == -1) {
      // record the location of the mouse event
      cardX = gameDisplay.getMouseEventX();
      cardY = gameDisplay.getMouseEventY();
      //Start game
      if(hit(cardX,cardY,50,68,35,40)){
        T1::setText("B12","Playing");
        b12 = "Playing";
        messageString.str("");
        messageString << "Playing";
        gameDisplay.bannerBottom(messageString.str());
        DealerT1 d;
        onGoing = false;
      }else if(hit(cardX,cardY,87,105,35,40)){
        return;
      }
    }
  }
  go->T1Timer.checkOut();
  gameDisplay.eraseBox(0,0,gameDisplay.getCols(),gameDisplay.getLines());
}

DealerT1::DealerT1(){
  go->T1Timer.checkIn();
  dealer = this;
  pot = 0;
  numPlayers = 6;
  User* user = new User(go->cash);
  user->ID = 1;
  players.push_back(user);
  for(int i = 1; i < numPlayers; i++){
    players.push_back(new Computer(500));
    players.back()->ID = i+1;
  }

  std::vector<PlayerT1*>::iterator pitr;

  smallBlindLoc = -1;
  //Game loop

  while((*players.front()).wallet > largeBlind && onGoing){

    //Fill and shuffle the deck before each hand
    deck.fill();
    deck.shuffle();

    //Clear out the community cards
    community.clear();

    //Kill all the players that can't make large blind
    for(pitr = players.begin(); pitr != players.end(); ++pitr){
      if((*pitr) != NULL && (**pitr).wallet < largeBlind){
        (*pitr) = NULL; //GET NULLIFIED
        numPlayers--;
      }
    }

    if(numPlayers == 1 && players.front() != NULL){
      //Game Over, you win
      gameDisplay.bannerBottom("You've won!");
      usleep(1000*3000);
      return;
    }

    dealHands();
    
    //Resetting things between rounds (pot, blinds, players in current round)
    pot = 0;

    do{
      smallBlindLoc = (smallBlindLoc+1) % players.size();
    }
    while(players[smallBlindLoc] == NULL);

    //Try the next player first
    largeBlindLoc = (smallBlindLoc+1) % players.size();
    while(players[largeBlindLoc] == NULL){
      largeBlindLoc = (largeBlindLoc+1) % players.size();
    }

    currentRound = players;
    players[smallBlindLoc]->wallet -= smallBlind;
    players[largeBlindLoc]->wallet -= largeBlind;
    go->cash = players.front()->wallet;
    pot += smallBlind+largeBlind;

    duringHand = true;
    roundOfBetting(2);
    dealFlop();
    roundOfBetting(0);
    dealTurn();
    roundOfBetting(0);
    dealRiver();
    roundOfBetting(0);
    gameDisplay.bannerAd(go->advertisement.getAd());
    go->cardsPlayed += 2;

    std::vector<PlayerT1*> winners = determineWinner();
    stringstream win_strm;
    string win_str = "Player(s) ";
    for(pitr = winners.begin(); pitr != winners.end(); ++pitr){
      if((*pitr) != NULL){
        (**pitr).wallet += pot/winners.size();
        win_strm << (**pitr).ID << ", ";
      }
    }

    go->cash = players.front()->wallet;
    win_str += win_strm.str();
    win_str = win_str.substr(0,win_str.length()-2);
    win_str += " won.";
    T1::setText("C",win_str);
    showAllCards();
    duringHand = false;
  }
  if((*players.front()).wallet < largeBlind){
    //Game Over, you lose
    gameDisplay.bannerBottom("You've lost!");
    usleep(1000*500);
  }
}

void DealerT1::updateBet(){
  char betstr[21];
  char potstr[21];
  sprintf(potstr, "Pot: $%d", pot);
  sprintf(betstr, "Bet: $%d", betValue);
  mvprint_with_offset(22,47,potstr);
  mvprint_with_offset(24,47,betstr);
  gameDisplay.captureInput();
}

void DealerT1::dealHands(){
  //Draw blank community cards
  gameDisplay.displayCard(38,16,0,0, A_BOLD);
  gameDisplay.displayCard(44,16,0,0, A_BOLD);
  gameDisplay.displayCard(50,16,0,0, A_BOLD);
  gameDisplay.displayCard(56,16,0,0, A_BOLD);
  gameDisplay.displayCard(62,16,0,0, A_BOLD);
  hideAllCards();

  std::vector<PlayerT1*>::iterator pitr;
  //Clear out each user's hand, then deal them a new one
  for(pitr = players.begin(); pitr != players.end(); ++pitr){
    if((*pitr) != NULL){
      (**pitr).hand.clear();
      (**pitr).allIn = false;
    }
  }
  for(int i = 0; i < 2; i++){
    for(pitr = players.begin(); pitr != players.end(); ++pitr){
      if((*pitr) != NULL){
        (**pitr).hand.push_back(deck.dealCard());
      }
    }
  }
  CardT1 card1 = players.front()->hand.front();
  CardT1 card2 = players.front()->hand.back();

  gameDisplay.displayCard(35,29,card1.suit+1,card1.value+2, A_BOLD);
  gameDisplay.displayCard(42,29,card2.suit+1,card2.value+2, A_BOLD);
}
void DealerT1::updateValuesOnScreen(){
  char tmpstr[21];
  string move;
  string location;
  std::vector<PlayerT1*>::iterator pitr;
  int index = 1;

  for(pitr = players.begin(); pitr != players.end(); ++pitr){
    location = "P";
    if((*pitr) == NULL){
      sprintf(tmpstr, "$%d",0);
      move = "Out";
    }else{
      sprintf(tmpstr, "$%d",(*pitr)->wallet);
      move = (*pitr)->lastMove;
    }
    int x,y;

    switch(index){
      case 1:
        y = 34;
        x = 36;
        location += "1";
        break;
      case 2:
        y = 24;
        x = 11;
        location += "2";
        break;
      case 3:
        y = 12;
        x = 11;
        location += "3";
        break;
      case 4:
        y = 7;
        x = 48;
        location += "4";
        break;
      case 5:
        y = 12;
        x = 79;
        location += "5";
        break;
      case 6:
        y = 24;
        x = 79;
        location += "6";
        break;
    }
    T1::setText(location+"T",tmpstr);
    T1::setText(location+"B",move.c_str());
    index++;
  }
  
  // Player 1
  //gameDisplay.drawBox(35, 33, 13, 3, 0);    // Money
  //gameDisplay.drawBox(35, 35, 13, 3, 0);    // Last action

  // Player 2
  //gameDisplay.drawBox(10, 23, 13, 3, 0);    // Money
  //gameDisplay.drawBox(10, 25, 13, 3, 0);    // Last action

  // Player 3
  //gameDisplay.drawBox(10, 11, 13, 3, 0);    // Money
  //gameDisplay.drawBox(10, 13, 13, 3, 0);    // Last action

  // Player 4
  //gameDisplay.drawBox(47, 6, 13, 3, 0);     // Money
  //gameDisplay.drawBox(47, 8, 13, 3, 0);     // Last action

  // Player 5
  //gameDisplay.drawBox(78, 11, 13, 3, 0);    // Money
  //gameDisplay.drawBox(78, 13, 13, 3, 0);    // Last action

  // Player 6
  //gameDisplay.drawBox(78, 23, 13, 3, 0);    // Money
  //gameDisplay.drawBox(78, 25, 13, 3, 0);    // Last action

  updateBet();
}

void DealerT1::dealRiver(){
  community.push_back(deck.dealCard());
  T1::setText("C","River");
  gameDisplay.displayCard(62,16,community.back().suit+1,community.back().value+2, A_BOLD);

}

void DealerT1::dealTurn(){
  community.push_back(deck.dealCard());
  T1::setText("C","Turn");
  gameDisplay.displayCard(56,16,community.back().suit+1,community.back().value+2, A_BOLD);
}

void DealerT1::dealFlop(){
  for(int i = 0; i < 3; i++){
    community.push_back(deck.dealCard());
  }
  T1::setText("C","Flop");
  gameDisplay.displayCard(38,16,community[0].suit+1,community[0].value+2, A_BOLD);
  gameDisplay.displayCard(44,16,community[1].suit+1,community[1].value+2, A_BOLD);
  gameDisplay.displayCard(50,16,community[2].suit+1,community[2].value+2, A_BOLD);
  gameDisplay.displayCard(56,16,0,0, A_BOLD);
  gameDisplay.displayCard(62,16,0,0, A_BOLD);
}

// have the user enter the amount to raise
int User::getAmountForMove(DealerT1* d){
  gameDisplay.drawBox(46, 21, 15, 3, 0);		// Money in Pot
  char potstr[21];
  sprintf(potstr,"Pot: $%d",d->pot);
  for(;;){
    key2 = gameDisplay.captureInput();
    keynew = key2 - 48;

    if ((keynew >= 0) && (keynew <= 9)){
      bet = (bet * 10) + keynew;
      messageString.str("");
      messageString << "Press SPACE to confirm                Money raising: " << bet;
      gameDisplay.bannerBottom(messageString.str());
    }

    if (keynew == -16){
      if (bet != 0){
        gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
        mvprint_with_offset(36,36,"Raise");								
        messageString.str("");
        messageString << "You bet " << bet << " chip(s)";
        gameDisplay.bannerBottom(messageString.str());
        int temp = bet;
        bet = 0;
        return temp;
      }
    }
  }
}

Move Computer::getMove(DealerT1* d){
  int handValue;
  int decision;
  lastMove = "Thinking";
  //Flush visuals
  d->updateValuesOnScreen();
  usleep(1000*500);
  std::vector<CardT1> allCards;
  allCards.insert(allCards.end(), hand.begin(), hand.end());
  allCards.insert(allCards.end(), (*d).community.begin(),(*d).community.end());

  //if only pocket cards use ratePocketCards method for decision
  if(allCards.size() <= 2){    
    handValue = ratePocketCards(allCards);
  }else if(allCards.size() == 5){
    handValue = DealerT1::scoreHand(allCards);
  }else if ((allCards.size()) >= 6){
    handValue = (*d).scoreBestHand(hand);
  }
  decision = getDecision(handValue);

  if((decision == 0) || (decision == 3)){
    raiseAmount = 0;
    //move = 0;
    lastMove = "Call";
    d->updateValuesOnScreen();
    return CALL;
  }else if ((decision == 1) || (decision == 4)){
    lastMove = "Raise";
    raiseAmount = getRaiseAmount(d);
    d->updateValuesOnScreen();
    return RAISE;
  }else if ((decision == 2) || (decision == 5)){
    //move = 2;
    alreadyFolded = true;
    lastMove = "Fold";
    d->updateValuesOnScreen();
    return FOLD;
  }
  lastMove = "Call";
  d->updateValuesOnScreen();
  return CALL;
}

int Computer::getAmountForMove(DealerT1* d){
  return raiseAmount;
}

// have the user enter their move, store it for later
Move User::getMove(DealerT1* d){
  // display class will return button pressed
  // "raise", "call", "fold", "allin"
  lastMove = "Your Move";
  //mvprint_with_offset(36,36,"Your Move");

  d->updateValuesOnScreen();
  char potstr[21];
  gameDisplay.drawBox(46, 21, 15, 3, 0);		// Money in Pot
  sprintf(potstr, "Pot: $%d", d->pot);
  mvprint_with_offset(22,47,potstr);


  for (;;) {
    key = gameDisplay.captureInput();
    keynew = key - 48;
    // if a mouse event occurred
    if (key == -1) {
      // make a banner message
      messageString.str("");
      messageString << "A mouse event occurred x=" \
        << gameDisplay.getMouseEventX() << ", y=" \
        << gameDisplay.getMouseEventY() << ", bstate=" \
        << gameDisplay.getMouseEventButton();
      // display a banner message
      gameDisplay.bannerTop(messageString.str());
      // record the location of the mouse event
      cardX = gameDisplay.getMouseEventX();
      cardY = gameDisplay.getMouseEventY();
      // Some of the mouse click values are defined in display.h
      // check if it was a left click
      if (gameDisplay.getMouseEventButton()&LEFT_CLICK) {
        // Top Left
        // Check/Call
        if(hit(cardX,cardY,50,68,28,33)){
          gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
          mvprint_with_offset(36,36,"Call");
          messageString.str("");
          messageString << "You Checked/Called";
          lastMove = "Check";
          gameDisplay.bannerBottom(messageString.str());
          return CALL;
        }

        // Top Middle
        // Raise
        else if(hit(cardX,cardY,69,86,28,33)){
          messageString.str("");
          messageString << "Press SPACE to confirm                           Money raising: " << bet;
          gameDisplay.bannerBottom(messageString.str());
          lastMove = "Raise";
          return RAISE;
        }
        // Bottom Middle
        // ALL IN
        else if(hit(cardX,cardY,69,86,35,40)){
          gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
          mvprint_with_offset(36,36,"All In");
          messageString.str("");
          messageString << "You went ALL IN!";
          gameDisplay.bannerBottom(messageString.str());
          lastMove = "Raise";
          return ALLIN;
        }
        // Top Right
        // Fold
        else if(hit(cardX,cardY,87,105,28,33)){
          gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
          mvprint_with_offset(36,36,"Fold");
          messageString.str("");
          messageString << "You Folded";
          gameDisplay.bannerBottom(messageString.str());
          lastMove = "Fold";
          return FOLD;
        }
        // Bottom Right
        // Quit
        else if(hit(cardX,cardY,87,105,35,40)){
          onGoing = false;
          gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action
          mvprint_with_offset(36,36,"Fold");
          messageString.str("");
          messageString << "You Folded";
          gameDisplay.bannerBottom(messageString.str());
          lastMove = "Fold";
          return FOLD;
        }
      }
    } 
  }
  d->updateValuesOnScreen();
}

void DealerT1::hideAllCards(){
  std::vector<PlayerT1*>::iterator pitr;
  for(pitr = players.begin(); pitr != players.end(); ++pitr){
    if((*pitr) != NULL){
      int suit1 = 0;
      int value1 = 0;
      int suit2 = 0;
      int value2 = 0;
      int ypos,xpos;
      switch((**pitr).ID){
        case 1:
          xpos = 35;
          ypos = 29;
          if(duringHand){
            suit1 = (**pitr).hand.front().suit+1;
            value1 = (**pitr).hand.front().value+2;
            suit2 = (**pitr).hand.back().suit+1;
            value2 = (**pitr).hand.back().value+2;
          }
          break;
        case 2:
          xpos = 10;
          ypos = 19;
          break;
        case 3:
          xpos = 10;
          ypos = 7;
          break;
        case 4:
          xpos = 47;
          ypos = 2;
          break;
        case 5:
          xpos = 78;
          ypos = 7;
          break;
        case 6:
          xpos = 78;
          ypos = 19;
          break;
      }
      gameDisplay.displayCard(xpos,ypos,suit1,value1, A_BOLD);
      gameDisplay.displayCard(xpos+7,ypos,suit2,value2, A_BOLD);
    }
  }
}

void DealerT1::showAllCards(){
  std::vector<PlayerT1*>::iterator pitr;
  for(pitr = players.begin(); pitr != players.end(); ++pitr){
    if((*pitr) != NULL && (*pitr)->lastMove != "Fold"){
      int suit1 = (**pitr).hand.front().suit+1;
      int value1 = (**pitr).hand.front().value+2;
      int suit2 = (**pitr).hand.back().suit+1;
      int value2 = (**pitr).hand.back().value+2;
      int ypos,xpos;
      switch((**pitr).ID){
        case 1:
          xpos = 35;
          ypos = 29;
          break;
        case 2:
          xpos = 10;
          ypos = 19;
          break;
        case 3:
          xpos = 10;
          ypos = 7;
          break;
        case 4:
          xpos = 47;
          ypos = 2;
          break;
        case 5:
          xpos = 78;
          ypos = 7;
          break;
        case 6:
          xpos = 78;
          ypos = 19;
          break;
      }
      gameDisplay.displayCard(xpos,ypos,suit1,value1, A_BOLD);
      gameDisplay.displayCard(xpos+7,ypos,suit2,value2, A_BOLD);
    }
  }

  T1::setText("B12","New Hand?");
  b12 = "New Hand?";
  while(true){
    key = gameDisplay.captureInput();
    keynew = key - 48;
    // if a mouse event occurred
    if (key == -1) {
      // record the location of the mouse event
      cardX = gameDisplay.getMouseEventX();
      cardY = gameDisplay.getMouseEventY();
      if(hit(cardX,cardY,50,68,35,40)){
        T1::setText("C","");
        T1::setText("B12","Playing");
        b12 = "Playing";
        messageString.str("");
        messageString << "Playing";
        gameDisplay.bannerBottom(messageString.str());
        break;
      //Quit
      }else if(hit(cardX,cardY,87,105,35,40)){
        onGoing = false;
        return;
      }
    }
  }
}

void PlayerT1::updateWallet(){
  const char* move = lastMove.c_str();
  char money[10];
  sprintf(money,"$%d",wallet);
  switch(ID){
    case 1:
      T1::setText("P1T",money);
      T1::setText("P1B",move);
      go->cash = wallet;
      break;
    case 2:
      T1::setText("P2T",money);
      T1::setText("P2B",move);
      break;
    case 3:
      T1::setText("P3T",money);
      T1::setText("P3B",move);
      break;
    case 4:
      T1::setText("P4T",money);
      T1::setText("P4B",move);
      break;
    case 5:
      T1::setText("P5T",money);
      T1::setText("P5B",move);
      break;
    case 6:
      T1::setText("P6T",money);
      T1::setText("P6B",move);
      break;
  }
}
/*
 * This is the interrupt service routine called when the resize screen 
 * signal is captured.
 */
void detectResize(int sig) {
  // update the display class information with the new window size
  gameDisplay.handleResize(sig);
  // re-enable the interrupt for a window resize
  signal(SIGWINCH, detectResize);
  resizeT1();
}

/*
 * This is a simple stub that should be replaced with what the game does
 * when the screen resizes. 
 */
void resizeT1(void) {
  if(dealer != NULL){
    // gets the new screen size
    int cols = gameDisplay.getCols();
    int lines = gameDisplay.getLines();
    //game is 90x30, roughly
    gameDisplay.updateOffset(cols/2-50,lines/2-20);
    gameDisplay.eraseBox(0,0,gameDisplay.getCols(),gameDisplay.getLines());
    redrawEverything();
  }
}

void T1::setText(string target, string text){
  int xpos,ypos;
  if(longestStrings[target] < text.length()){
    longestStrings[target] = text.length();
  }
  if(target == "B11"){ //Box 1,1 top left
    ypos = 30;
    xpos = 55;
  }else if(target == "B12"){ //Box 1,2 bottom left
    ypos = 37;
    xpos = 55;
  }else if(target == "B21"){ //Box 2,1 top center
    ypos = 30;
    xpos = 75;
  }else if(target == "B22"){ //Box 1,2 bottom center
    ypos = 37;
    xpos = 75;
  }else if(target == "B31"){ //Box 3,1 top right
    ypos = 30;
    xpos = 94;
  }else if(target == "B32"){ //Box 3,2 bottom right
    ypos = 37;
    xpos = 94;
  }else if(target == "P1T"){ //Player 1 top box
    ypos = 34;
    xpos = 36;
  }else if(target == "P1B"){ //Player 1 bottom box
    ypos = 36;
    xpos = 36;
  }else if(target == "P2T"){ //Player 3 top box
    ypos = 24;
    xpos = 11;
  }else if(target == "P2B"){ //Player 3 bottom box
    ypos = 26;
    xpos = 11;
  }else if(target == "P3T"){ //Player 4 top box
    ypos = 12;
    xpos = 11;
  }else if(target == "P3B"){ //Player 4 bottom box
    ypos = 14;
    xpos = 11;
  }else if(target == "P4T"){ //Player 2 top box
    ypos = 7;
    xpos = 48;
  }else if(target == "P4B"){ //Player 2 bottom box
    ypos = 9;
    xpos = 48;
  }else if(target == "P5T"){ //Player 6 top box
    ypos = 12;
    xpos = 79;
  }else if(target == "P5B"){ //Player 6 bottom box
    ypos = 14;
    xpos = 79;
  }else if(target == "P6T"){ //Player 5 top box
    ypos = 24;
    xpos = 79;
  }else if(target == "P6B"){ //Player 5 bottom box
    ypos = 26;
    xpos = 79;
  }else if(target == "C"){ //Community header
    ypos = 15;
    xpos = 51;
  }
  string spaceString = "";
  for(int i = 0; i < longestStrings[target]; i++){
    spaceString += " ";
  }
  mvprint_with_offset(ypos,xpos,spaceString.c_str());
  mvprint_with_offset(ypos,xpos,text.c_str());
}

void DealerT1::roundOfBetting(int handOffset){
  if(playersStillIn(currentRound) == 1){
    return; //There's only one person, we don't need to play
  }
  //Reset the value to stay in to the large blind
  betValue = largeBlind;
  
  //All set if nobody has raised, means everyone has folded or checked
  bool allSet = false;
  
  //Start by setting everyone's contribution to the current round of betting to zero
  std::vector<PlayerT1*>::iterator pitr;
  for(pitr = players.begin(); pitr != players.end(); ++pitr){
    if((*pitr) != NULL){
      (**pitr).currentContribution = 0;
    }
  }

  updateValuesOnScreen();

  while(!allSet){
    //cot << "Pot: $" << pot << " Bet: $" << betValue << endl;
    allSet = true;
    for(int i = 0; i < currentRound.size(); i++){
      int index = (smallBlindLoc+handOffset+i) % currentRound.size();
      if(currentRound[index] != NULL){
        PlayerT1* player = currentRound[index];
        if(!(player->allIn)){
          Move move = player->getMove(this);
          if(move == RAISE){
            //The amount they spend is the amount they need to add to match the current bet, plus their raise
            int raise = player->getAmountForMove(this);
            int amount = (betValue - player->currentContribution) + raise;
            if(amount <= player->wallet){ //If they have enough money to do this
              betValue += raise;
              player->currentContribution += amount;
              player->wallet -= amount;
              pot += amount;
            }else{ //If they don't have enough, put them all in
              player->allIn = true;
              player->lastMove = "All In";
              //Only increase the actual bet by how much new they're adding in
              betValue += player->wallet - (betValue - player->currentContribution);
              player->currentContribution += player->wallet;
              pot += player-> wallet;
              player->wallet = 0;
            }
            allSet = false;
          }else if(move == CALL){
            int amount = betValue - player->currentContribution;
            if(amount <= player->wallet){
              player->currentContribution += amount;
              player->wallet -= amount;
              pot += amount;
            }else{ //If they don't have enough, put them all in
              player->allIn = true;
              player->lastMove = "All In";
              //Only increase the actual bet by how much new they're adding in
              betValue += player->wallet - (betValue - player->currentContribution);
              player->currentContribution += player->wallet;
              pot += player-> wallet;
              player->wallet = 0;
              allSet = false;
            }
          }else if(move == FOLD){
            currentRound[index] = NULL;
            if(playersStillIn(currentRound) == 1){
              return; //There's only one person, we don't need to play
            }
          }else if(move == ALLIN){
            //Only increase the actual bet by how much new they're adding in
            betValue += player->wallet - (betValue - player->currentContribution);
            player->currentContribution += player->wallet;
            pot += player-> wallet;
            player->wallet = 0;
            allSet = false;
            player->allIn = true;
            player->lastMove = "All In";
          }else{
            assert(false);
          }
        }
        player->updateWallet();
      }
    }
  }
  go->cash = players.front()->wallet;
  updateBet();
}

void redrawEverything(){
  // Player 1
  gameDisplay.drawBox(35, 33, 13, 3, 0);		// Money
  gameDisplay.drawBox(35, 35, 13, 3, 0);		// Last action

  // Player 2
  gameDisplay.drawBox(10, 23, 13, 3, 0);		// Money
  gameDisplay.drawBox(10, 25, 13, 3, 0);		// Last action

  // Player 3
  gameDisplay.drawBox(10, 11, 13, 3, 0);		// Money
  gameDisplay.drawBox(10, 13, 13, 3, 0);		// Last action

  // Player 4
  gameDisplay.drawBox(47, 6, 13, 3, 0);		// Money
  gameDisplay.drawBox(47, 8, 13, 3, 0);		// Last action

  // Player 5
  gameDisplay.drawBox(78, 11, 13, 3, 0);		// Money
  gameDisplay.drawBox(78, 13, 13, 3, 0);		// Last action

  // Player 6
  gameDisplay.drawBox(78, 23, 13, 3, 0);		// Money
  gameDisplay.drawBox(78, 25, 13, 3, 0);		// Last action

  gameDisplay.drawBox(50, 28, 19, 6, 0);		// Top Left
  T1::setText("B11",b11);
  gameDisplay.drawBox(50, 35, 19, 6, 0);		// Bottom Left
  T1::setText("B12",b12);
  gameDisplay.drawBox(69, 28, 18, 6, 0);		// Top Middle
  T1::setText("B21",b21);
  gameDisplay.drawBox(69, 35, 18, 6, 0);		// Bottom Middle
  T1::setText("B22",b22);
  gameDisplay.drawBox(87, 28, 19, 6, 0);		// Top Right
  T1::setText("B31",b31);
  gameDisplay.drawBox(87, 35, 19, 6, 0);		// Bottom Right
  T1::setText("B32",b32);

  gameDisplay.drawBox(46, 23, 15, 3, 0);    // Money in current bet cost

  dealer->updateValuesOnScreen();
  dealer->hideAllCards();

  std::vector<CardT1>::iterator citr;
  int i = 0;
  int x,y;
  for(citr = dealer->community.begin(); citr != dealer->community.end(); ++citr){
    switch(i){
      case 0:
        x = 38;
        y = 16;
        break;
      case 1:
        x = 44;
        y = 16;
        break;
      case 2:
        x = 50;
        y = 16;
        break;
      case 3:
        x = 56;
        y = 16;
        break;
      case 4:
        x = 62;
        y = 16;
        break;
    }
    if(&citr != NULL){
      gameDisplay.displayCard(x,y,(*citr).suit+1,(*citr).value+2, A_BOLD);
    }else{
      gameDisplay.displayCard(x,y,0,0, A_BOLD);
    }
    i++;
  }
  while(i < 5){
    switch(i){
      case 0:
        x = 38;
        y = 16;
        break;
      case 1:
        x = 44;
        y = 16;
        break;
      case 2:
        x = 50;
        y = 16;
        break;
      case 3:
        x = 56;
        y = 16;
        break;
      case 4:
        x = 62;
        y = 16;
        break;
    }
    gameDisplay.displayCard(x,y,0,0, A_BOLD);
    i++;
  }
}

bool hit(int cardX, int cardY, int x1, int x2, int y1, int y2){
    return (cardX-gameDisplay.xOffset >= x1) && (cardX-gameDisplay.xOffset <= x2) && (cardY-gameDisplay.yOffset  >= y1) && (cardY-gameDisplay.yOffset  <= y2);
}

void mvprint_with_offset(int ypos, int xpos, string str){
  mvprintw(ypos+gameDisplay.yOffset,xpos+gameDisplay.xOffset,str.c_str());
}
