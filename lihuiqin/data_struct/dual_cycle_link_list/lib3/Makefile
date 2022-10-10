
.phony: all clean

all:app

app:main.o linklist.o
	$(CC) $^ -o $@

clean:
	rm -rf *.o app