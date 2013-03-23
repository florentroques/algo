all: run

run: tri.o statistiques.o main.o
	gcc tri.o statistiques.o main.o -o run -lm
	@echo Compilation finie

clean:
	rm -f run tri.o statistiques.o main.o

%.o: %.c
	gcc -c -Wall -ansi $<

