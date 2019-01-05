#include <stdio.h>
#include <stdlib.h>
#include "lib/calculator/calculator.h"
#include "lib/utils/parser.h"
#include "lib/utils/file.h"

int main(int argc, const char * argv[]) {
  Calculator *calc = createCalculator();
  File *file = fileConstructor("program.txt", 256);

  if (argc < 2) {
    printf("Usage: %s [filenames...]\n", argv[0]);
  }

  populateContents(file);

  printf("%s\n", file->contents);

  destroyFile(file);
  destroyCalculator(calc);
  return 0;
}
