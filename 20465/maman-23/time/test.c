#include <stdio.h>
#include "time.h"

int main(void) {
  time date1 = {2018, DEC, 31, 23, 59, 58};
  time date2 = {2019, JAN, 1, 0, 0, 0};
  int diff1 = time_diff(date1, date2);

  time d1 = {-1, JAN, 1, 23, 59, 59};
  time d2 = {0, JAN, 1, 23, 59, 59};
  int diff2 = time_diff(d1, d2);

  printf("Expected value: %d, Actual value: %d\n", 2, diff1);
  printf("Expected value: %d, Actual value: %d\n", SECS_IN_YEAR, diff2);

  return 0;
}
