#ifndef calculator_h
#define calculator_h

#define NUM_OF_VARS 6

#include "../complex/complex.h"

typedef struct {
  Complex *A;
  Complex *B;
  Complex *C;
  Complex *D;
  Complex *E;
  Complex *F;
} Calculator;

Calculator *createCalculator (void);
void destroyCalculator (Calculator *calc);
Complex *getVariableByName (Calculator *calc, char name);

#endif /* calculator_h */
