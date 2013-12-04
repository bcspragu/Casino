#!/bin/bash

rm -f *.o

#Make the display.o file
cd ../display_class
echo "In $PWD making display"
make
cd ../test

echo "In $PWD copying files"
cp ../display_class/display.o .
cp ../Frame* .
cp ../Card* .
cp ../Hand* .
cp ../Deck* .
cp ../Player* .

echo "Compiling..."
g++ Frame.cpp -c
g++ Card.cpp -c
g++ Hand.cpp -c
g++ Deck.cpp -c
g++ Player.cpp -c

