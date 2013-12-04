# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC=g++
DEBUG=
CFLAGS=-c -Wall $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=TestMain.cpp Hand.cpp Card.cpp Deck.cpp
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

