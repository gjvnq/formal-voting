CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -O2 -g -march=native -Wno-unused-command-line-argument
DEPS=main.o basics.o

all: main.bin

main.bin: $(DEPS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -o $@