#Compiler & Linker
CC = gcc
LD = gcc

#Options
CFLAGS = -Wall -ansi -pedantic

#All *.c & *o files
SRC = $(wildcard *.c)
OBJS = $(SRC:%.c=%.o)

#Output
EXE = $(SRC:%.c=%)

#all : ${EXE}
all : cleaner main
	./main > data && gnuplot plot && gv tri.ps &

#Linking
${EXE} : $(OBJS)
	$(LD) $(OBJS) -o $@

#Compilation
%.o : %.c
	$(CC) $(CFLAGS) $< -c

clean :
	rm -f $(OBJS)
	
cleaner : clean
	rm -f $(EXE)

