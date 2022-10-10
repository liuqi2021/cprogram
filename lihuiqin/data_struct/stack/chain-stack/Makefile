
.phony: all clean

all:app

app:main.o stack.o linklist.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o app