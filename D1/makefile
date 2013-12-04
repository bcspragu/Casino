CC = g++
CFLAGS = -Wall -c
LFLAGS = -lncursesw

all: poker

poker: display.o Frame.o Card.o Hand.o Deck.o Player.o HumanPlayer.o AI.o Advertisement.o GameObject.o Poker.o Timer.o

Frame.o: Frame.cpp Frame.h
	$(CC) $(CFLAGS) Frame.cpp

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

Hand.o: Hand.cpp Hand.h
	$(CC) $(CFLAGS) Hand.cpp

Deck.o: Deck.cpp Deck.h
	$(CC) $(CFLAGS) Deck.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	$(CC) $(CFLAGS) HumanPlayer.cpp
	
AI.o: AI.cpp AI.h
	$(CC) $(CFLAGS) AI.cpp

Poker.o: Poker.cpp Poker.h
	$(CC) $(CFLAGS) Poker.cpp

Advertisement.o: ../Advertisement.cpp ../Advertisement.h
	$(CC) $(CFLAGS) ../Advertisement.cpp

GameObject.o: ../GameObject.cpp ../GameObject.h
	$(CC) $(CFLAGS) ../GameObject.cpp

Timer.o: ../Timer.cpp ../Timer.h
	$(CC) $(CFLAGS) ../Timer.cpp

clean:
	rm -f *.o *~
