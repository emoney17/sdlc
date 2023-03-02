CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb
LIBS = -lSDL2
SRC = ./main.c ./application.c
all:
	$(CC) $(CFLAGS) -o run.o $(SRC) $(LIBS)
