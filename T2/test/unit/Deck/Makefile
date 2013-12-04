#Makefile for Deck_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Deck.cpp Card.cpp Deck_Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: clean $(SOURCES) $(EXECUTABLE)

debug: clean
debug: DEBUG +=-g
debug: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

