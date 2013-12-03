#include "Timer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void runT2(int);

int main (void) {
	
	int playerBalance = 500;

	//runT2(playerBalance);

	return 0;
}

void runT2(int playerBalance) {
	string input= "T2/poker ";

	stringstream args;

	args << input;
	args << playerBalance;	
	
	cout << args.str() << endl;

	//pass money to system call
	system(args.str().c_str());

}
