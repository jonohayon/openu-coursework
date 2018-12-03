#include <stdio.h>

#define SET_LENGTH 64 /* Defines the max length of the set */

/**
 * get_set - Scans for a user input using `scanf` and inserts it into a given array.
 *           The set is implemented using a fixed size array with a size of SET_LENGTH. This is done because since
 *           the array size is fixed, the search complexity is O(1) which is very good, and therefore using a different
 *           data structure would be insufficient. Indeed, a different data structure maybe would take less memory (i.e.
 *           a dynamically allocated array), but in this case it isn't necessary in my opinion.
 * \param destArr The destination array which will hold the set's contents.
 */
void get_set (int destArr[]) {
  int num, j, i = 0, isIn = 0; /* Variable declaration */
  printf("Input: ");

  while (scanf("%d", &num) != EOF && i < SET_LENGTH) { /* Execute the loop when the scanned character isn't EOF and the set isn't full */
    printf("%d ", num);
    isIn = 0;
    
    for (j = 0; j < SET_LENGTH; j++) { /* Check whether the number is already in the set */
      if (destArr[j] == num) {
        isIn = 1;
        break;
      }
    }

    if (!isIn) { /* Inserts the number into the set */
      destArr[i] = num;
      i++;
    }
  }

  printf("\n");
}

/**
 * print_set - Prints a given set to stdout.
 */
void print_set (int *arr) {
  int i; /* Variable declaration */
  printf("Set items: ");

  for (i = 0; i < SET_LENGTH; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int main (void) {
  int numbers[SET_LENGTH * sizeof(int)] = {'\0'};

  get_set(numbers);

  print_set(numbers);

  return 0;
}
