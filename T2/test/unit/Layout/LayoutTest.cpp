#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstddef>
#include <time.h>
#include "Layout.h"
using namespace std;
int main(){
	Layout L;
	L.setup(5,7);
	cout<< L.getSize().print() << endl;
	cout<< L.getDeckArea().print() << endl;
	cout<< L.getDiscardArea().print() << endl;
	cout<< L.getCommCardArea(4).print() << endl;
	cout<< L.getCenterPotArea().print() << endl;
	cout<< L.getPlayerInfoArea(3).print() << endl;
	cout<< L.getPlayerCardArea(2).print() << endl;
	cout<< L.getPlayerPotArea().print() << endl;
}
