#include <stdio.h>
#include <math.h>

#define BINARY_REPR_LEN 32
#define LOG_2 0.693147180559945309417232121458176568075500134360255254120 /* ln(2) */
#define POW2_ACCUR 100000
#define MAX_INPUT 4294967296 /* pow(2, 32) */
#define STORE_DIGIT(varname, reprArr) varname = reprArr[BINARY_REPR_LEN - i - 1] == '0' ? 0 : 1;

/*
 * Returns the base 2 log of x. Calculation is done like so:
 *   log2(x) = ln(x) / log_e(2)
 * (since log_a(b) = log_c(b) / log_c(a))
 * @param x - The number to take log_2 of.
 * @return The base 2 log of x.
 */
double log2 (double x);

/*
 * Returns an integer symbolizing whether a number x is a power of 2.
 * This uses the fact that if x = pow(2, y), then y is a natural number, therefore complying to
 * the following boolean expression:
 *   round(ceil(y) - y) == 0
 * [The code includes some accuracy fixes since C isn't perfect]
 * @param x - The number to check whether it is a power of 2.
 * @return 1 if x is a power of 2, 0 otherwise.
 */
int powof2 (double x);

/*
 * Converts a decimal representation of a number (int) to a an array of characters of it's binary
 * representation. The calculation is done as follows:
 *   If num is a power of 2, set repr[log2(num)] to 1 and return.
 *   Else, set repr[i] to 0 if (num / round(pow(2, i))) % 2 == 0, else set to 1.
 * @param num - The number to convert to a binary representation.
 * @param repr - A pointer to the binary representation's char array.
 * @param reprLength - The representation's char array length.
 */
void dectobin(unsigned int num, char *repr, int reprLength);

/*
 * Converts a binary representation of a number (repr) to its decimal representation.
 * Algorithm:
 *   bintodec(repr) = sum(0, BINARY_REPR_LEN, repr[i] == 1 ? pow(2, i) : 0)
 * @param repr - A binary representation of a given number.
 * @return The decimal representation of the given number.
 */
int bintodec (char *repr);

/*
 * Adds the two numbers a and b according to the binary addition specified in the assignment.
 * @param a - A whole number, 0 ≤ a ≤ MAX_INPUT.
 * @param b - A whole number, 0 ≤ b ≤ MAX_INPUT.
 * @return a + b, calculated according to the assignment specifications.
 */
unsigned int my_add(unsigned int a, unsigned int b);
