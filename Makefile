
CC=gcc
CFLAGS= -g -Wall -I.
LINKFLAGS= -g -Wall

all: Main

Main: main.o data.o parity.o
	$(CC) $(LINKFLAGS) -o Main main.o data.o parity.o

data.o: data.c data.h parity.h
	$(CC) $(CFLAGS) -c data.c -o data.o

parity.o: parity.c parity.h data.h
	$(CC) $(CFLAGS) -c parity.c -o parity.o

main.o: main.c data.h parity.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o Main




