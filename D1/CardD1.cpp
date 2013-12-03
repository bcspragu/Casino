#include "CardD1.h"
#include "Frame.h"
#include <iostream>

using namespace std;


CardD1::CardD1(int s, int r){
	frame = Frame();
	discard = false;
	suit = s;
	rank = r;
}
	
CardD1::~CardD1(){}

int CardD1::getSuit(){
	return suit;
}

int CardD1::getRank(){
	return rank;
}

void CardD1::setDiscarded(bool d){
	discard = d;
	if(discard)
		setFrame(frame.getX(), frame.getY()-2);
	else
		setFrame(frame.getX(), frame.getY());
}

bool CardD1::isDiscarded() {
	return discard;
}
	
void CardD1::setFrame(int x, int y){
	frame.setX(x);
	frame.setY(y);
}

int CardD1::getNumber(){
	if(rank == 14)
		return 1;
	else
		return rank;
}

Frame CardD1::getFrame(){
	return frame;
}
