/*
5 kyu
Not very secure
https://www.codewars.com/kata/526dbd6c8c0eb53254000110
*/

#include <ctype.h>
#include <stdbool.h>

bool alphanumeric(const char* str_in) {
  const char* p = str_in;
  if (!*p)
    return false;
  while (*p) {
    if (!isalnum(*p))
      return false;
    p++;
  }
  return true;
}
