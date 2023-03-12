CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb
LIBS = -lSDL2 -lSDL2_image
SRC = ./main.c ./window.c
all:
	$(CC) $(CFLAGS) $(SRC) $(LIBS)
