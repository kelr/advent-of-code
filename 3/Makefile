CC=clang++
CFLAGS=-Wall -Wextra -pedantic -std=c++1z -O

all: Wires.o
	$(CC) $(CFLAGS) -o wires Wires.o

Wires.o: Wires.cpp
	$(CC) $(CFLAGS) -c Wires.cpp

.PHONY: clean
clean:
	rm -f *.o wires
