CC=gcc
CFLAGS=-ansi -Wall -pedantic

all:
	@echo Compiling...
	@mkdir -p build
	@$(CC) $(CFLAGS) src/palindrome.c -o build/palindrome
	@$(CC) $(CFLAGS) src/my_add.c -o build/my_add
	@echo Compiled!

clean:
	@rm -rf build
	@echo Cleaned the build files
