#ifndef BALANCE_H_
#define BALANCE_H_

class Balance {
private:
	static int balance; //amount of money the player has
public:
	Balance(void);
	~Balance(void);
	int	addBalance(int);
	int	subBalance(int);
	int getBalance(void);
};

#endif /*BALANCE_H_*/

