#Makefile for Game_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=play

all: clean $(SOURCES) $(EXECUTABLE)

debug: clean
debug: DEBUG +=-g
SOURCES: T2/Player.o T2/Deck.o T2/SmallDeck.o T2/HumanPlayer.o T2/GameData.o T2/ComputerPlayer.o T2/Hand.o T2/PlayerList.o T2/Layout.o T2/Display.o T2/Card.o T2/Game.o T2/Gui.o T2/Bet.o T2/Point.o T2/MainDeck.o T2/Poker.o T2/Dealer.o GameObject.o Advertisement.o D1/Player.o D1/Deck.o D1/HumanPlayer.o D1/Hand.o D1/GameObject.o D1/Timer.o D1/Advertisement.o D1/Card.o D1/display.o D1/AI.o D1/Frame.o D1/Poker.o T1/Player.o T1/Deck.o T1/T1.o T1/Card.o T1/display.o T1/Computer.o T1/User.o T1/Dealer.o
debug: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	cd D1; make; cd ../T1; make; cd ../T2; make; cd ..; 



