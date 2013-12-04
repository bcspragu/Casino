#include "HumanPlayer.h"
#include "displayD1.h"
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

HumanPlayer::HumanPlayer(int displayPos, int initialMoney, string name) : PlayerD1(displayPos, initialMoney, name) {}

/**
 * Ask the player if they want to ante. If they fold,
 * remove them from the game. If they call, proceed normally.
 *  - Alex
 */
int HumanPlayer::ante(int minimumAnte, displayD1 &gameDisplay) {
    int input;

    stringstream bannerText;
    bannerText << "Current Ante: " << minimumAnte << "; a:ante up; l:leave game";
    gameDisplay.bannerBottom(bannerText.str());

    //Drawing the ante and leave 'buttons'
    int box_width = 30;
    int box_height = 7;
    int y_ante = 7;
    int y_leave = y_ante + box_height + 2;
    int x_coord = 15;
    gameDisplay.drawBox(x_coord, y_ante, box_width, box_height, 0);
    gameDisplay.drawBox(x_coord, y_leave, box_width, box_height, 0); 
    mvprintw(y_ante + box_height/2, x_coord + box_width/2 - 2, "Ante!");
    mvprintw(y_leave + box_height/2, x_coord + box_width/2 - 2, "Leave");

    //check if player has enough money
    if (money < minimumAnte) {
        gameDisplay.eraseBox(x_coord, y_ante, box_width, box_height);
        bannerText.str("");
        bannerText << "Ante is " << minimumAnte << "; You do not have enough money to ante. Ending game. <Press any key to continue>";
        gameDisplay.bannerBottom(bannerText.str());
        while (1) {
            input = gameDisplay.captureInput();
            if (input != 0) {
                return PlayerD1::FOLD;
            }
        }
    }

    while (1) {
        input = gameDisplay.captureInput();

		if (input == -1) {
	 
			 gameDisplay.drawBox(x_coord, y_ante, box_width, box_height, 0);
			 gameDisplay.drawBox(x_coord, y_leave, box_width, box_height, 0); 
			mvprintw(y_ante + box_height/2, x_coord + box_width/2 - 2, "Ante!");
			mvprintw(y_leave + box_height/2, x_coord + box_width/2 - 2, "Leave");
		}
        switch (input) {
            case 'a': case 'A':
                moneyInPot += minimumAnte;
                money -= minimumAnte;
                gameDisplay.eraseBox(x_coord, y_ante, box_width, box_height);
                gameDisplay.eraseBox(x_coord, y_leave, box_width, box_height); 
                return PlayerD1::CALL;

            case 'l': case 'L':

                gameDisplay.eraseBox(x_coord, y_ante, box_width, box_height);
                gameDisplay.eraseBox(x_coord, y_leave, box_width, box_height); 
                return PlayerD1::FOLD;

            case -1: //mouse press
                int mouse_x = gameDisplay.getMouseEventX();
                int mouse_y = gameDisplay.getMouseEventY();
                if (within(mouse_x, mouse_y, x_coord, y_ante, box_width, box_height)) {
                    moneyInPot += minimumAnte;
                    money -= minimumAnte;
                    gameDisplay.eraseBox(x_coord, y_ante, box_width, box_height);
                    gameDisplay.eraseBox(x_coord, y_leave, box_width, box_height); 
                    return PlayerD1::CALL;
                } else if (within(mouse_x, mouse_y, x_coord, y_leave, box_width, box_height)) {
                    gameDisplay.eraseBox(x_coord, y_ante, box_width, box_height);
                    gameDisplay.eraseBox(x_coord, y_leave, box_width, box_height); 
                    return PlayerD1::FOLD;
                }
                break;
        }
    }
}

/**
 * Ask the player how much they want to bid.
 * Once a legal bid is made, subtract the bid from the player's money.
 * Note: If a player bids more than they have, they go all in.
 * Add the player's bid to the player's moneyInPot.
 * If the player folds, set the fold flag for that player.
 * returns the amount bid, unless the player folds, in which case Player::FOLD is returned
 */

