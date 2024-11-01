# Makefile for compiling matrix multiplication program

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: matmult_exec

matmult_exec: main.o matmult.o
	$(CC) $(CFLAGS) -o matmult_exec main.o matmult.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c

clean:
	rm -f *.o matmult_exec
