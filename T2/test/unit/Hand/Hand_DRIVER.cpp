#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include "SmallDeck.h"
#include <iostream>
#include <cstddef>
#include <time.h>
using namespace std;

int main(){
	srand ( (unsigned)time(0) );
	
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
	SmallDeck Player1;
	SmallDeck Player2;
	SmallDeck Player3;
	SmallDeck Player4;
	
	Card* com1 = new Card(4,3);
	Card* com2 = new Card(3,2);
	Card* com3 = new Card(2,6);
	Card* com4 = new Card(4,13);
	Card* com5 = new Card(4,10);

	
	Card* player1pocket1 = new Card(3,10);
	Card* player1pocket2 = new Card(3,2);
	Card* player2pocket1 = new Card(4,4);
	Card* player2pocket2 = new Card(1,10);
	Card* player3pocket1 = new Card(1,6);
	Card* player3pocket2 = new Card(2,10);
	Card* player4pocket1 = new Card(3,13);
	Card* player4pocket2 = new Card(2,5);


	cout << (*com1).getValue() << "/"<<  com1->getSuit()<< " "	<< com2->getValue() << "/"<<  com2->getSuit()<< " " << com3->getValue() << "/"<<  com3->getSuit()<< " " << com4->getValue() << "/"<<  com4->getSuit()<< " " << com5->getValue() << "/"<<  com5->getSuit()<< endl;
	TABLE.add(com1);
	TABLE.add(com2);
	TABLE.add(com3);
	TABLE.add(com4);
	TABLE.add(com5);
	
	Player1.add(player1pocket1);
	Player1.add(player1pocket2);
	Player2.add(player2pocket1);
	Player2.add(player2pocket2);
	Player3.add(player3pocket1);
	Player3.add(player3pocket2);
	Player4.add(player4pocket1);
	Player4.add(player4pocket2);
	
	Hand Player1Hand;
	Hand Player2Hand;
	Hand Player3Hand;
	Hand Player4Hand;
	
	Player1Hand.putInCards(Player1, TABLE);
	Player2Hand.putInCards(Player2, TABLE);
	Player3Hand.putInCards(Player3, TABLE);
	Player4Hand.putInCards(Player4, TABLE);
	
	Player1Hand.evaluateCards();
	Player2Hand.evaluateCards();
	Player3Hand.evaluateCards();
	Player4Hand.evaluateCards();
	

	
	cout << "Tie Value:" << Player1Hand.getTieBreaker() << ".......Hand Value:" << Player1Hand.getType() << endl;
	cout << "Tie Value:" << Player2Hand.getTieBreaker() << ".......Hand Value:" << Player2Hand.getType() << endl;
	cout << "Tie Value:" << Player3Hand.getTieBreaker() << ".......Hand Value:" << Player3Hand.getType() << endl;
	cout << "Tie Value:" << Player4Hand.getTieBreaker() << ".......Hand Value:" << Player4Hand.getType() << endl;
    

}
