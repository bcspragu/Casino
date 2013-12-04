# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC=g++
DEBUG=
CFLAGS=-c $(DEBUG)
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=*.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: clean $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) 

clean:
	rm -rf *.o
