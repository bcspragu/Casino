#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "ComputerPlayer.h"
#include "Card.h"
#include "Deck.h"
#include "Bet.h"
#include "SmallDeck.h"
#include <cstddef>
#include <time.h>
using namespace std;
int main(){
	int rnd[13];
	int suitrnd[13];
	int j;
	for(j=0; j<13; j++){
		rnd[j]=2+(rand()%13);
	}
	for(j=0; j<13; j++){
		suitrnd[j]=1+(rand()%4);
	}
	SmallDeck TABLE;

	Card* com1 = new Card(3,7);
	Card* com2 = new Card(2,4);
	Card* com3 = new Card(1,13);
	Card* com4 = new Card(2,7);
	Card* com5 = new Card(2,3);
	
	TABLE.add(com1);
	TABLE.add(com2);
	TABLE.add(com3);
	TABLE.add(com4);
	TABLE.add(com5);
	



	Card* card1 =new Card(2,13);
	Card* card2 = new Card(3,6);

	ComputerPlayer dan;
	dan.giveCard(card1);
	dan.giveCard(card2);
	int temp = (*(dan.makeBet(TABLE,20))).getAmount();
	cout << temp << endl;
	
	return 1;



}
