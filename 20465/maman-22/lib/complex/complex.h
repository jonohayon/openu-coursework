#ifndef complex_h
#define complex_h

#define ZERO {0, 0}

/**
 * Complex number typedef
 *
 * re - The real part of the complex number
 * im - The imaginary part of the complex number
 */
typedef struct {
  double re;
  double im;
} Complex;

/**
 * Constructs a new Complex struct pointer.
 *
 * @param re The real part of the new complex number
 * @param im The imaginary part of the new complex number
 * @return A pointer to a new Complex struct instance
 */
Complex *complexConstructor (double re, double im);

/**
 * A pointer to zero
 */
Complex *zeroPtr (void);

/**
 * Adds two complex numbers together.
 * If z = Complex{a, b}, w = Complex{c, d} then
 * complexAdd(z, w) = Complex{a + c, b + d}
 *
 * @param z The first complex number to add
 * @param w The second complex number to add
 * @return The result of the complex addition defined above
 */
Complex complexAdd (Complex z, Complex w);

/**
 * Multiplies two complex numbers together.
 * If z = Complex{a, b}, w = Complex{c, d} then
 * complexMult(z, w) = Complex{ac - bd, ad + bc}
 *
 * @param z The first complex number to multiply
 * @param w The second complex number to multiply
 * @return The result of the complex multiplication defined above
 */
Complex complexMult (Complex z, Complex w);

/**
 * Computes the absolute value of a complex number.
 * If z = Complex{a, b}, then
 * complexAbs(z) = sqrt(a * a + b * b)
 *
 * @param z The number to calculate the absolve value of
 * @return The absolute value of z as defined above
 */
double complexAbs (Complex z);

/**
 * Prints a complex number to the screen
 */
void complexPrint (Complex z);

#endif /* complex_h */
