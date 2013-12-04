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

void runT1(GameObject game);
bool inHitBox(int cardX, int cardY, int x1, int x2, int y1, int y2);
T2Display T2GameDisplay;	//global used in T2

GameObject* game = new GameObject(500,0);

void runT2(GameObject*);
void runT1(GameObject*);
void runD1(GameObject*);

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

  gameDisplay.drawBox(50, 28, 19, 6, 0);		// Top Left
  T1::setText("B11","Texas Hold'em 1");
  gameDisplay.drawBox(69, 28, 18, 6, 0);		// Top Middle
  T1::setText("B21","Texas Hold'em 2");
  gameDisplay.drawBox(87, 28, 19, 6, 0);		// Top Right
  T1::setText("B31","Five Card Draw");
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
      if((cardX >= 50) && (cardX <= 68) && (cardY >= 28) && (cardY <= 34)){
        runT1(game);
      }else if((cardX >= 87) && (cardX <= 105) && (cardY >= 35) && (cardY <= 40)){
        exit(0);
      }
    }
  }
	return 0;
}

void runT1(GameObject game){
  T1 t1;
  t1.runGame(&game);
}

void runT2(GameObject* game) {
    T2Poker t2;
    t2.runGame(game);
}

void runD1(GameObject game) {
}

bool inHitBox(int cardX, int cardY, int x1, int x2, int y1, int y2){
    return (cardX >= x1) && (cardX <= x2) && (cardY >= y1) && (cardY <= y2);
}
