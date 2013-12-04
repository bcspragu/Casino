# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: Card.o Computer.o Dealer.o Deck.o display.o Player.o T1.o User.o

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp

Computer.o: Computer.cpp Computer.h
	$(CC) $(CFLAGS) Computer.cpp

Dealer.o: Dealer.cpp
	$(CC) $(CFLAGS) Dealer.cpp

Deck.o: Deck.cpp Deck.h
	$(CC) $(CFLAGS) Deck.cpp

display.o: display.cpp display.h
	$(CC) $(CFLAGS) display.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) Player.cpp

T1.o: T1.cpp T1.h
	$(CC) $(CFLAGS) T1.cpp

User.o: User.cpp User.h
	$(CC) $(CFLAGS) User.cpp

clean:
	rm -f *.o
