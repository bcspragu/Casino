/**
* Gui.h
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#ifndef GUI_H
#define GUI_H

class Bet;
class Game;
class Player;
class PlayerList;

class Gui{
public:
	Gui();
	~Gui();
	Bet getBetInput(int minBet);
	int getAmount();
};

#endif
