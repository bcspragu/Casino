# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: CardT1.o Computer.o DealerT1.o DeckT1.o displayT1.o PlayerT1.o T1.o User.o

debug: CFLAGS += -g
debug: poker

CardT1.o: CardT1.cpp CardT1.h
	$(CC) $(CFLAGS) CardT1.cpp -o CardT1.o

Computer.o: Computer.cpp Computer.h
	$(CC) $(CFLAGS) Computer.cpp -o Computer.o

DealerT1.o: DealerT1.cpp
	$(CC) $(CFLAGS) DealerT1.cpp -o DealerT1.o

DeckT1.o: DeckT1.cpp DeckT1.h
	$(CC) $(CFLAGS) DeckT1.cpp -o DeckT1.o

displayT1.o: displayT1.cpp displayT1.h
	$(CC) $(CFLAGS) displayT1.cpp -o displayT1.o

PlayerT1.o: PlayerT1.cpp PlayerT1.h
	$(CC) $(CFLAGS) PlayerT1.cpp -o PlayerT1.o

T1.o: T1.cpp T1.h
	$(CC) $(CFLAGS) T1.cpp -o T1.o

User.o: User.cpp User.h
	$(CC) $(CFLAGS) User.cpp -o User.o

clean:
	rm -f *.o
