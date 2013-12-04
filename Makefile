# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker

poker: Advertisement.o display.o GameObject.o main.o Timer.o

Advertisement.o: Advertisement.cpp Advertisement.h
	$(CC) $(CFLAGS) Advertisement.cpp

display.o: display.cpp display.h
	$(CC) $(CFLAGS) display.cpp

GameObject.o: GameObject.cpp GameObject.h
	$(CC) $(CFLAGS) GameObject.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Timer.o: Timer.cpp Timer.h
	$(CC) $(CFLAGS) Timer.cpp

clean:
	rm -f *.o


