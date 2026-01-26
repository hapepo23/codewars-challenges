/*
5 kyu
Strings: implement your own "strtok" function!
https://www.codewars.com/kata/5806203dc2799821cb000293
*/

#include <string.h>

char* my_strtok(char* src, const char* delims) {
  static char* p;
  static char* pend;
  if (src != NULL) {
    p = src;
    pend = NULL;
  }
  if (pend != NULL)
    return NULL;
  while (*p) {
    if (strchr(delims, *p) == NULL)  // next non-delim
      break;
    p++;
  }
  char* result = p;
  if (*result) {
    while (1) {
      if (*p == '\0') {  // end
        pend = p;
        break;
      }
      if (strchr(delims, *p) != NULL)  // next delim
        break;
      p++;
    }
    *p = '\0';
    p++;
  } else
    result = NULL;
  return result;
}
