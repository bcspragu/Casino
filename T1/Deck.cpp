#include <algorithm>
#include <time.h>
#include "Deck.h"
#include "CardT1.h"
#include "SuitValue.h"

Deck::Deck(){
  fill();
}

Deck::~Deck(){}

void Deck::fill(){
  cards.clear();
  for(int i = 0; i < 52; i++){
    Suit s = CardT1::suitFromInt(i/13);
    Value v = CardT1::valueFromInt(i % 13);
    cards.push_back(CardT1(s,v));
  }

}

void Deck::shuffle(){
  std::srand(time(0));
  std::random_shuffle(cards.begin(),cards.end());
}

CardT1 Deck::dealCard(){
  CardT1 top = cards.front();
  cards.erase(cards.begin());
  return top;
}

int Deck::cardCount(){
  return cards.size();
}

string Deck::displayHand(std::vector<CardT1> cards){
  string handString = "";
  std::vector<CardT1>::iterator itr;
  for(itr = cards.begin(); itr != cards.end(); ++itr){
    handString += (*itr).shortCardString() + " ";
  }
  return handString;
}
