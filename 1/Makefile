CC=clang++
CFLAGS=-Wall -Wextra -pedantic -std=c++1z -O

all: Mass.o
	$(CC) $(CFLAGS) -o mass Mass.o

Mass.o: Mass.cpp
	$(CC) $(CFLAGS) -c Mass.cpp

.PHONY: clean
clean:
	rm -f *.o mass