int HumanPlayer::bet(int minimumBet, displayD1 &gameDisplay) {
    int currentBid = 0;
    int input;

    if (hasFolded) {
        return PlayerD1::FOLD;
    }

    int x_allin = 1;
    int x_fold = 10;
    int x_raise = 58;
    int x_call = 67;
    int y_button = 18;
    int w_button = 8;
    int h_button = 5;
    gameDisplay.drawBox(x_allin, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_fold, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_raise, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_call, y_button, w_button, h_button, 0);
    mvprintw(y_button + h_button/2-1, x_allin + w_button/2 - 1, "all");
    mvprintw(y_button + h_button/2, x_allin + w_button/2 - 1, "in");
    mvprintw(y_button + h_button/2, x_fold + w_button/2 - 2, "fold");
    mvprintw(y_button + h_button/2, x_raise + w_button/2 - 2, "raise");
    if (minimumBet == 0 ) {
        mvprintw(y_button + h_button/2, x_call + w_button/2 - 2, "check");
    } else {
        mvprintw(y_button + h_button/2, x_call + w_button/2 - 2, "call");
    }

    stringstream bannerText;
    if (money < minimumBet) {
        bannerText << "Call: " << minimumBet << "; Not enough money; f:fold; a:all in;" << currentBid << "  ";
    } else {
        bannerText << "Minimum: " << minimumBet << "; f:fold; c:call/check; a:all in; current bid: " << currentBid << "  ";
    }

    gameDisplay.bannerBottom(bannerText.str());

    while (1) {
        input = gameDisplay.captureInput();

        //mouse press
        if (input == -1) {
            int mouse_x = gameDisplay.getMouseEventX();
            int mouse_y = gameDisplay.getMouseEventY();
            if (within(mouse_x, mouse_y, x_allin, y_button, w_button, h_button)) {
                input = 'a';
            } else if (within(mouse_x, mouse_y, x_fold, y_button, w_button, h_button)) {
                input = 'f';
            } else if (within(mouse_x, mouse_y, x_call, y_button, w_button, h_button)) {
                input = 'c';
            } else if (within(mouse_x, mouse_y, x_raise, y_button, w_button, h_button)) {
                input = 'r';
            }
            gameDisplay.bannerBottom(bannerText.str());
    gameDisplay.drawBox(x_allin, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_fold, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_raise, y_button, w_button, h_button, 0);
    gameDisplay.drawBox(x_call, y_button, w_button, h_button, 0);
    mvprintw(y_button + h_button/2-1, x_allin + w_button/2 - 1, "all");
    mvprintw(y_button + h_button/2, x_allin + w_button/2 - 1, "in");
    mvprintw(y_button + h_button/2, x_fold + w_button/2 - 2, "fold");
    mvprintw(y_button + h_button/2, x_raise + w_button/2 - 2, "raise");
    if (minimumBet == 0 ) {
        mvprintw(y_button + h_button/2, x_call + w_button/2 - 2, "check");
    } else {
        mvprintw(y_button + h_button/2, x_call + w_button/2 - 2, "call");
    }
        }
        //If the bid ever becomes negative, something went wrong, so reset it.
        if (currentBid < 0) {
            currentBid = 0;
        } else if (currentBid > money) {
            currentBid = money;
        }

        if (money < minimumBet) {
            switch (input) {
                //Fold
                case 'f': case 'F':
                    hasFolded = true;
                    gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                    return PlayerD1::FOLD;

                    //All In
                case 'a': case 'A':
                    currentBid = money;
                    moneyInPot += currentBid;
                    money -= currentBid;
                    gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                    return currentBid;
            }
        } else {
            switch (input) {
                //The player typed a number, so update the bid accordingly
                case '0': case '1': case '2':
                case '3': case '4': case '5':
                case '6': case '7': case '8':
                case '9':
                    currentBid = (currentBid) * 10 + (input - '0');
                    currentBid = min(currentBid, money);
                    bannerText.str("");
                    bannerText << "Minimum: " << minimumBet << "; f:fold; c:call/check; a:all in; current bid: " << currentBid << "  ";
                    gameDisplay.bannerBottom(bannerText.str());
                    break;

                    //Fold
                case 'f': case 'F':
                    hasFolded = true;
                    gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                    return PlayerD1::FOLD;

                    //Call/Check
                case 'c': case 'C':
                    currentBid = minimumBet;
                    moneyInPot += currentBid;
                    money -= currentBid;
                    gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                    return currentBid;

                    //All In
                case 'a': case 'A':
                    currentBid = money;
                    moneyInPot += currentBid;
                    money -= currentBid;
                    gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                    gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                    return currentBid;

                    //Backspace and delete characters
                case 8: case 127: case 330: case 263:
                    currentBid = currentBid/10;
                    bannerText.str("");
                    bannerText << "Minimum: " << minimumBet << "; f:fold; c:call/check; a:all in; current bid: " << currentBid << "  ";
                    gameDisplay.bannerBottom(bannerText.str());
                    break;

                    //Player pressed ENTER, b, or B (for Bid), r or R (for Raise)
                case '\r': case 10: case 'b': case 'B': case 'r': case 'R':
                    if (currentBid < minimumBet) {
                        currentBid = 0;
                        bannerText.str("");
                        bannerText << "ERROR: Bid too low; Minimum: " << minimumBet << "; f:fold; c:call/check; a:all in; current bid: " << currentBid << "  ";
                        gameDisplay.bannerBottom(bannerText.str());
                    } else if (currentBid >= money) { //If a player bids more than they have, they go all in
                        currentBid = money;
                        moneyInPot += currentBid;
                        money -= currentBid;
                        gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                        return currentBid;
                    } else if (currentBid == 0) {
                        gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                        return PlayerD1::CHECK;
                    } else {
                        moneyInPot += currentBid;
                        money -= currentBid;
                        gameDisplay.eraseBox(x_allin, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_fold, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_call, y_button, w_button, h_button);
                        gameDisplay.eraseBox(x_raise, y_button, w_button, h_button);
                        return currentBid;
                    }
                    break;
            }
        }
    }
}

