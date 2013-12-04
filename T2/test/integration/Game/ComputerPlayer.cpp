/*
 * ComputerPlayer.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: Christopher J. Cunniff
 */

#include "ComputerPlayer.h"

#include <stdlib.h>
#include <time.h>
#include <cstddef>
#include <fstream>
#include <iostream>

#include "Bet.h"
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Hand.h"
#include "Player.h"
#include "SmallDeck.h"

extern Game game;

ComputerPlayer::ComputerPlayer(int num) {
	playerNum = num;
}



Bet ComputerPlayer::makeBet(SmallDeck C, int min) {
	
	Bet b = calculateBet(C, min);
	money -= b.getAmount();
	return b;
}

Bet ComputerPlayer::calculateBet(SmallDeck C, int min){

	int state = game.getState();
	srand ( (unsigned)time(0) );
	ifstream inputFile;
	inputFile.open("PocketRanking.txt");
	char temp[4];
	int rank;
	int card1;
	int card2;
	int suited;
	int cardsuits;
	int ComputerRank;
	
	
	Card temp1;
	Card temp2;
	Card temp3;
	Hand Current;
	SmallDeck d = *pocket;
	
	
	if(!C.isEmpty()){
		Current.putInCards(d, C);
		Current.evaluateCards();
	}
	temp1 | d.getCard(0);
	temp2 | d.getCard(1);


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
	int FP; //Flop Confidence
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
	
	int Act=0;
	int BettingAmount=0;
	int percent=rand()%10;	
	if (state==0){
		
		switch (PC){
			case 0:{
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
			break;	
			}
			case 1:{
				if(percent<3){
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
					BettingAmount = min==0 ? 40 : min;  //	BettingAmount = money < BettingAmount ? money : BettingAmount;

				}
			break;	
			}
			case 2:{
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
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
			break;	
			}
			case 3:{
				if (percent<8){
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
			break;
			}
			case 4:{
				
				if (percent<7){
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
			break;
			}
			case 5:{
				if (percent<5){
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
			break;
			}
	
		}
	}
	else {
		if(Current.getType()<13 && Current.getType()>=0 && PC > 2)
			FP=PC;
		else if(Current.getType()<13 && Current.getType()>=0 && PC <= 2)
			FP=PC-1;
		else if(Current.getType()<26 && Current.getType()>=13 && PC > 2)
			FP=PC+2;
		else if(Current.getType()<26 && Current.getType()>=13 && PC <= 2)
			FP=PC+1;	
		else if(Current.getType()<38 && Current.getType()>=26 && PC==1)
			FP=PC+3;
		else if(Current.getType()<38 && Current.getType()>=26 && PC > 1)
			FP=PC+4;	
		else if(Current.getType()<106 && Current.getType()>=38 )
			FP=10;	
		switch (FP){
			case -1:{
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
			case 0:{
				if(percent<9){
					if(min == 0){
					Act=0;
					BettingAmount=0;
					}
					else{
					Act=-1;
					BettingAmount=0;
					}
					
				}
				else{
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				break;
			}
			case 1:{
				if(percent<8){
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
					BettingAmount= min==0 ? 40 : min;
				}
				break;
			}
			case 2:{
				if(percent<7){
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
				else {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				break;
			}
			case 3:{
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
				else if(percent<9) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 4:{
				if(percent<3){
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
				else if(percent<8) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 5:{
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
				else if(percent<8) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 6:{
				if(percent<8) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 7:{
				if(percent<8) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 8:{
				if(percent<7) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				break;
			}
			case 9:{
				if(percent<7) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else if(percent<9) {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				else{
					Act=2;
					BettingAmount= min==0 ? 120 : 3*min;
				}
				break;
			}
			case 10:{
				if(percent<3) {
					Act=1;
					BettingAmount= min==0 ? 40 : min;
				}
				else if(percent<8) {
					Act=2;
					BettingAmount= min==0 ? 80 : 2*min;
				}
				else{
					Act=2;
					BettingAmount=min==0 ? 120 : 3*min;
				}
				break;
			}
	
		}
	}
	BettingAmount = money < BettingAmount ? money : BettingAmount;
	return Bet (Act, BettingAmount);
}




