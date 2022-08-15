$CC ?= gcc

all:main

main:main.o linear_link_list.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o main
