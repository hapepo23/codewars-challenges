/*
6 kyu
Who likes it?
https://www.codewars.com/kata/5266876b8f4bf2da9b000362
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* likes(size_t n, const char* const names[n]) {
  char* result;
  char buf[200];
  if (n == 0) {
    strncpy(buf, "no one likes this", sizeof(buf));
  } else if (n == 1) {
    snprintf(buf, sizeof(buf), "%s likes this", names[0]);
  } else if (n == 2) {
    snprintf(buf, sizeof(buf), "%s and %s like this", names[0], names[1]);
  } else if (n == 3) {
    snprintf(buf, sizeof(buf), "%s, %s and %s like this", names[0], names[1],
             names[2]);
  } else {
    snprintf(buf, sizeof(buf), "%s, %s and %ld others like this", names[0],
             names[1], n - 2);
  }
  result = calloc(strlen(buf) + 1, sizeof(char));
  strcpy(result, buf);
  return result;
}
