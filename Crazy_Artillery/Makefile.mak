CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=jeu
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
all: $(EXEC)
jeu: $(OBJ)
 $(CC) -o $@ $^ $(LDFLAGS)
main.o: jeu.h
%.o: %.c
 $(CC) -o $@ -c $< $(CFLAGS)
.PHONY: clean mrproper
clean:
 rm -rf *.o
mrproper: clean
 rm -rf $(EXEC)
