#include "HandDriver.h"
#include "Card.h"
#include "Hand.h"
#include <iostream>
#include <stdio.h>

void testHand(Hand hand, int *expectedArray, bool higherThanThreeOfAKind, int cardExchanged,
					Card* exchangedCard, int elementGot, Card* gotCard);

HandDriver::HandDriver(void)
{
}

int main(){
	//	Below is each card that will be exchanged and gotten out of the hand
	Card *eCardHC	= new Card(1,6);
	Card *gCardHC	= new Card(1,14);
	Card *eCardD	= new Card(2,2);
	Card *gCardD	= new Card(2,12);
	Card *eCardTP	= new Card(0,2);
	Card *gCardTP	= new Card(1,12);
	Card *eCardTOAK	= new Card(2,12);
	Card *gCardTOAK	= new Card(2,2);
	Card *eCardS	= new Card(1,6);
	Card *gCardS	= new Card(0,5);
	Card *eCardF	= new Card(1,6);
	Card *gCardF	= new Card(1,14);
	Card *eCardFH	= new Card(2,6);
	Card *gCardFH	= new Card(2,14);
	Card *eCardFOAK	= new Card(0,6);
	Card *gCardFOAK	= new Card(1,6);
	Card *eCardSF	= new Card(1,4);
	Card *gCardSF	= new Card(1,2);

	// Making a hand for each of the types of hands that can be made
	Hand highCardHand		(eCardHC,		new Card(2, 2), new Card(0, 10), new Card(2, 12),	gCardHC);
	Hand doubleHand			(new Card(1,6),	eCardD,			new Card(0, 2), gCardD,				new Card(1, 14));
	Hand twoPairHand		(gCardTP,		new Card(2, 2), eCardTP,		new Card(2, 12),	new Card(1, 14));
	Hand threeOfAKindHand	(new Card(1,2), gCardTOAK,		new Card(0, 2), eCardTOAK,			new Card(1, 14));
	Hand straightHand		(new Card(1,3), new Card(2, 2), gCardS,			new Card(2, 4),		eCardS);
	Hand flushHand			(eCardF,		new Card(1, 2), new Card(1, 10),new Card(1, 12),	gCardF);
	Hand fullHouseHand		(new Card(1,6), eCardFH,		new Card(0, 6), gCardFH,			new Card(1, 14));
	Hand fourOfAKindHand	(gCardFOAK,		new Card(2, 6), eCardFOAK,		new Card(3, 6),		new Card(1, 14));
	Hand straightFlushHand	(new Card(1,3), gCardSF,		new Card(1, 5), eCardSF,			new Card(1, 6));

	// The expected score arrays from each of the Hands that will be tested
	int expectedHC[] =	{0,0,0,0,0,0,0,0,0,0,14,12,10,6,2};
	int expectedD[] =	{0,0,0,0,0,0,0,0,0,2,14,12,6,0,0};
	int expectedTP[] =	{0,0,0,0,0,0,0,12,2,0,14,0,0,0,0};
	int expectedTOAK[] ={0,0,0,0,0,0,2,0,0,0,14,12,0,0,0};
	int expectedS[] =	{0,0,0,0,0,6,0,0,0,0,0,0,0,0,0};
	int expectedF[] =	{0,0,0,0,14,0,0,0,0,0,14,12,10,6,2};
	int expectedFH[] =	{0,0,6,14,0,0,0,0,0,0,0,0,0,0,0};
	int expectedFOAK[] ={0,6,0,0,0,0,0,0,0,0,14,0,0,0,0};
	int expectedSF[] =	{6,0,0,0,0,0,0,0,0,0,6,5,4,3,2};

	// The Actual testing begins
	cout<<"Testing High Card Hand:"<<endl;
	testHand(highCardHand,		expectedHC,		false,	0, eCardHC,		4, gCardHC);	// High Card Hand Testing

	cout<<"Testing Double Hand:"<<endl;
	testHand(doubleHand,		expectedD,		false,	1, eCardD,		3, gCardD);		// Double Hand Testing

	cout<<"Testing Two Pair Hand:"<<endl;
	testHand(twoPairHand,		expectedTP,		false,	2, eCardTP,		0, gCardTP);	// Two Pair Hand Testing

	cout<<"Testing Three of a Kind Hand:"<<endl;
	testHand(threeOfAKindHand,	expectedTOAK,	false,	3, eCardTOAK,	1, gCardTOAK);	// Three of a Kind Hand Testing

	cout<<"Testing Straight Hand:"<<endl;
	testHand(straightHand,		expectedS,		true,	4, eCardS,		2, gCardS);		// Straight Hand Testing

	cout<<"Testing Flush Hand:"<<endl;
	testHand(flushHand,			expectedF,		true,	0, eCardF,		4, gCardF);		// Flush Hand Testing

	cout<<"Testing Full House Hand:"<<endl;
	testHand(fullHouseHand,		expectedFH,		true,	1, eCardFH,		3, gCardFH);	// Full House Hand Testing

	cout<<"Testing Four of a Kind Hand:"<<endl;
	testHand(fourOfAKindHand,	expectedFOAK,	true,	2, eCardFOAK,	0, gCardFOAK);	// Four of A Kind Hand Testing

	cout<<"Testing Straight Flush Hand:"<<endl;
	testHand(straightFlushHand, expectedSF,		true,	3, eCardSF,		1, gCardSF);	// Straight Flush Hand Testing
		
	// Because I'm an optimist
	return 1;
}

void testHand(Hand hand, int expectedArray[15], bool higherThanThreeOfAKind, int cardExchanged,
					Card* exchangedCard, int elementGot, Card* gotCard){
	int* score = hand.getScore();		// Retrieves the score of the hand given
	
	bool handIsCorrect = true;
	cout<<"Checking if getScore() is returning the right score"<<endl;

	cout<<"[ ";
	for(int i = 0; i < 15; i++){			// Checks if hand given equals the score expected
		if(score[i] != expectedArray[i]){	// Looks at each element in each array
			handIsCorrect = false;			// If not equal makes hand incorrect
		}
		cout<<score[i]<<" ";
	}
	cout<<"]"<<endl;

	if(handIsCorrect)
		cout<<"Success"<<endl;
	else
		cout<<"Failure"<<endl;
	
	cout<<"Checking if compareTo() method works"<<endl;
	
	int tempArray[] = {0,0,0,0,0,0,6,0,0,0,14,13,0,0,0};

	if(higherThanThreeOfAKind == hand.isHigherScore(tempArray))
		cout<<"Success"<<endl;
	else
		cout<<"Failure"<<endl;

	cout<<"Checking if cards are exchanging properly"<<endl;

	if(hand.exchange(new Card(2,3),cardExchanged) == exchangedCard)
		cout<<"Success"<<endl;
	else
		cout<<"Failure"<<endl;
	
	cout<<"Checking if getCard() method works"<<endl;

	//Card* tempCard = hand.getCard(elementGot);
	if(hand.getCard(elementGot) == gotCard)
		cout<<"Success"<<endl;
	else
		cout<<"Failure"<<endl;

	cout<<endl;
}

HandDriver::~HandDriver(void)
{
}
