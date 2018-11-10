all: play

play: util1.o util2.o main.o
	gcc-8 -o play main.o util1.o util2.o

util1.o: util1.c util1.h
	gcc-8 -ansi -Wall -pedantic -c util1.c

util2.o: util2.c util2.h util1.h
	gcc-8 -ansi -Wall -pedantic -c util2.c

main.o: main.c util1.h util2.h
	gcc-8 -ansi -Wall -pedantic -c main.c

clean:
	rm *.o play
