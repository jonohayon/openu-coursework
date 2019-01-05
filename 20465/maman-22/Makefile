CC=gcc-8
CFLAGS=-ansi -Wall -pedantic

all: mycomp.o complex.o utils.o calculator.o
	$(CC) -o play mycomp.o complex.o file.o parser.o calculator.o

mycomp.o: mycomp.c
	$(CC) $(CFLAGS) -c mycomp.c

complex.o: lib/complex/complex.h lib/complex/complex.c
	$(CC) $(CFLAGS) -c lib/complex/complex.c lib/complex/complex.h

calculator.o: lib/calculator/calculator.h lib/calculator/calculator.c
	$(CC) $(CFLAGS) -c lib/calculator/calculator.c lib/calculator/calculator.h

utils.o: lib/utils/*.h lib/utils/*.c
	$(CC) $(CFLAGS) -c lib/utils/*.h lib/utils/*.c

clean:
	rm *.o play
	find . -type f -name '*.gch' -exec rm {} +
