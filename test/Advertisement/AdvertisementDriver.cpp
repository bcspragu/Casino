#include "Advertisement.h"
#include <iostream>

using namespace std;

int main () {
	Advertisement ad = Advertisement();
	for(int i = 0; i < 50; i++)
		cout << ad.getAd() << endl;
	return 0;
}
