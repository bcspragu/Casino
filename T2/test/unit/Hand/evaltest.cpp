#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <cstddef>
#include <time.h>
using namespace std;

int main(){

	Deck TABLE;
	Deck Player1;
	
	
	Card com1(2,10);
	Card com2(1,11);
	Card com3(2,4);

	Card player1pocket1(2,10);
	Card player1pocket2(2,3);
	
	TABLE.add(&com1);
	TABLE.add(&com2);
	TABLE.add(&com3);
	
	Player1.add(&player1pocket1);
	Player1.add(&player1pocket2);
	
	Hand Player1Hand;
	
	Player1Hand.putInCards(Player1, TABLE);
	
	Player1Hand.evaluateCards();
	
	int temp1=Player1Hand.getType();
	
	cout << "[Value:"<< player1pocket1.getValue() <<" Suit:"<< player1pocket1.getSuit()<< "] [Value:"  << player1pocket2.getValue()<< " Suit:"<< player1pocket2.getSuit()  << "].............Hand Value:" << Player1Hand.getType() << endl;

}

	