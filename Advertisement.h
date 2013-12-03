#ifndef ADVERTISEMENT_H_
#define ADVERTISEMENT_H_

#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Advertisement {
private:
	string path;
public:
	Advertisement();
	~Advertisement();
	string getAd();
};

#endif /*ADVERTISEMENT_H_*/
