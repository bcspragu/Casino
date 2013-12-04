/**
* Game.h
*
*  Created on: Oct 25, 2013
*      Author: Christopher J. Cunniff
*
*      stub
*/

#ifndef GAME_H
#define GAME_H

#include "Gui.h"

class Game {
public:
	Game();
	~Game();
	Gui getGui(){return gui;}
	int getButNum();
	friend class Gui;
private:
	Gui gui;
};

#endif /* GAME_H */
