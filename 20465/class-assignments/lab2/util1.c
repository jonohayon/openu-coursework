#include "util1.h"

char upper(char c) {
  if (c >= 'a' && c <= 'z')
    return c - ('a' - 'A');
  else
    return c;
}

char lower(char c) {
  if (c >= 'A' && c <= 'Z')
    return c + ('a' - 'A');
  else
    return c;
}
