CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: displayD1.o Frame.o CardD1.o HandD1.o DeckD1.o PlayerD1.o HumanPlayer.o AI.o Poker.o

AI.o: AI.cpp AI.h
	$(CC) $(CFLAGS) AI.cpp -o ../Objects/AI.o

CardD1.o: CardD1.cpp CardD1.h
	$(CC) $(CFLAGS) CardD1.cpp -o ../Objects/CardD1.o

DeckD1.o: DeckD1.cpp DeckD1.h
	$(CC) $(CFLAGS) DeckD1.cpp -o ../Objects/DeckD1.o

DeckDriver.o: DeckDriver.cpp
	$(CC) $(CFLAGS) DeckDriver.cpp -o ../Objects/DeckDriver.o

displayD1.o: displayD1.cpp displayD1.h
	$(CC) $(CFLAGS) displayD1.cpp -o ../Objects/displayD1.o

Frame.o: Frame.cpp Frame.h
	$(CC) $(CFLAGS) Frame.cpp -o ../Objects/Frame.o

HandD1.o: HandD1.cpp HandD1.h
	$(CC) $(CFLAGS) HandD1.cpp -o ../Objects/HandD1.o

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp -o ../Objects/HumanPlayer.o

PlayerD1.o: PlayerD1.cpp PlayerD1.h
	$(CC) $(CFLAGS) PlayerD1.cpp -o ../Objects/PlayerD1.o

Poker.o: Poker.cpp Poker.h
	$(CC) $(CFLAGS) Poker.cpp -o ../Objects/Poker.o

clean:
	rm -f *.o
