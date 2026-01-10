/*
4 kyu
Multiplying numbers as strings
https://www.codewars.com/kata/55911ef14065454c75000062
*/

#include <stdlib.h>
#include <string.h>

static void multiply_single_char(char a, char b, char oco, char* r, char* co) {
  int product = ((int)(a - '0') * (int)(b - '0')) + (int)(oco - '0');
  *co = (char)(product / 10 + '0');
  *r = (char)(product % 10 + '0');
}

static void add_single_char(char a, char b, char oco, char* r, char* co) {
  int sum = (int)(a - '0') + (int)(b - '0') + (int)(oco - '0');
  *co = (char)(sum / 10 + '0');
  *r = (char)(sum % 10 + '0');
}

char* multiply(const char* a, const char* b) {
  int la = strlen(a), lb = strlen(b);
  int l = la + lb, ltemp = la + 1;
  char* result = calloc(l + 1, sizeof(char));
  for (int i = 0; i < l; i++)
    result[i] = '0';
  char* temp = calloc(ltemp + 1, sizeof(char));
  for (int j = lb - 1, pos = 0; j >= 0; j--, pos++) {
    temp[ltemp - 1] = '0';
    for (int i = la - 1, k = ltemp - 1; i >= 0; i--, k--) {
      multiply_single_char(a[i], b[j], temp[k], &temp[k], &temp[k - 1]);
    }
    char co = '0';
    for (int k = ltemp - 1, m = l - 1; k >= 0; k--, m--) {
      add_single_char(result[m - pos], temp[k], co, &result[m - pos], &co);
    }
  }
  free(temp);
  char* pr = result;
  while (*pr == '0' && pr < result + l - 1)
    pr++;
  if (result < pr)
    memmove(result, pr, strlen(pr) + 1);
  return result;
}
