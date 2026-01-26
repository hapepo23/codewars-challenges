/*
5 kyu
Factorial decomposition
https://www.codewars.com/kata/5a045fee46d843effa000070
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXF 4000
#define ERRMSG "n > 4000"

static int fac[MAXF + 1];

static void factors(int num) {
  int div = 2;
  int divmax = (int)sqrt(num);
  while (div <= divmax) {
    if (num % div == 0) {
      fac[div]++;
      num /= div;
      divmax = (int)sqrt(num);
    } else
      div++;
  }
  fac[num]++;
}

char* decomp(int n) {
  if (n > MAXF) {
    char* result = calloc(strlen(ERRMSG) + 1, sizeof(char));
    strcpy(result, ERRMSG);
    return result;
  }
  for (int i = 0; i <= MAXF; i++) {
    fac[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    factors(i);
  }
  int count = 0;
  for (int i = 0; i <= MAXF; i++)
    count++;
  char* result = calloc(10 * count, sizeof(char));
  for (int i = 0; i <= MAXF; i++) {
    char buf[11];
    if (fac[i] > 0) {
      if (fac[i] == 1)
        sprintf(buf, "%d * ", i);
      else
        sprintf(buf, "%d^%d * ", i, fac[i]);
      strcat(result, buf);
    }
  }
  result[strlen(result) - 3] = '\0';
  return result;
}
