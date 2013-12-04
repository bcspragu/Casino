#Makefile for Game_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Bet.cpp Card.cpp ComputerPlayer.cpp Dealer.cpp Deck.cpp Game.cpp\
Gui.cpp Hand.cpp HumanPlayer.cpp MainDeck.cpp Player.cpp PlayerList.cpp\
PlayerNode.cpp SmallDeck.cpp Game_test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

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

