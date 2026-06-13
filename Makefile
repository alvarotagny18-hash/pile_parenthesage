CC = gcc
CFLAGS = -Wall -Iinclude

all: main run_tests

main: src/main.c src/pile_tableau.c src/pile_liste.c src/verification.c
	$(CC) $(CFLAGS) -o main src/main.c src/pile_tableau.c src/pile_liste.c src/verification.c

run_tests: tests/tests.c src/pile_tableau.c src/pile_liste.c src/verification.c
	$(CC) $(CFLAGS) -o run_tests tests/tests.c src/pile_tableau.c src/pile_liste.c src/verification.c

clean:
	rm -f main run_tests

.PHONY: all clean
