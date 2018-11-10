#include <stdio.h>
#include <math.h>

#define BINARY_REPR_LEN 32
#define LOG_2 0.693147180559945309417232121458176568075500134360255254120 /* ln(2) */
#define POW2_ACCUR 100000
#define MAX_INPUT 2147483648 /* pow(2, 31) */
#define STORE_DIGIT(varname, reprArr) (varname = reprArr[BINARY_REPR_LEN - i - 1] == '0' ? 0 : 1);

/*
 * Returns the base 2 log of x. Calculation is done like so:
 *   log2(x) = ln(x) / log_e(2)
 * (since log_a(b) = log_c(b) / log_c(a))
 * @param x - The number to take log_2 of.
 * @return The base 2 log of x.
 */
double log2 (double x) {
  return log(x) / LOG_2;
}

/*
 * Returns an integer symbolizing whether a number x is a power of 2.
 * This uses the fact that if x = pow(2, y), then y is a natural number, therefore complying to
 * the following boolean expression:
 *   round(ceil(y) - y) == 0
 * [The code includes some accuracy fixes since C isn't perfect]
 * @param x - The number to check whether it is a power of 2.
 * @return 1 if x is a power of 2, 0 otherwise.
 */
int powof2 (double x) {
  double l2 = log2(x); /* Base 2 log of x */
  return (int) round((ceil(l2) - l2) * POW2_ACCUR) == 0;
}

/*
 * Converts a decimal representation of a number (int) to a an array of characters of it's binary
 * representation. The calculation is done as follows:
 *   If num is a power of 2, set repr[log2(num)] to 1 and return.
 *   Else, set repr[i] to 0 if (num / round(pow(2, i))) % 2 == 0, else set to 1.
 * @param num - The number to convert to a binary representation.
 * @param repr - A pointer to the binary representation's char array.
 * @param reprLength - The representation's char array length.
 */
int bintodec (char *repr) {
  int i, result = 0; /* The decimal representation */

  for (i = 0; i < BINARY_REPR_LEN; i++) {
    result += repr[BINARY_REPR_LEN - 1 - i] == '1' ? (int) pow(2, i) : 0;
  }

  return result;
}

/*
 * Converts a binary representation of a number (repr) to its decimal representation.
 * Algorithm:
 *   bintodec(repr) = sum(0, BINARY_REPR_LEN, repr[i] == 1 ? pow(2, i) : 0)
 * @param repr - A binary representation of a given number.
 * @return The decimal representation of the given number.
 */
void dectobin (unsigned int num, char *repr, int reprLength) {
  int i, isOdd = 0; /* An indicator whether num is odd */
  double l2 = log2(num); /* Base 2 log of x */

  if (num % 2 != 0) {
    isOdd = 1;
    num--;
  }

  for (i = 0; i < reprLength; i++) {
    if (powof2(num)) {
      repr[reprLength - 1 - i] = i == (int) l2 ? '1' : '0';
    } else {
      repr[reprLength - 1 - i] = (int) (num / round(pow(2, i))) % 2 == 0 ? '0' : '1';
    }
  }

  if (isOdd) repr[reprLength - 1] = '1';
}

/*
 * Adds the two numbers a and b according to the binary addition specified in the assignment.
 * @param a - A whole number, 0 ≤ a ≤ MAX_INPUT.
 * @param b - A whole number, 0 ≤ b ≤ MAX_INPUT.
 * @return a + b, calculated according to the assignment specifications.
 */
unsigned int my_add (unsigned int a, unsigned int b) {
  char reprA[BINARY_REPR_LEN + 1] = {'\0'}; /* Representation char array of a */
  char reprB[BINARY_REPR_LEN + 1] = {'\0'}; /* Representation char array of b */
  char reprSum[BINARY_REPR_LEN + 1] = {'\0'}; /* Representation char array of the sum */

  /*
   * digA - The current digit of a
   * digB - The current digit of b
   * digSum - The digit to add to the sum
   * carrier - The addition remainder
   */
  int i, digA, digB, digSum, carrier = 0;

  dectobin(a, reprA, BINARY_REPR_LEN);
  dectobin(b, reprB, BINARY_REPR_LEN);

  printf("First number binary: %s\n", reprA);
  printf("Second number binary: %s\n", reprB);

  for (i = 0; i < BINARY_REPR_LEN; i++) {
    STORE_DIGIT(digA, reprA);
    STORE_DIGIT(digB, reprB);

    digSum = digA + digB + carrier;

    /* Set the carrier according to the sum's binary representation */
    switch (digSum) {
      case 2:
        carrier = 1;
        digSum = 0;
        break;
      case 3:
        carrier = 1;
        digSum = 1;
        break;
      default:
        carrier = 0;
        break;
    }

    reprSum[BINARY_REPR_LEN - i - 1] = digSum == 0 ? '0' : '1';
  }
  
  printf("Sum binary: %s\n", reprSum);
  return bintodec(reprSum);
}


int main () {
  /*
   * numA - The first number read from stdin
   * numB - The second number read from stdin
   * sum - A variable storing the sum of a and b
   */
  unsigned long int numA, numB, sum;

  printf("Enter first number: ");
  scanf("%lu", &numA);

  printf("Enter second number: ");
  scanf("%lu", &numB);

  if (numA > MAX_INPUT || numB > MAX_INPUT) {
    printf("Maximum input is %ld; Aborting\n", MAX_INPUT);
    return 1;
  }

  sum = my_add(numA, numB);

  printf("%lu + %lu = %lu\n", numA, numB, sum);
  return 0;
}
