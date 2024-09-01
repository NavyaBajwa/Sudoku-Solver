CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)/*.c

all: sudoku_solver run clean

sudoku_solver:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./sudoku_solver

clean:
	rm -f sudoku_solver
