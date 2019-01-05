CC=gcc-8
CFLAGS=-ansi -Wall -pedantic

all: test.o time.o
	$(CC) -o test test.o time.o

test: all clean-no-test
	./test

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

time.o: time.h time.c
	$(CC) $(CFLAGS) -c time.c time.h

clean-no-test:
	rm *.o *.gch

clean: clean-no-test
	rm test
