#Makefile for Game_test
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS= $(DEBUG)
SOURCES=Player.cpp PlayerList.cpp PlayerListDriver.cpp PlayerNode.cpp
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

