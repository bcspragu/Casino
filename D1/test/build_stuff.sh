#!/bin/bash

rm -f *.o


echo "In $PWD copying files"
cp ../Frame* .
cp ../Card* .
cp ../Hand* .
cp ../Deck* .
cp ../Player* .

echo "Compiling..."
g++ display.cpp -c
g++ Frame.cpp -c
g++ Card.cpp -c
g++ Hand.cpp -c
g++ Deck.cpp -c
g++ Player.cpp -c

