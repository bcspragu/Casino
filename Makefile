#Makefile for Game_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=main.cpp Balance.cpp Timer.cpp T2/Bet.cpp T2/Display.cpp T2/Player.cpp T2/Card.cpp T2/Hand.cpp T2/PlayerList.cpp T2/ComputerPlayer.cpp T2/Game.cpp T2/HumanPlayer.cpp T2/Point.cpp T2/Dealer.cpp T2/GameData.cpp T2/Layout.cpp T2/SmallDeck.cpp T2/Deck.cpp T2/Gui.cpp T2/MainDeck.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=play

all: clean $(SOURCES) $(EXECUTABLE)

debug: clean
debug: DEBUG +=-g
debug: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
	

