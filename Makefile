CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb
LIBS = -lSDL2 -lSDL2_image
# SRC = ./demo.c ./cube.c
all:
	$(CC) $(CFLAGS) -o cube ./cube.c $(LIBS)
	$(CC) $(CFLAGS) -o demo ./demo.c $(LIBS)
