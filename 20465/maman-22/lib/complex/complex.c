#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "complex.h"

Complex *complexConstructor (double re, double im) {
  Complex *z = (Complex *) malloc(sizeof(Complex));

  z->re = re;
  z->im = im;

  return z;
}

Complex *zeroPtr () {
  return complexConstructor(0, 0);
}

Complex complexAdd (Complex z, Complex w) {
  Complex res = ZERO;
  res.re = z.re + w.re;
  res.im = z.im + w.im;

  return res;
}

Complex complexMult (Complex z, Complex w) {
  double resultRe = z.re * w.re - z.im * w.im;
  double resultIm = z.re * w.im + z.im * w.re;

  Complex res = ZERO;
  res.re = resultRe;
  res.im = resultIm;

  return res;
}

double complexAbs (Complex z) {
  return sqrt(pow(z.re, 2) + pow(z.im, 2));
}

void complexPrint (Complex z) {
  printf("%f + i%f", z.re, z.im);
}
