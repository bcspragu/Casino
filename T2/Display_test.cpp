/*
 * Display_test.cpp
 *
 *  Created on: Nov 8, 2013
 *      Author: Eli
 */

#include "Display.h"
#include "Point.h"
#include "Card.h"

#include <signal.h>
#include <ncursesw/ncurses.h>
#include <cstdio>
#include <iostream>
#include <string>

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

	Point p;
	Point size;
	char key;
	Card card1(0, 0);
	Card card2(1, 1);
	Card card3(2, 5);
	Card card4(3, 13);

	// Display 4 cards

	p.set(1, 2);
	gameDisplay.displayCard(p, card1);

	p.move(8, 0);
	gameDisplay.displayCard(p, card2);

	p.move(8, 0);
	gameDisplay.displayCard(p, card3);

	p.move(8, 0);
	gameDisplay.displayCard(p, card4);

	p.move(8, 0);
	size.set(10, 5);
	gameDisplay.displayBox(p, size, true, COLOR_PAIR(1));



	// infinite loop to wait for user input
	for (;;) {

		// calls the game display to capture some input
		key = gameDisplay.captureInput();

		// if a key was pressed
		if (key == 'e')
			break;
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

