#include "SmallDeck.h"

class Player;

#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <math.h>
#include <iostream>
using namespace std;

Hand::Hand(Player * p) {
	cardArray = new Card[7];
	type = -1;
	tieBreaker = -1;
	valid = -1;
	length = -1;
	player = p;
}

Hand::Hand() {
	cardArray = new Card[7];
	type = -1;
	tieBreaker = -1;
	valid = -1;
	length = -1;
	player = NULL;
}

Hand::~Hand() {

}

int Hand::getType(){ return type;}
int Hand::getTieBreaker(){ return tieBreaker;}

void Hand::putInCards(SmallDeck pocket, SmallDeck community) {
	int i = 1;
	int j = 1;
	if (pocket.isEmpty() || community.isEmpty()) {
		cout << "ERROR: HAND HAS NO CARDS" << endl;
	} else {
		while (i <= pocket.getSize()) {
		//	cout << "adding...";
			cardArray[i - 1] = pocket.getCard(i);
			//cout << "added" << endl;
			i++;
		}
		cout << endl;
		while (j <= pocket.getSize()) {
			cardArray[i + j - 2] = community.getCard(j);
		//	cout << "added" << endl;
			j++;

		}
		valid = 1;
		length = i + j;
		quickSort(cardArray, 0, length - 1);
	}
}

int Hand::operator >(Hand h) {
	if (this->type == -1 || h.type == -1) {
		return -1;
	} else if (this->type > h.type) {
		return 1;
	} else if (this->type < h.type) {
		return 0;
	} else if (this->type == h.type) {
		if (this->tieBreaker > h.tieBreaker) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return -1;
	}
}

void Hand::evaluateCards() {
	while (true) {
		if (this->valid != 1) {
			this->type = -1;
			this->tieBreaker = -1;
			cout << "ERROR: HAND HAS NO CARDS" << endl;
			break;
		}
		if (this->fourOfaKind() != 0) {
			this->type = this->fourOfaKind();
			break;
		}

		if (this->threeOfaKind() % 100 != 36 && this->pair() % 100 != 11) {
			this->tieBreaker = (this->threeOfaKind()) / 100;
			this->type = (((((this->threeOfaKind()) / 10) % 10) * 10)
					+ this->threeOfaKind() % 10) + 32;
			break;
		}

		if (this->straight() != 0) {
			this->type = this->straight();
			break;
		}
		if (this->flush() != 0) {
			this->type = this->flush();
			break;
		}
		if (this->threeOfaKind() % 100 != 36) {
			this->tieBreaker = (this->threeOfaKind()) / 100;
			this->type = (((((this->threeOfaKind()) / 10) % 10) * 10)
					+ this->threeOfaKind() % 10);
			break;
		}
		if (this->pair() % 100 != 11) {
			this->tieBreaker = (this->pair()) / 100;
			this->type = ((((this->pair()) / 10) % 10) * 10)
					+ this->pair() % 10;
			break;
		}

		else {
			this->type = (this->cardArray[this->length - 1].getValue()) - 2;
			this->tieBreaker = (this->cardArray[this->length - 2].getValue())
					- 2;
			break;
		}

	}
}

int Hand::pair() {
	int paired = 0;
	int countpairs = 0;
	int doublepair = 0;
	int i;
	int TieBreaker = 0;
	for (i = 0; i < this->length - 1; i++) {
		if (this->cardArray[i].getValue()
				== this->cardArray[i + 1].getValue()) {
			if ((this->cardArray[i].getValue()
					!= this->cardArray[i + 2].getValue())
					|| i == this->length - 2) {
				if (countpairs == 1) {
					doublepair = 1;
					TieBreaker = paired;
				}
				paired = cardArray[i].getValue();
				countpairs++;
			}
			i++;
		}
	}

	if (doublepair == 1) {
		paired = paired + (TieBreaker * 100);
		return paired + 23;
	} else {
		if (this->cardArray[this->length - 1].getValue() == paired) {
			paired = paired
					+ 100 * this->cardArray[(this->length) - 3].getValue();
		} else {
			paired = paired
					+ 100 * this->cardArray[this->length - 1].getValue();
		}
		return paired + 11;
	}
}

