/*
7 kyu
Anagram Detection
https://www.codewars.com/kata/529eef7a9194e0cbc1000255
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

bool is_anagram(const char* s1, const char* s2) {
  char* p = NULL;
  bool result = true;
  char cmp[2] = {' ', '\0'};
  char* p2 = NULL;
  if (strlen(s1) != strlen(s2))
    return false;
  char* s1a = xstrdup(s1);
  for (p = s1a; *p; ++p)
    *p = tolower(*p);
  char* s2a = xstrdup(s2);
  for (p = s2a; *p; ++p) {
    cmp[0] = tolower(*p);
    p2 = strpbrk(s1a, cmp);
    if (p2 == NULL) {
      result = false;
      break;
    } else {
      *p2 = '#';
    }
  }
  free(s1a);
  free(s2a);
  return result;
}
