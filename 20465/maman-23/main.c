#include <stdio.h>

#define REPR_LENGTH 4

void xorOp (char A[], char B[], char result[]) {
  int i;
  for (i = 0; i < REPR_LENGTH; i++) {
    result[i] = A[i] == B[i] ? '0' : '1';
  }
}

void swap (int *A, int *B) {
  *A ^= *B;
  *B ^= *A;
  *A ^= *B;
}

int main (void) {
  int A = 5, B = 6;
  char a[] = {'1', '0', '0', '1', '\0'},
       b[] = {'1', '1', '0', '0', '\0'};

  swap(&A, &B);
  printf("%d, %d\n", A, B);

  xorOp(a, b, a);
  xorOp(b, a, b);
  xorOp(a, b, a);
  printf("%s, %s\n", a, b);
  return 0;
}
