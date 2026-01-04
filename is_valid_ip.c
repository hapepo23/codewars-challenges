/*
6 kyu
IP Validation
https://www.codewars.com/kata/515decfd9dcfc23bb6000006
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool is_all_digits(const char* s) {
  if (*s == '\0')
    return false;
  for (; *s; ++s) {
    if (!isdigit((unsigned char)*s))
      return false;
  }
  return true;
}

static char* xstrdup(const char* s) {
  size_t len = strlen(s) + 1;
  char* p = malloc(len);
  if (p)
    memcpy(p, s, len);
  return p;
}

bool is_valid_ip(const char* addr) {
  size_t l = strlen(addr);
  if (*addr == '.')
    return false;
  if (*(addr + l - 1) == '.')
    return false;
  bool result = true;
  int v;
  int counttoken = 0;
  char* a = xstrdup(addr);
  char* token = strtok(a, ".");
  while (token) {
    l = strlen(token);
    if (l < 1 || l > 3 || (!is_all_digits(token))) {
      result = false;
      break;
    }
    if (sscanf(token, "%d", &v) != 1) {
      result = false;
      break;
    }
    if (v < 0 || v > 255 || (v < 10 && l > 1) || (v < 100 && l > 2)) {
      result = false;
      break;
    }
    counttoken++;
    token = strtok(NULL, ".");
  }
  if (counttoken != 4)
    result = false;
  free(a);
  return result;
}
