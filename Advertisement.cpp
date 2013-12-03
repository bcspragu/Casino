#include "Advertisement.h"

Advertisement::Advertisement(void) {
	path = "advertisement.txt";
    srand(time(NULL));
}

Advertisement::~Advertisement(void) {};

string Advertisement::getAd(void) {
	int numLines = 0;
    string randLine;
    ifstream file(path.c_str());

    if(file.is_open()) {
        //count number of lines
        while (getline(file, randLine))
            numLines++;
    
        //go back to begining of file
        file.clear();
        file.seekg(0, ios::beg);

        //select a random line from file
        string temp;
        
        int randNum = rand();
        for (int i = 0; i < randNum % numLines + 1; i++) {
        	getline(file, randLine);
        }
        file.close();
    } else 
        return "Error in retrieving advertisement";
	return randLine;
}
