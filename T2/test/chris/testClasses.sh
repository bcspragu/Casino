#!/bin/bash

#cd HumanPlayer_Driver_and_Stubs
#make test
#cd ..
cd Player_Driver_and_Stubs
make test
cd ..
cd PlayerList_Driver_and_Stubs
make test

echo
./test
echo
#cd ..
#cd HumanPlayer_Driver_and_Stubs
#./test
echo
cd ..
cd Player_Driver_and_Stubs
./test
echo

