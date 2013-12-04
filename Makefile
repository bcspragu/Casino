# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC = g++
CFLAGS = -c
LFLAGS = -lncursesw

all: poker games

poker: Advertisement.o display.o GameObject.o main.o Timer.o

Advertisement.o: Advertisement.cpp Advertisement.h
	$(CC) $(CFLAGS) Advertisement.cpp -o Advertisement.o

display.o: display.cpp display.h
	$(CC) $(CFLAGS) display.cpp -o display.o

GameObject.o: GameObject.cpp GameObject.h
	$(CC) $(CFLAGS) GameObject.cpp -o GameObject.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

Timer.o: Timer.cpp Timer.h
	$(CC) $(CFLAGS) Timer.cpp -o Timer.o

clean:
	cd Objects; rm -f *.o

games:
	cd D1; make; cd ../T1; make; cd ../T2; make; cd ../Objects; cp ../T1/*.o .; cp ../T2/*.o .; cp ../D1/*.o .; cp ../*.o .; g++ *.o -o ../Casino -lncursesw
