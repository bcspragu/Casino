#include "Balance.h"

Balance::Balance(void) {};

Balance::~Balance(void) {};

int Balance::addBalance(int amt) {
	balance += amt;
	return balance;
};

int Balance::subBalance(int amt) {
	balance -= amt;
	return balance;
};

int Balance::getBalance() {return balance;};

