/*
7 kyu
Vowel Count
https://www.codewars.com/kata/54ff3102c1bad923760001f3
*/

#include <stddef.h>

size_t get_count(const char* s) {
  const char* p = s;
  size_t c = 0;
  while (*p) {
    switch (*p) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        c++;
        break;
    }
    p++;
  }
  return c;
}