#Makefile for Poker
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Bet.cpp Card.cpp ComputerPlayer.cpp Dealer.cpp Deck.cpp Display.cpp Game.cpp GameData.cpp Gui.cpp Hand.cpp HumanPlayer.cpp Layout.cpp MainDeck.cpp Player.cpp PlayerList.cpp Point.cpp SmallDeck.cpp Poker.cpp ../GameObject.cpp ../Advertisement.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=../T2.o

all: clean $(OBJECTS)

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

