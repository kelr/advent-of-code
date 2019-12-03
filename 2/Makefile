CC=clang++
CFLAGS=-Wall -Wextra -pedantic -std=c++1z -O

all: Intcode.o
	$(CC) $(CFLAGS) -o intcode Intcode.o

Intcode.o: Intcode.cpp
	$(CC) $(CFLAGS) -c Intcode.cpp

.PHONY: clean
clean:
	rm -f *.o intcode
