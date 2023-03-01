CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb
LIBS = -lSDL2
SRC = ./main.c
all:
	$(CC) $(CFLAGS) -o run $(SRC) $(LIBS)
run: all 
	./run