/**
 * Ask the player which cards they want to discard
 * Set the discard flag for each card the player wants to discard
 * Return the number of cards the player wants to discard
 */
int HumanPlayer::discard(displayD1 &gameDisplay) {
    int input;
    stringstream bannerText;
    bannerText << "Cards to discard: <Press ENTER or (d) when done>";
    gameDisplay.bannerBottom(bannerText.str());

    //Draw the discard 'button
    int x_discard = 60;
    int y_discard = 18;
    int w_discard = 15; 
    int h_discard = 5;
    gameDisplay.drawBox(x_discard, y_discard, w_discard, h_discard, 0);
    mvprintw(y_discard + h_discard/2, x_discard + w_discard/2 - 3, "Discard");

    //Reset all the discard flags
    int i;
    for (i = 0; i < 5; i++) {
        hand->getCard(i)->setDiscarded(false);
    }

    while (1) {
        input = gameDisplay.captureInput();

        int cardIndex = 0;
        int discardCount = 0;

		if (input == -1) {
    gameDisplay.drawBox(x_discard, y_discard, w_discard, h_discard, 0);
    mvprintw(y_discard + h_discard/2, x_discard + w_discard/2 - 3, "Discard");
		}
        switch(input) {
            //Player indicates a card 1-5, so toggle that card's discard flag
            case '1': case '2':
            case '3': case '4':
            case '5':
                cardIndex = input - '1';
                hand->getCard(cardIndex)->setDiscarded(!hand->getCard(cardIndex)->isDiscarded());
                break;

                //Backspace and delete buttons, removes the right-most discard
            case 8: case 127: case 330: case 263:
                for (i = 4; i >= 0; i--) {
                    if (hand->getCard(i)->isDiscarded()) {
                        hand->getCard(i)->setDiscarded(false);
                        break;
                    }
                }
                break;

                //Player pressed ENTER, d, D (for discard), so discard the selected cards.
            case '\r': case 10: case 'd': case 'D':
                discardCount = 0;
                for (i = 0; i < 5; i++) {
                    if (hand->getCard(i)->isDiscarded()) {
                        discardCount++;
                    }
                }
                gameDisplay.eraseBox(x_discard, y_discard, w_discard, h_discard);
                return discardCount;

            case -1: //mouse press

                //If a button is pressed too long, it will fire two events, thus not correctly toggling the discard flag
                if (gameDisplay.getMouseEventButton() == RIGHT_UP || gameDisplay.getMouseEventButton() == LEFT_UP) {
                    break;
                }

                int mouse_x = gameDisplay.getMouseEventX();
                int mouse_y = gameDisplay.getMouseEventY();

                for (i = 0; i < 5; i++) {
                    if (within(mouse_x, mouse_y, 21+i*7, 18, 5, 4)) {
                        hand->getCard(i)->setDiscarded(!hand->getCard(i)->isDiscarded());
                        break;
                    }
                }

                if (within(mouse_x, mouse_y, x_discard, y_discard, w_discard, h_discard)) {
                    discardCount = 0;
                    for (i = 0; i < 5; i++) {
                        if (hand->getCard(i)->isDiscarded()) {
                            discardCount++;
                        }
                    }
                    gameDisplay.eraseBox(x_discard, y_discard, w_discard, h_discard);
                    return discardCount;
                }
                break;
        }   

        //Update the banner text to show which cards are currently selected for discard
        if (input != 0) {
            bannerText.str("Cards to discard: ");
            for (i = 0; i < 5; i++) {
                if (hand->getCard(i)->isDiscarded()) {
                    bannerText << (i+1) << " ";
                }
            }
            bannerText << "<Press ENTER or (d) when done>";
            gameDisplay.bannerBottom(bannerText.str());
        }
    }
}

bool HumanPlayer::within(int mouse_x, int mouse_y, int box_x, int box_y, int box_width, int box_height) {
    return (mouse_x >= box_x) && (mouse_x <= box_x + box_width) && (mouse_y >= box_y) && (mouse_y <= box_y + box_height);
}
