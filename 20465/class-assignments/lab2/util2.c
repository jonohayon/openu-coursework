#include "util1.h"
#include "util2.h"

void to_upper_array(char arr[], int size) {
  int i;
  for(i=0; i<size; i++) {
      arr[i] = upper(arr[i]);
  }  
}

void to_lower_array(char arr[], int size) {
  int i;
  for(i=0; i<size; i++) {  
    arr[i] = lower(arr[i]);
  }
}
