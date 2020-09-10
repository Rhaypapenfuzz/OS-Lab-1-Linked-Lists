# list/Makefile
#
# Makefile for list implementation and test file.
#
# Raymond Gyabeng

CC=gcc
CFLAGS=-I.
DEPS = list.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o list.o 
	$(CC) -o main main.o list.o 
