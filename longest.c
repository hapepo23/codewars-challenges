/*
7 kyu
Two to One
https://www.codewars.com/kata/5656b6906de340bd1b0000ac
*/

#include <stdlib.h>

char* longest(const char* s1, const char* s2) {
  unsigned int count[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  unsigned int i, pos = 0;
  while (*s1) {
    count[*s1 - 'a']++;
    s1++;
  }
  while (*s2) {
    count[*s2 - 'a']++;
    s2++;
  }
  char* result = calloc(27, sizeof(char));
  for (i = 0; i < 26; i++) {
    if (count[i])
      result[pos++] = (char)('a' + i);
  }
  return result;
}
