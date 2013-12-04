/*
 * Layout.h
 *
 *  Created on: Oct 27, 2013
 *      Author: Eli
 */

#ifndef Layout_H_
#define Layout_H_

//#include "Deck.h"
//#include "Display.h"

#include "Point.h"
#include "SmallDeck.h"

class Game;

#define PLAYERNUM 8
#define CARDW 6
#define CARDH 5

using namespace std;

class Layout {
public:
	Layout();
	~Layout();

	// setup the layout to fit the display
	void setup();

	// setting game status information
	void setBlankCards();
	void setPlayerCards();
	void setPot(int centerPot);
	void startTurn(int player);
	void endTurn();
	void setCurrentButton(int player);


	// getters
	Point getSize();
	Point getDeckArea();
	Point getDiscardArea();
	Point getCommCardArea(int i);
	Point getCenterPotArea();
	Point getPlayerInfoArea(int i);
	Point getPlayerCardArea(int i);
	Point getPlayerPotArea();
	SmallDeck getCompCards(int player);
	int getPot();
	bool isCurrent(int player);
	bool isButton(int player);

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

	int centerPot;
	int currentPlayer;
	int currentButton;

	// Internal functions called by setup:
	void setSize();
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
