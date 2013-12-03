#include "display.h"
#include "Timer.h"
#include "T1/T1.h"
#include "GameObject.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "D1/Poker.h"

using namespace std;

void runT2(int*, int*, Timer*);
void runD1(GameObject game);
void setText(string target, string text);

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

  gameDisplay.drawBox(50, 28, 19, 6, 0);		// Top Left
  setText("B11","Check/Call");
  gameDisplay.drawBox(50, 35, 19, 6, 0);		// Bottom Left
  setText("B12","Start Game");
  gameDisplay.drawBox(69, 28, 18, 6, 0);		// Top Middle
  setText("B21","Raise");
  gameDisplay.drawBox(69, 35, 18, 6, 0);		// Bottom Middle
  setText("B22","All In");
  gameDisplay.drawBox(87, 28, 19, 6, 0);		// Top Right
  setText("B31","Fold");
  gameDisplay.drawBox(87, 35, 19, 6, 0);		// Bottom Right
  setText("B32","Quit");
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
  T1 t1;
  t1.runGame(game);
}

void runT2(GameObject game) {
  //T2 t2;
  //t2.runGame(game);
	//string input= "T2/poker ";

	//stringstream args;

	//args << input;
	//args << *playerBalance;	
	
	//cout << args.str() << endl;

	//t2Timer->checkIn();	//start recording time played

	////pass money to system call
	//system(args.str().c_str());

	//t2Timer->checkOut();	//stop recording time played

}

void runD1(GameObject game) {
	Poker poker;
	poker.runGame(game);
}

void setText(string target, string text){
  int xpos,ypos;
  //if(longestStrings[target] < text.length()){
    //longestStrings[target] = text.length();
  //}
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
  //string spaceString = "";
  //for(int i = 0; i < longestStrings[target]; i++){
    //spaceString += " ";
  //}
  //mvprintw(ypos,xpos,spaceString.c_str());
  mvprintw(ypos,xpos,text.c_str());
}
