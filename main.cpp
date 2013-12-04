#include "display.h"
#include "Timer.h"
#include "T1/T1.h"
#include "T2/T2Poker.h"
#include "T2/T2Display.h"
#include "GameObject.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "D1/Poker.h"

using namespace std;

T2Display T2GameDisplay;	//global used in T2

GameObject game(500,0);

int main (void) {
	//initial values
  display gameDisplay;
	int initialBalance = 300;
	int initialCards = 0;

	//pointers for variables to be passed to functions
	int* playerBalance = &initialBalance;
	int* playedCards = &initialCards;

	//create a time object to record time playing t2
	Timer* t2Timer = new Timer();
	//runT2(playerBalance, playedCards, t2Timer);

  //gameDisplay.drawBox(50, 28, 19, 6, 0);		// Top Left
  //setText("B11","Check/Call");
  //gameDisplay.drawBox(50, 35, 19, 6, 0);		// Bottom Left
  //setText("B12","Start Game");
  //gameDisplay.drawBox(69, 28, 18, 6, 0);		// Top Middle
  //setText("B21","Raise");
  //gameDisplay.drawBox(69, 35, 18, 6, 0);		// Bottom Middle
  //setText("B22","All In");
  //gameDisplay.drawBox(87, 28, 19, 6, 0);		// Top Right
  //setText("B31","Fold");
  //gameDisplay.drawBox(87, 35, 19, 6, 0);		// Bottom Right
  //setText("B32","Quit");
  int keynew = 0;
  char key;
  char key2;
  bool onGoing = true;
  int cardX, cardY;
  stringstream messageString;
  while(onGoing){
    key = gameDisplay.captureInput();
    keynew = key - 48;
    // if a mouse event occurred
    if (key == -1) {
      // record the location of the mouse event
      cardX = gameDisplay.getMouseEventX();
      cardY = gameDisplay.getMouseEventY();
      //Start game
      if((cardX >= 50) && (cardX <= 68) && (cardY >= 35) && (cardY <= 40)){
        messageString.str("");
        messageString << "Playing";
        gameDisplay.bannerBottom(messageString.str());
        onGoing = false;
      }else if((cardX >= 87) && (cardX <= 105) && (cardY >= 35) && (cardY <= 40)){
        exit(0);
      }
    }
  }
	return 0;
}

void runT1(GameObject game){
}

void runT2(GameObject game) {
}

void runD1(GameObject game) {
}
