#include "display.h"
#include "Timer.h"
#include "T1/T1.h"
#include "T2/T2Poker.h"
#include "T2/T2Display.h"
#include "GameObject.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <sstream>
#include <csignal>
#include "D1/Poker.h"

using namespace std;

void initScreen(display gameDisplay);
map<string,int> longStr;
void setText(string target, string text);
void runT1(GameObject* game);
void runT2(GameObject* game);
void runD1(GameObject* game);
void redrawD1(int sig);
bool inHitBox(int cardX, int cardY, int x1, int x2, int y1, int y2);
T2Display T2GameDisplay;	//global used in T2
Poker* poker;

GameObject* game = new GameObject(500,0);

int main (void) {
	//initial values
  display gameDisplay;

  int keynew = 0;
  char key;
  char key2;
  bool onGoing = true;
  int cardX, cardY;
  stringstream messageString;
  initScreen(gameDisplay);
  while(onGoing){
    key = gameDisplay.captureInput();
    keynew = key - 48;
    // if a mouse event occurred
    if (key == -1) {
      // record the location of the mouse event
      cardX = gameDisplay.getMouseEventX();
      cardY = gameDisplay.getMouseEventY();
      //Start game
      if(inHitBox(cardX,cardY,50,69,18,24)){
        gameDisplay.eraseBox(0,0,gameDisplay.getCols(),gameDisplay.getLines());
        runT1(game);
        initScreen(gameDisplay);
      }else if(inHitBox(cardX,cardY,69,87,18,24)){
        gameDisplay.eraseBox(0,0,gameDisplay.getCols(),gameDisplay.getLines());
        runT2(game);
        initScreen(gameDisplay);
      }else if(inHitBox(cardX,cardY,87,106,18,24)){
        gameDisplay.eraseBox(0,0,gameDisplay.getCols(),gameDisplay.getLines());
        signal(SIGWINCH, redrawD1);
        runD1(game);
        signal(SIGWINCH, SIG_DFL);
        initScreen(gameDisplay);
      }
      else if(inHitBox(cardX,cardY,69,87,24,30)){
        exit(0);
      }
    }
  }
	return 0;
}

void runT1(GameObject* game){
  T1 t1;
  t1.runGame(game);
}

void runT2(GameObject* game) {
  T2Poker t2;
  t2.runGame(game);
}

void runD1(GameObject* game) {
	poker = new Poker();
	poker->runGame(game);
	delete poker;
	poker = NULL;
}

void redrawD1(int sig) {
	if (poker) {
		poker->mostlyRedraw(sig);
	}
}

bool inHitBox(int cardX, int cardY, int x1, int x2, int y1, int y2){
    return (cardX >= x1) && (cardX <= x2) && (cardY >= y1) && (cardY <= y2);
}

void initScreen(display gameDisplay){
  gameDisplay.eraseBox(0,0,gameDisplay.getCols(), gameDisplay.getLines());

  gameDisplay.drawBox(50, 15, 56, 3, 0);		// Top Left

  stringstream message;

  message << "Money: $" << game->cash;
  message << "         Cards Played: " << game->cardsPlayed;

  setText("DISP",message.str());
  setText("AD",game->advertisement.getAd());

  stringstream t1, t2, d1;
  t1 << game->T1Timer.getSecondsPlayed() << " seconds";
  t2 << game->T2Timer.getSecondsPlayed() << " seconds";
  d1 << game->D1Timer.getSecondsPlayed() << " seconds";

  gameDisplay.drawBox(50, 18, 19, 6, 0);		// Top Left
  setText("B11","Texas Hold'em 1");
  gameDisplay.drawBox(69, 18, 18, 6, 0);		// Top Middle
  setText("B21","Texas Hold'em 2");
  gameDisplay.drawBox(87, 18, 19, 6, 0);		// Top Right
  setText("B31","Five Card Draw");
  gameDisplay.drawBox(69, 24, 18, 6, 0);		// Top Middle
  setText("B22","Quit");

  setText("T1",t1.str());
  setText("T2",t2.str());
  setText("D1",d1.str());
}

void setText(string target, string text){
  int xpos,ypos;
  if(longStr[target] < text.length()){
    longStr[target] = text.length();
  }
  if(target == "B11"){ //Box 1,1 top left
    ypos = 20;
    xpos = 52;
  }else if(target == "B21"){ //Box 2,1 top center
    ypos = 20;
    xpos = 70;
  }else if(target == "B31"){ //Box 2,1 top center
    ypos = 20;
    xpos = 89;
  }else if(target == "B22"){ //Box 1,2 bottom center
    ypos = 26;
    xpos = 75;
  }else if(target == "DISP"){ //Box 3,2 bottom right
    ypos = 16;
    xpos = 51;
  }else if(target == "AD"){ //Box 3,2 bottom right
    ypos = 14;
    xpos = 61;
  }else if(target == "T1"){
    ypos = 22;
    xpos = 54;
  }else if(target == "T2"){
    ypos = 22;
    xpos = 72;
  }else if(target == "D1"){
    ypos = 22;
    xpos = 91;
  }
  string spaceString = "";
  for(int i = 0; i < longStr[target]; i++){
    spaceString += " ";
  }
  mvprintw(ypos,xpos,spaceString.c_str());
  mvprintw(ypos,xpos,text.c_str());
}
