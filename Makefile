CC=g++
CFLAGS=-c -Wall

all: safex

safex: src/main.o
	$(CC) src/main.o -o safex

main.o: src/main.cc
	$(CC) $(CFLAGS) main.cc

clean:
	rm -rf src/*.o safex
