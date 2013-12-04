/*
 * Layout.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Eli
 */

#ifndef Layout_H_
#define Layout_H_

#include "Point.h"
#include "SmallDeck.h"


#define PLAYERNUM 8
#define CARDW 6
#define CARDH 5

using namespace std;

class Layout {
public:
	Layout();
	~Layout();

	// setup the layout to fit the display
	void setup(int x, int y);

	// getters
	Point getSize();
	Point getDeckArea();
	Point getDiscardArea();
	Point getCommCardArea(int i);
	Point getCenterPotArea();
	Point getPlayerInfoArea(int i);
	Point getPlayerCardArea(int i);
	Point getPlayerPotArea();
	SmallDeck getPlayerCards(int player);

private:
	Point size;
	Point center;
	Point deckArea;
	Point discardArea;
	Point commCardArea[6];
	Point centerPotArea;
	Point playerInfoArea[PLAYERNUM];
	Point playerCardArea[3];
	Point playerPotArea;
	SmallDeck humanCards;
	SmallDeck compCards[8];

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

#endif /* GUI_H_ */
