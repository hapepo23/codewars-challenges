/*
6 kyu
Backspaces in string
https://www.codewars.com/kata/5727bb0fe81185ae62000ae3
*/

#include <stdlib.h>
#include <string.h>

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

char* strclr(const char* s) {
  char* result = xstrdup(s);
  char* p = result;
  char* d = result;
  while (*p) {
    if (*p == '#') {
      if (d > result) {
        d--;
      }
    } else {
      *d = *p;
      d++;
    }
    p++;
  }
  *d = '\0';
  return result;
}
