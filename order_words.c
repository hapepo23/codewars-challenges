/*
6 kyu
Your order, please
https://www.codewars.com/kata/55c45be3b2079eccff00010f
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

char* order_words(char* ordered, const char* words) {
  *ordered = '\0';
  if (strlen(words) > 0) {
    char* ww[10] = {NULL};
    char* w = xstrdup(words);
    char* p = strtok(w, " ");
    while (p) {
      char* posnum = strpbrk(p, "123456789");
      ww[*posnum - '1'] = p;
      p = strtok(NULL, " ");
    }
    for (int i = 0; i < 9; i++) {
      if (ww[i])
        strcat(ordered, ww[i]);
      if (ww[i + 1])
        strcat(ordered, " ");
    }
    free(w);
  }
  return ordered;
}
