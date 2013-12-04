# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: Bet.o Card.o ComputerPlayer.o Dealer.o Deck.o Display.o Game.o GameData.o Gui.o Hand.o T2HumanPlayer.o 	Layout.o 	MainDeck.o 	Player.o 	PlayerList.o 	Point.o 	Poker.o 	SmallDeck.o

Bet.o: Bet.cpp Bet.h
	$(CC) $(CFLAGS) Bet.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

ComputerPlayer.o: ComputerPlayer.cpp ComputerPlayer.h
	$(CC) $(CFLAGS) ComputerPlayer.cpp

Dealer.o: Dealer.cpp Dealer.h
	$(CC) $(CFLAGS) Dealer.cpp

Deck.o: Deck.cpp Deck.h
	$(CC) $(CFLAGS) Deck.cpp

Display.o: Display.cpp Display.h
	$(CC) $(CFLAGS) Display.cpp

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) Game.cpp

GameData.o: GameData.cpp GameData.h
	$(CC) $(CFLAGS) GameData.cpp

Gui.o: Gui.cpp Gui.h
	$(CC) $(CFLAGS) Gui.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) $(CFLAGS) Hand.cpp

T2HumanPlayer.o: T2HumanPlayer.cpp T2HumanPlayer.h
	$(CC) $(CFLAGS) T2HumanPlayer.cpp

Layout.o: Layout.cpp Layout.h
	$(CC) $(CFLAGS) Layout.cpp

MainDeck.o: MainDeck.cpp MainDeck.h
	$(CC) $(CFLAGS) MainDeck.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

PlayerList.o: PlayerList.cpp PlayerList.h
	$(CC) $(CFLAGS) PlayerList.cpp

Point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) Point.cpp

Poker.o: Poker.cpp
	$(CC) $(CFLAGS) Poker.cpp

SmallDeck.o: SmallDeck.cpp SmallDeck.h
	$(CC) $(CFLAGS) SmallDeck.cpp

clean:
	rm -f *.o



