/* Gui.cpp
 *
 * Author: Eli Siskind
 * Description: Wrapper class for using the functionality of the display class.
 *
 */

#ifndef GUI_H
#define GUI_H

#include "Bet.h"
#include "../Advertisement.h"
 #include <unistd.h>

class Bet;
class GameData;
class Layout;

using namespace std;

class Gui{
public:
	Gui();
	~Gui();
	bool startGui(void);
	static void update(GameData data, int status);
	static void showWinner(int winnerNum);
	static bool showRoundWinner(int roundWinnerNum, int amount, int roundNum);
	static Bet getBetInput();
	static void newAd();

private:
	static Advertisement ad;

	static string advertisement;

	// Everything is static because it can be updated at any time
	// detectResize, which needs a static variable.

	// Layout object defines cards and positions
	static Layout gameLayout;

	// Display and game data for storing some information
	static GameData gameData;

	// Flag for remembering user input state on resize
	static int userInputState;

	// Functions for redrawing on resize
	static void detectResize(int sig);
	static void redraw();
	static void drawCommon();
	static void drawComputerPlayers();
	static void drawHumanPlayer();

	// Functions for user input
	static BetAction getBetAction();
	static int getBetAmount();
};

#endif
