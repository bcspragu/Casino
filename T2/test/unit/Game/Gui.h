/* Author: Eli Siskind
 * Description: Encapsulates the display class to add the functionality needed
 * 				for the project.
 *
 * NOTES: 
 *		* Uses the given display class as is.
 */

#ifndef GUI_H
#define GUI_H

class Bet;
class Game;



using namespace std;

class Gui{
public:
	Gui();
	~Gui();
	bool startGui(void);
	void showTurn(int player, Bet bet);
	void update(Game g);
private:
	//static functions for redrawing on resize
	static void detectResize(int sig);
	static void redraw(void);
	static void clearScreen();
	static void displayCommon();
	static void displayPlayers();
	static void displayUserRegion();
};

#endif
