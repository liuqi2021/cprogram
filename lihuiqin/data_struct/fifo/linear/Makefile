$CC ?= gcc

all:main

main:main.o fifo.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o main
