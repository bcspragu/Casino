# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: Bet.o Card.o ComputerPlayer.o Dealer.o Deck.o T2Display.o Game.o GameData.o Gui.o Hand.o T2HumanPlayer.o 	Layout.o 	MainDeck.o 	Player.o 	PlayerList.o 	Point.o 	T2Poker.o 	SmallDeck.o

Bet.o: Bet.cpp Bet.h
	$(CC) $(CFLAGS) Bet.cpp -o Bet.o

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp -o Card.o

ComputerPlayer.o: ComputerPlayer.cpp ComputerPlayer.h
	$(CC) $(CFLAGS) ComputerPlayer.cpp -o ComputerPlayer.o

Dealer.o: Dealer.cpp Dealer.h
	$(CC) $(CFLAGS) Dealer.cpp -o Dealer.o

Deck.o: Deck.cpp Deck.h
	$(CC) $(CFLAGS) Deck.cpp -o Deck.o

T2Display.o: T2Display.cpp T2Display.h
	$(CC) $(CFLAGS) T2Display.cpp -o T2Display.o

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) Game.cpp -o Game.o

GameData.o: GameData.cpp GameData.h
	$(CC) $(CFLAGS) GameData.cpp -o GameData.o

Gui.o: Gui.cpp Gui.h
	$(CC) $(CFLAGS) Gui.cpp -o Gui.o

Hand.o: Hand.cpp Hand.h
	$(CC) $(CFLAGS) Hand.cpp -o Hand.o

T2HumanPlayer.o: T2HumanPlayer.cpp T2HumanPlayer.h
	$(CC) $(CFLAGS) T2HumanPlayer.cpp -o T2HumanPlayer.o

Layout.o: Layout.cpp Layout.h
	$(CC) $(CFLAGS) Layout.cpp -o Layout.o

MainDeck.o: MainDeck.cpp MainDeck.h
	$(CC) $(CFLAGS) MainDeck.cpp -o MainDeck.o

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp -o Player.o

PlayerList.o: PlayerList.cpp PlayerList.h
	$(CC) $(CFLAGS) PlayerList.cpp -o PlayerList.o

Point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) Point.cpp -o Point.o

T2Poker.o: T2Poker.cpp T2Poker.h
	$(CC) $(CFLAGS) T2Poker.cpp -o T2Poker.o

SmallDeck.o: SmallDeck.cpp SmallDeck.h
	$(CC) $(CFLAGS) SmallDeck.cpp -o SmallDeck.o

clean:
	rm -f *.o



