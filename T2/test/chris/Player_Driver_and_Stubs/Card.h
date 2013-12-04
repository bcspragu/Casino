/**
* Card.h
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#ifndef CARD_H_
#define CARD_H_

class Card {
private:
int suit;
int value;
public:
Card();
Card(int s, int v);
~Card();
int getValue();
int getSuit();
};

#endif /* CARD_H_ */
