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
#include "Layout.h"

class Bet;
class Game;
class Player;
class PlayerList;

class Gui{
public:
	Gui();
	~Gui();
	bool startGui(void);
	static void showRoundWinner(int roundWinner);
	static void update(int status);
	Bet getBetInput(int minBet);
private:

	//static functions for redrawing on resize
	static void delay(int delay);
	static void detectResize(int sig);
	static void redraw();
	static void clearScreen();
	static void displayCommon();
	static void displayPlayers();
	static void displayUserRegion(Player p);

	//functions for user input
	int getBetType(int minBet);
	int getBetAmount();
};

#endif
