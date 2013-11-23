/*
 * Gui_test.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: Eli Siskind
 */

#include "Gui.h"

#include <signal.h>
#include <string>

using namespace std;

// The gameDisplay object is global, because the static signal handler object
// needs to access the dynamic object.
Display gameDisplay;


Layout Gui::gameLayout;
GameData Gui::gameData;
int Gui::userInputState = 0;

/*
 * This is the main function that starts the driver artifact.
 * This function demonstrates the abilities of display class
 */
int main(int argc, char* argv[]) {

	Gui gui;
	GameData data;
	gui.update(data, 0);

	return 0;
}