int Hand::threeOfaKind() {
	int triple = 0;
	int i;
	for (i = 0; i < (this->length - 2); i++) {
		if (this->cardArray[i].getValue() == this->cardArray[i + 1].getValue()
				&& this->cardArray[i].getValue()
						== this->cardArray[i + 2].getValue()) {
			triple = cardArray[i].getValue();
		}
	}
	if (this->cardArray[this->length - 1].getValue() == triple)
		triple = triple + 100 * this->cardArray[this->length - 4].getValue();
	else
		triple = triple + 100 * this->cardArray[this->length - 1].getValue();
	return triple + 36;

}

int Hand::straight() {
	int straight;
	int i;
	int HighCard = 0;
	int iterate;
	int iteratorLimit;
	int flush;
	for (i = 0; i < 3; i++) {
		iterate = 0;
		iteratorLimit = 4;
		flush = 1;
		straight = 1;

		while (iterate < iteratorLimit) {
			if (this->cardArray[this->length].getValue() == 14
					&& this->cardArray[0].getValue() == 2 && i == 0) {
				if (this->cardArray[this->length].getSuit()
						!= this->cardArray[0].getSuit()) {
					flush = 0;
				}
				iteratorLimit = 3;
			}
			iterate++;
			if (this->cardArray[i].getValue() + iterate
					!= this->cardArray[i + iterate].getValue()) {
				straight = 0;
				break;
			}
			if (this->cardArray[i].getSuit()
					!= this->cardArray[i + iterate].getSuit()) {
				flush = 0;
			}
		}
		if (straight == 1)
			HighCard = (this->cardArray[i + iterate].getValue() + 46);
		if (straight == 1 && flush == 1)
			HighCard = (this->cardArray[i + iterate].getValue() + 91);
	}
	return HighCard;
}

int Hand::flush() {
	int suit1 = 0;
	int HighCard1 = 0;
	int suit2 = 0;
	int HighCard2 = 0;
	int suit3 = 0;
	int HighCard3 = 0;
	int suit4 = 0;
	int HighCard4 = 0;
	int i;
	for (i = 0; i < (this->length); i++) {
		switch (this->cardArray[i].getSuit()) {
		case 1:
			suit1++;
			if (this->cardArray[i].getValue() > HighCard1)
				HighCard1 = this->cardArray[i].getValue();
			break;
		case 2:
			suit2++;
			if (this->cardArray[i].getValue() > HighCard2)
				HighCard2 = this->cardArray[i].getValue();
			break;
		case 3:
			suit3++;
			if (this->cardArray[i].getValue() > HighCard3)
				HighCard3 = this->cardArray[i].getValue();
			break;
		case 4:
			suit4++;
			if (this->cardArray[i].getValue() > HighCard4)
				HighCard4 = this->cardArray[i].getValue();
			break;
		}
	}
	if (suit1 == 5)
		return HighCard1 + 55;
	else if (suit2 == 5)
		return HighCard2 + 55;
	else if (suit3 == 5)
		return HighCard3 + 55;
	else if (suit4 == 5)
		return HighCard4 + 55;
	else
		return 0;
}

int Hand::fullHouse() {

}

int Hand::fourOfaKind() {
	if ((this->cardArray[0].getValue() == this->cardArray[3].getValue()
			&& this->length > 3)
			|| (this->cardArray[1].getValue() == this->cardArray[4].getValue()
					&& this->length > 4)
			|| (this->cardArray[2].getValue() == this->cardArray[5].getValue()
					&& this->length > 5)
			|| (this->cardArray[3].getValue() == this->cardArray[6].getValue()
					&& this->length > 6))
		return cardArray[3].getValue() + 81;
	else
		return 0;

}

void Hand::quickSort(Card arr[], int left, int right) {
	int i = left;
	int j = right;
	Card temp;
	int pivot = arr[(left + right) / 2].getValue();

	while (i <= j) {
		while (arr[i].getValue() < pivot)
			i++;
		while (arr[j].getValue() > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

Player * Hand::getPlayer() {
	return player;
}

