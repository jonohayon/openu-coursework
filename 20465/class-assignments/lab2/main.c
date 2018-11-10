#include <stdio.h>
#include "util1.h"
#include "util2.h"
#define SIZE 25

int main(void) {
  char arr[SIZE];
  char c;
  scanf("%c %s",&c, arr);
  to_upper_array(arr,SIZE);
  c = upper(c);
  printf("Result is: %c %s\n", c, arr);
  return 0;
}
