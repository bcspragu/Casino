#Makefile for Poker
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Bet.cpp Card.cpp ComputerPlayer.cpp Dealer.cpp Deck.cpp Display.cpp Game.cpp\
GameData.cpp Gui.cpp Hand.cpp HumanPlayer.cpp Layout.cpp MainDeck.cpp Player.cpp PlayerList.cpp\
Point.cpp SmallDeck.cpp Poker.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=poker

all: clean $(SOURCES) $(EXECUTABLE)

display: 

debug: clean
debug: DEBUG +=-g
debug: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

