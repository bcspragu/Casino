#Makefile for Game_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=main.cpp Timer.cpp Advertisement.cpp GameObject.cpp display.cpp T1.o T2.o D1.o
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=play

all: clean $(SOURCES) $(EXECUTABLE)

debug: clean
debug: DEBUG +=-g
debug: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	cd D1; make; cd ../T1; make; cd ../T2; make; cd ..; 
