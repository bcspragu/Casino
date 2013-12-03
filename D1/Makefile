CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: displayD1.o Frame.o Card.o HandD1.o DeckD1.o Player.o HumanPlayer.o AI.o Poker.o

AI.o: AI.cpp AI.h
	$(CC) $(CFLAGS) AI.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

DeckD1.o: DeckD1.cpp DeckD1.h
	$(CC) $(CFLAGS) DeckD1.cpp

DeckDriver.o: DeckDriver.cpp
	$(CC) $(CFLAGS) DeckDriver.cpp

displayD1.o: displayD1.cpp displayD1.h
	$(CC) $(CFLAGS) displayD1.cpp

Frame.o: Frame.cpp Frame.h
	$(CC) $(CFLAGS) Frame.cpp

HandD1.o: HandD1.cpp HandD1.h
	$(CC) $(CFLAGS) HandD1.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

Poker.o: Poker.cpp Poker.h
	$(CC) $(CFLAGS) Poker.cpp

clean:
	rm -f *.o
