/*
 * ComputerPlayer.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "ComputerPlayer.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstddef>
#include <time.h>
//ComputerPlayer::ComputerPlayer(){}


Bet* ComputerPlayer::makeBet(SmallDeck C, int min) {
	srand ( (unsigned)time(0) );
	ifstream inputFile;
	inputFile.open("PocketRanking.txt");
	char temp[4];
	int rank;
	int card1;
	int card2;
	int suited;
	int cardsuits;
	int state;
	int ComputerRank;
	state=0;
	// switch(C.getSize()){
		// case 3 :
			// state=1;
			// break;
		// case 4 : 
			// state=2;
			// break;
		// case 5:
			// state=3;
			// break;
		// default:
			// state=0;
	// }
	
	
	Card temp1;
	Card temp2;
	Card temp3;
	Hand Current;
	SmallDeck d = deck;
	
	
	if(!C.isEmpty()){
		Current.putInCards(deck, C);
		Current.evaluateCards();
	}
	temp1 | *d.draw();
	temp2 | *d.draw();


	if(temp1.getSuit()==temp2.getSuit()){
		cardsuits=1;
		}
	else{
		cardsuits=0;
		}
	if(temp2.getValue() > temp1.getValue()){
			temp3 | temp1;
			temp1 | temp2;
			temp2 | temp3;	
	}
	
	for(int i = 0; i < 169; i++){   
	
		inputFile.getline(temp, 4, '	');
		inputFile >> temp;
		rank = atoi ( temp);
		
		inputFile.getline(temp, 4, '	');
		inputFile >> temp;
		card1 = atoi ( temp);
		
		inputFile.getline(temp, 4, '	');
		inputFile >> temp;
		card2 = atoi ( temp);
		
		inputFile.getline(temp, 4, '	');
		inputFile >> temp;
		suited = atoi ( temp);
		
		
		if(card1==temp1.getValue() && card2==temp2.getValue() && suited==cardsuits)
			ComputerRank=rank;
	
	}
	
	int PC; //PocketConfidence
	
	if (ComputerRank<=169 && ComputerRank>=120)
		PC=0;
	else if (ComputerRank<=119 && ComputerRank >= 80)
		PC=1;
	else if (ComputerRank<=79 && ComputerRank >= 30)
		PC=2;
	else if (ComputerRank<=29 && ComputerRank >= 20)
		PC=3;
	else if (ComputerRank<=19 && ComputerRank >= 10)
		PC=4;
	else if (ComputerRank<=9 && ComputerRank >= 1)
		PC=5;
	int Act;
	int BettingAmount;
	int percent=rand()%10;	
	if (state==0){
		switch (PC){
			case 0:
				if(min == 0){
					Act=0;
					BettingAmount=0;
				}
				else{
					Act=-1;
					BettingAmount=0;
				}
				break;
			case 1:
				if(percent<5){
					if(min == 0){
					Act=0;
					BettingAmount=0;
					}
					else{
					Act=-1;
					BettingAmount=0;
					}
					break;
				}
				else{
					Act=1;
					BettingAmount=min;
				}
			case 2:
				if(percent<1){
					if(min == 0){
					Act=0;
					BettingAmount=0;
					}
					else{
					Act=-1;
					BettingAmount=0;
					}
					break;
				}
				else if (percent<8){
					Act=1;
					BettingAmount=min;
				}
				else {
					Act=2;
					BettingAmount=2*min;
				}
			case 3:
				if (percent<8){
					Act=1;
					BettingAmount=min;
				}
				else {
					Act=2;
					BettingAmount=2*min;
				}
			case 4:
				if (percent<7){
					Act=1;
					BettingAmount=min;
				}
				else {
					Act=2;
					BettingAmount=2*min;
				}
			case 5:
				if (percent<5){
					Act=1;
					BettingAmount=min;
				}
				else {
					Act=2;
					BettingAmount=2*min;
				}
	
		}
	}
	Bet* b = new Bet(Act, BettingAmount);
	
	
	
	return b; //change later..
}




