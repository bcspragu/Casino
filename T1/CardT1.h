#ifndef CARDT1_H
#define CARDT1_H

#include <string>
#include "SuitValue.h"

using std::string;

class CardT1 {
  public:
    CardT1(Suit s, Value v);
    CardT1(string s);
    ~CardT1(void);
    Suit suit;
    Value value;
    static Suit suitFromInt(int i);
    static Value valueFromInt(int i);
    string cardString();
    string shortCardString();
    bool operator<(const CardT1 &other) const;
};

#endif
