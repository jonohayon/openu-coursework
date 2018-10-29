#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 80

/**
 * Checks whether a string s is a palindrome.
 */
int palindrome (char s[]) {
  int len = strlen(s);
  int i = 0;
  int j = len - 1;

  while (i < j) {
    if (isspace(s[i])) {
      i++;
    } else if (isspace(s[j])) {
      j--;
    } else if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      return 0;
    }
  }

  return 1;
}

int main () {
  char str[MAX_STR_LEN];
  scanf("%[^\n]", str);

  printf("PALINDROME CHECKER\n------------------\n");
  printf("The word you entered, %s, is%s a palindrome.\n", str, palindrome(str) ? "" : "n\'t");
  return 0;
}
