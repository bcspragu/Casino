/* Title: Display stub for gui driver
 * Author: Eli Siskind
 * Description: Substitutes ncurses terminal display with simple cin and cout
 * statements.
 */

#include "Display.h"

#include <locale.h>
#include <ncursesw/ncurses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <clocale>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "Card.h"
#include "Layout.h"
#include "Player.h"
#include "Point.h"
#include "SmallDeck.h"

using namespace std;

/* Function: This is the constructor.
 * Description: It is called whenever an object of class display is initialized
 */
Display::Display(void) {
	// setup the screen size settings.
	cols = 150;
	lines = 50;
	// this updates the locally stored col and line variables
	handleResize(0);
	// set a no card draw offset of 1 so the bottom banner is not overwritten
	lineBoundaryOffset = 1;
}

/* Function: This is the destructor.
 * Description: This is called just before an object is deleted.
 */
Display::~Display() {

}

int Display::captureInput(void) {
	return cin.get();
}

/*
 * Function: Updates all the information in the display class on window resize
 * Description: This function just updates information, it requires the call
 *		from a static singal handler. Signal handlers service interrupts and require
 *		a static function to be called, because they are not part of the main
 * 		program control flow. The signal handler should be declared in the main
 *		class, because your game should redraw the display on a resize.
 */
void Display::handleResize(int sig) {

}

void Display::displayPot(Point p, string name, int amount, int printAtt) {

	cout << name << " pot: " << amount << endl;

}

void Display::displayInfoBox(Point p, string title, string text1, string text2,
		int colorAtt) {

	cout << endl << title << endl;
	cout << text1 << endl;
	cout << text2 << endl << endl;

}

void Display::displayDeck(Point p) {

}

void Display::displayPlayerInfo(Player player, bool turn, bool button,
		bool faceUp, Point p) {

	//variables
	Card card1;
	Card card2;
	stringstream ss;

	cout << endl << "Info of player " << player.getNum() << ":" << endl;

	// extract info from layout
	int pNum = player.getNum();
	SmallDeck playerDeck = *(player.getPocket());

	//draw first card
	card1 = playerDeck.getCard(0);
	if (!(card1.isBlank() || faceUp))
		card1 = Card(1, 1);
	card1.print();

	// draw second card
	card2 = playerDeck.getCard(1);
	if (!(card2.isBlank() || faceUp))
		card2 = Card(1, 1);
	card2.print();
	cout << endl;

	// draw title
	int m = player.getMoney();
	ss.str("");
	cout << "P" << pNum << " $" << m << endl;
}

void Display::displayCard(Point p, Card card, int printAtt){

	cout << "Card displayed at: " << p.print();
	card.print();
	cout << endl;

}

/*
 * Function: Erases a rectangle on the screen
 * Description: x,y is for the top left corner, sizeX and sizeY set
 * 			how big the square is.
 */
void Display::eraseScreen() {

	cout << "Clearing screen." << endl;

}

/*
 * Function: Draws a box on the screen
 * Description: x,y is for the top left corner, sizeX and sizeY set
 *          how big the square is. printAtt allows for changes in the
 *			display settings.
 */
void Display::drawBox(Point p, int sizeX, int sizeY, bool doubleBorder,
		int printAtt) {

	cout << "Box at " << p.print() << "size: " << sizeX << ", " << sizeY
			<< endl;

}

/*
 * Function: Draws a banner of text at the bottom right of the screen
 * Description: Inverts the color and draws the banner at the bottom
 *		of the screen. Does not handle carriage returns on the string.
 */
void Display::bannerBottom(string bannerText) {
	cout << "Bottom Banner: " << bannerText << endl;
}

/*
 * Function: Draws a banner of text at the top left of the screen
 * Description: Inverts the color and draws the banner at the top
 *      of the screen. Does not handle carriage returns on the string.
 */
void Display::bannerTop(string bannerText) {

	cout << "Top Banner: " << bannerText << endl;
}

