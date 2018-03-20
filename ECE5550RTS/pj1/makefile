CC=gcc
CFLAGS=-Wall -g
DEPS = helper.h edf.h controller.h
OBJ = helper.o edf.o controller.o
INPUT=
OUTPUT=

all: proj1

run: all
	./proj1 $(INPUT)
#	./proj1 $(INPUT) $(OUTPUT)

proj1: main.c $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	rm -f *.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o proj1

.PHONY: clean all
