#include "Advertisement.h"

Advertisement::Advertisement(void) {
	path = "advertisement.txt";
}

Advertisement::~Advertisement(void) {};

string Advertisement::getAd(void) {
	int numLines = 0;
    string line;
    ifstream file(path.c_str());

    //count number of lines
    while (getline(file, line))
        ++numLines;
    
    //go back to begining of file
    file.clear();
    file.seekg(0, ios::beg);
    
    string temp;
    for (int i = 0; i < (rand() % (numLines + 1)); i++) {
    	getline(file, line);
    }
    file.close();
    
	return line;
}
