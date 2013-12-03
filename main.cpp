#include "Timer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void runT2(int*, int*, Timer*);

int main (void) {
	//initial values
	int initialBalance = 300;
	int initialCards = 0;

	//pointers for variables to be passed to functions
	int* playerBalance = &initialBalance;
	int* playedCards = &initialCards;

	//create a time object to record time playing t2
	Timer* t2Timer = new Timer();
	runT2(playerBalance, playedCards, t2Timer);

	return 0;
}

void runT2(int* playerBalance, int* playedCards, Timer* t2Timer) {
	string input= "T2/poker ";

	stringstream args;

	args << input;
	args << *playerBalance;	
	
	cout << args.str() << endl;

	t2Timer->checkIn();	//start recording time played

	//pass money to system call
	system(args.str().c_str());

	t2Timer->checkOut();	//stop recording time played

}
