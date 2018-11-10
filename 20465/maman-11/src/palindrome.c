#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 80

/**
 * Checked whether a given string is a palindrome, i.e. s = reverse(s), without respect to spaces.
 * The algorithm iterates over the string, checking the leftmost character against the rightmost character,
 * and skips all of the spaces, tabs, newlines and carrige returns (using the isspace function from ctype.h).
 * @param s The given string to check the "palindromity" of
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
