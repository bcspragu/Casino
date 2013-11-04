/* Gui.cpp
 *
 * Author: Eli Siskind
 * Description: Wrapper class for using the functionality of the display class.
 *
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
	static void showWinner(int winner);
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
