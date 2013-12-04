#pragma once
#include "CardD1.h"
#include <vector>

using namespace std;

class HandD1{
private:
	vector<CardD1*> hand;
	int ranks[13];
	
public: 
	HandD1(CardD1 *c1, CardD1 *c2, CardD1 *c3, CardD1 *c4, CardD1 *c5);
	CardD1* exchange(CardD1* c, int placeOfCard);
	bool isHigherScore(int secondScore[15]);
	bool compareTo(int secondScore[15]);
	void highCard(int *score);
	bool isDouble(int *score);
	bool isTwoPair(int *score);
	bool isThreeofaKind(int *score);
	bool isStraight(int *score);
	bool isFlush(int *score);
	bool isFullHouse(int *score);
	bool isFourofaKind(int *score);
	bool isStraightFlush(int *score);
	int* getScore();
	CardD1* getCard(int element);
};

