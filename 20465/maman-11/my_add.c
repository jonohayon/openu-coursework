#include "my_add.h"

double log2 (double x) {
  return log(x) / LOG_2;
}

int powof2 (double x) {
  double l2 = log2(x); /* Base 2 log of x */
  return (int) round((ceil(l2) - l2) * POW2_ACCUR) == 0;
}

int bintodec (char *repr) {
  int i, result = 0; /* The decimal representation */

  for (i = 0; i < BINARY_REPR_LEN; i++) {
    result += repr[BINARY_REPR_LEN - 1 - i] == '1' ? (int) pow(2, i) : 0;
  }

  return result;
}

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

  for (i = 0; i < BINARY_REPR_LEN; i++) {
    STORE_DIGIT(digA, reprA);
    STORE_DIGIT(digB, reprB);

    digSum = digA + digB + carrier;

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

  printf("Sum: %lu\n", sum);
  return 0;
}
