#ifndef BET_H
#define BET_H

#include <string>

using namespace std;

class Bet
{
	private:
	int action;
	int amount;

	public:
	Bet();
	Bet(int BetType, int Amt);
	string print();
	int getAction();
	int getAmount();
};

#endif
