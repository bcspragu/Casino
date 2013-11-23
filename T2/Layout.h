/*
 * Layout.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Eli Siskind
 * Description: This defines the member functions and variables
 */

#ifndef Layout_H
#define Layout_H

#include "Card.h"
#include "Point.h"

#define PLAYERNUM 8
#define CARDW 6
#define CARDH 4

using namespace std;

class Layout {
public:
	Layout();
	~Layout();

	// setup the layout to fit the display
	void setup(int x, int y);

	// Getters for locations
	Point getSize();
	Point getCenter();
	Point getDeckArea();
	Point getDiscardArea();
	Point getCommCardArea(int i);
	Point getCenterPotArea();
	Point getPlayerInfoArea(int i);
	Point getPlayerCardArea(int i);
	Point getPlayerPotArea();

private:

	// Points for storing locations of things to display
	Point size;
	Point center;
	Point deckArea;
	Point discardArea;
	Point commCardArea[6];
	Point centerPotArea;
	Point playerInfoArea[PLAYERNUM];
	Point playerCardArea[3];
	Point playerPotArea;

	// Internal functions called by setup:
	void setSize(int x, int y);
	void setCenter();
	void setDeckArea();
	void setDiscardArea();
	void setCommCardArea();
	void setCenterPotArea();
	void setPlayerInfoArea();
	void setPlayerCardArea();
	void setPlayerPotArea();
};

#endif /* LAYOUT_H */
