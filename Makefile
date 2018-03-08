CC=gcc

CFLAGS=-std=c11  -lm

all: grade

sim: sim.c test.c
	$(CC) -o sim sim.c test.c -lm

grade: sim
	./sim

clean:
	rm -rf *.o sim
