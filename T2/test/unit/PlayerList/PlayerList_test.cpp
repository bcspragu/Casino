/*
 * PlayerList_test.cpp
 *
 *  Created on: Oct 29, 2013
 *      Author: esiskind
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

#include "PlayerList.h"
#include "Player.h"

using namespace std;

int main(int argc, char* argv[]) {

	Player * p;
	PlayerList pList;
	for (int i = 0; i < 8; i++) {
		p = new Player(i);
		pList.addPlayer(p);
	}
	pList.print();

	pList.remove();
	pList.print();

	pList.advanceButton();
	pList.print();

	pList.remove();
	pList.print();

	for (int i = 0; i < 5; i++) {
		pList.advanceButton();
	}

	pList.print();

	cout << endl << "Removing all:" << endl;
	pList.removeAll();
	pList.print();

	return 0;
}
