#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

Calculator *createCalculator () {
  Calculator *calc = (Calculator *) malloc(sizeof(Calculator));

  calc->A = zeroPtr();
  calc->B = zeroPtr();
  calc->C = zeroPtr();
  calc->D = zeroPtr();
  calc->E = zeroPtr();
  calc->F = zeroPtr();

  return calc;
}

void destroyCalculator (Calculator *calc) {
  free(calc->A);
  free(calc->B);
  free(calc->C);
  free(calc->D);
  free(calc->E);
  free(calc->F);

  free(calc);
}

Complex *getVariableByName (Calculator *calc, char name) {
  if (name - 'A' < 0 || NUM_OF_VARS < name - 'A') {
    printf("Variable with name %c isn't in the calculator\n", name);
    return NULL;
  }

  if (calc == NULL) {
    return NULL;
  }

  switch (name) {
    case 'A': return calc->A;
    case 'B': return calc->B;
    case 'C': return calc->C;
    case 'D': return calc->D;
    case 'E': return calc->E;
    case 'F': return calc->F;
    default: return NULL;
  }
}
