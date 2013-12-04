/* Author: Eli Siskind
 * Description: Encapsulates the display class to add the functionality needed
 * 				for the project.
 *
 * NOTES: 
 *		* Uses the given display class as is.
 */

#ifndef GUI_H
#define GUI_H

#include <ncurses.h>
#include <signal.h>

//#include "Display.h"
//#include "Layout.h"

class Bet;
class Game;
class Player;
class PlayerList;

class Gui{
public:
	Gui();
	~Gui();
	bool startGui(void);
	void showTurn(int p, Bet b);
	void update();
private:
	//static functions for redrawing on resize
	static void detectResize(int sig);
	static void redraw(void);
	static void clearScreen();
	static void displayCommon();
	static void displayPlayers();
	static void displayUserRegion(Player p);
};

#endif
