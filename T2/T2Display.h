/* Display Class Header File
 * Author: Eli Siskind
 * Description: Defines constants and class prototypes and variables
 */

// These are include files they are used for accessing functions and
// variables in external libraries.

#ifndef T2DISPLAY_H
#define T2DISPLAY_H

#include <ncursesw/ncurses.h>
#include <cstdio>
#include <iostream>
#include <string>

class Card;
class Player;
class Point;

// This is the namespace std, without this you would need to add "std::" 
// infront of every variable and function from the std library. 
using namespace std;

// These Mouse Mask Definitions are for some of the common mouse buttons
// that are used in this project.
#define LEFT_UP    1
#define LEFT_DOWN  2
#define LEFT_CLICK 4
#define LEFT_DOUBLECLICK 24

#define RIGHT_UP    4096
#define RIGHT_DOWN  8192
#define RIGHT_CLICK 16384
#define RIGHT_DOUBLECLICK 32768

#define MIDDLE_ROLLUP    1048576
#define MIDDLE_ROLLDOWN  256

// Some extended character definitions for showing the special symbols
// in the extended UTF-8 character map.
const char joker[]	  = {0xE2, 0x98, 0xBA, 0};
const char clubs[]    = {0xE2, 0x99, 0xA3, 0};
const char diamonds[] = {0xE2, 0x99, 0xA6, 0};
const char hearts[]   = {0xE2, 0x99, 0xA5, 0};
const char spades[]   = {0xE2, 0x99, 0xA0, 0};

// Enumeration for text justification
enum Just { LEFT, RIGHT, CENTER };

/*
 * This is the display class definitions
 */
class T2Display {
public:

	/*
	 * * * * Constructor and destructor * * * *
	 */
	T2Display(void);
	~T2Display(); // destructor

	/*
	 * * * * User interaction functions * * * *
	 */

	// get user input
	int captureInput(void);
	// stores new screensize on update
	void handleResize(int sig);

	/*
	 * * * * Drawing commands * * * *
	 */

	void eraseScreen(bool eraseBanners);
	void eraseBox(Point start, Point size);
	void displayCard(Point p, Card card);
	void displayText(Point p, string text, Just justify, int color);
	void displayBox(Point p, Point size, bool doubleBorder, int color);
	void bannerBottom(string bannerText);
	void bannerTop(string bannerText);

	/*
	 * * * * Getters * * * *
	 */

	int getCols(void) {return cols;}
	int	getLines(void) {return lines;}
	int getMouseEventX(void) {return mouseEventX;}
	int getMouseEventY(void) {return mouseEventY;}
	int getMouseEventButton(void) {return mouseEventButton;}

	// Updates the screen after you finish drawing
	void updateScreen(void) {refresh();}

	// sets an offset for when cards clip the bottom of the screen
	void setBottomOffset(int offset) {lineBoundaryOffset=offset;}

private:

	// Used to draw a card
	void printFace(Card card, int line, int attr);
	void printSuit(int suit);
	void printNumber(int number);

	// Information about the display
	int cols;
	int lines;	
	int mouseEventX;
	int mouseEventY;
	int	mouseEventButton;
	int lineBoundaryOffset;
};

#endif
