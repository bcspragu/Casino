/*
 * Display_test.cpp
 * Author: Eli Siskind
 * Description: Testing driver for display class
 */

#include "Player.h"
#include "Card.h"
#include "SmallDeck.h"
#include "Point.h"

#include <signal.h>
#include <ncurses.h>
#include <cstdlib>
#include <sstream>

#include "Display.h"

using namespace std;

/* No Header file for this example driver artifact
 * function declaration here instead.
 */
// Signal Subroutine for Window Resize
static void detectResize(int sig);
// stub artifact for what the game does when the screen resizes
void stub_PrintResize(void);

// The gameDisplay object is global, because the static signal handler object
// needs to access the dynamic object.
Display gameDisplay;

/*
 * This is the main function that starts the driver artifact.
 * This function demonstrates the abilities of display class
 */
int main(int argc, char* argv[]) {
	// using a stringstream rather than a string to make making the banner easier
	stringstream messageString;

	// various variable declarations
	char key;
	Point loc;
	Card card(2, 4);
	int attr = A_NORMAL | COLOR_PAIR(2);
	Player player;

	// enable a interrupt triggered on a window resize
	signal(SIGWINCH, detectResize); // enable the window resize signal

	// infinite loop for the main program, you can press ctrl-c to quit
	for (;;) {
		gameDisplay.bannerTop(
				"[Draw card: c] [Draw info box: b] [Draw player info: i] [Display pot : p]");
		gameDisplay.bannerBottom("[Clear screen: spacebar]");
		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		switch (key) {
		case 'c':
			loc.set(1, 2);
			gameDisplay.displayCard(loc, card, attr);
			break;
		case 'b':
			loc.set(10,2);
			gameDisplay.displayInfoBox(loc, "TITLE", "This is an", "info box.", attr);
			break;
		case 'i':
			loc.set(40, 2);
			gameDisplay.displayPlayerInfo(player, true, true, true, loc);
			break;
		case ' ':
			gameDisplay.eraseScreen();
			break;
		case 'p':
			loc.set(60, 2);
			gameDisplay.displayPot(loc, "Example", 100, attr);
			break;
		}
	}

	return 0;
}

/*
 * This is the interrupt service routine called when the resize screen
 * signal is captured.
 */
void detectResize(int sig) {
	// update the display class information with the new window size
	gameDisplay.handleResize(sig);
	// re-enable the interrupt for a window resize
	signal(SIGWINCH, detectResize);
	/*INSERT YOUR OWN SCREEN UPDATE CODE instead of stub_PrintResize*/
	stub_PrintResize();
}

/*
 * This is a simple stub that should be replaced with what the game does
 * when the screen resizes.
 */
void stub_PrintResize(void) {
	// gets the new screen size
	int cols = gameDisplay.getCols();
	int lines = gameDisplay.getLines();
	// setups a message stream
	stringstream messageString;
	messageString << "Terminal is " << cols << "x" << lines;
	// prints out the information of the new screen size in a top banner
	gameDisplay.bannerTop(messageString.str());
}

