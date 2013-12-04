CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: displayD1.o Frame.o CardD1.o HandD1.o DeckD1.o PlayerD1.o HumanPlayer.o AI.o Poker.o

standalone: displayD1.o Frame.o CardD1.o HandD1.o DeckD1.o PlayerD1.o HumanPlayer.o AI.o Poker.o ../Advertisement.o ../Timer.o ../GameObject.o
	$(CC) PokerDriver.cpp displayD1.o Frame.o CardD1.o HandD1.o DeckD1.o PlayerD1.o HumanPlayer.o AI.o Poker.o ../Advertisement.o ../Timer.o ../GameObject.o $(LFLAGS) -o standalone

debug: CFLAGS += -g
debug: poker

AI.o: AI.cpp AI.h
	$(CC) $(CFLAGS) AI.cpp -o AI.o

CardD1.o: CardD1.cpp CardD1.h
	$(CC) $(CFLAGS) CardD1.cpp -o CardD1.o

DeckD1.o: DeckD1.cpp DeckD1.h
	$(CC) $(CFLAGS) DeckD1.cpp -o DeckD1.o

displayD1.o: displayD1.cpp displayD1.h
	$(CC) $(CFLAGS) displayD1.cpp -o displayD1.o $(LFLAGS)

Frame.o: Frame.cpp Frame.h
	$(CC) $(CFLAGS) Frame.cpp -o Frame.o

HandD1.o: HandD1.cpp HandD1.h
	$(CC) $(CFLAGS) HandD1.cpp -o HandD1.o

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp -o HumanPlayer.o

PlayerD1.o: PlayerD1.cpp PlayerD1.h
	$(CC) $(CFLAGS) PlayerD1.cpp -o PlayerD1.o

Poker.o: Poker.cpp Poker.h
	$(CC) $(CFLAGS) Poker.cpp -o Poker.o

../Advertisment.o: ../Advertisement.cpp ../Advertisement.h 
	$(CC) $(CFLAGS) ../Advertisement.cpp -o ../Advertisment.o

../Timer.o: ../Timer.cpp ../Timer.h 
	$(CC) $(CFLAGS) ../Timer.cpp -o ../Timer.o

../GameObject.o: ../GameObject.cpp ../GameObject.h 
	$(CC) $(CFLAGS) ../GameObject.cpp -o ../GameObject.o

clean:
	rm -f *.o

test: .FORCE

.FORCE:
	cd test; ./build_stuff.sh; g++ PokerDriver.cpp display.o Frame.o Card.o Hand.o Deck.o Player.o HumanPlayer.o AI.o -o testD1 -lncursesw; ./testD1; cd ..
