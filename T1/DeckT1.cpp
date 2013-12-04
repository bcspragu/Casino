#include <algorithm>
#include <time.h>
#include "DeckT1.h"
#include "CardT1.h"
#include "SuitValue.h"

DeckT1::DeckT1(){
  fill();
}

DeckT1::~DeckT1(){}

void DeckT1::fill(){
  cards.clear();
  for(int i = 0; i < 52; i++){
    Suit s = CardT1::suitFromInt(i/13);
    Value v = CardT1::valueFromInt(i % 13);
    cards.push_back(CardT1(s,v));
  }

}

void DeckT1::shuffle(){
  std::srand(time(0));
  std::random_shuffle(cards.begin(),cards.end());
}

CardT1 DeckT1::dealCard(){
  CardT1 top = cards.front();
  cards.erase(cards.begin());
  return top;
}

int DeckT1::cardCount(){
  return cards.size();
}

string DeckT1::displayHand(std::vector<CardT1> cards){
  string handString = "";
  std::vector<CardT1>::iterator itr;
  for(itr = cards.begin(); itr != cards.end(); ++itr){
    handString += (*itr).shortCardString() + " ";
  }
  return handString;
}
