/*
7 kyu
Alphabetically ordered
https://www.codewars.com/kata/5a8059b1fd577709860000f6
*/

#include <stdbool.h>

bool is_ordered(const char* string) {
  char last = 'a';
  while (*string) {
    if (*string < last)
      return false;
    last = *string;
    string++;
  }
  return true;
}
