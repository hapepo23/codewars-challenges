/*
5 kyu
Primes in numbers
https://www.codewars.com/kata/54d512e62a5e54c96200019e
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXF 30

int fac[MAXF][2];
int nfac = 0;

static void addfac(int n) {
  if (nfac == 0 || (nfac > 0 && n != fac[nfac - 1][0])) {
    fac[nfac][0] = n;
    fac[nfac][1] = 1;
    nfac++;
  } else
    fac[nfac - 1][1]++;
}

char* factors(int n) {
  char* result;
  char buffer[25];
  nfac = 0;
  int num = n;
  int div = 2;
  int divmax = (int)sqrt(num);
  while (div <= divmax) {
    if (num % div == 0) {
      addfac(div);
      num /= div;
      divmax = (int)sqrt(num);
    } else
      div++;
  }
  addfac(num);
  result = calloc(nfac * 25, sizeof(char));
  for (int i = 0; i < nfac; i++) {
    if (fac[i][1] == 1)
      sprintf(buffer, "(%d)", fac[i][0]);
    else
      sprintf(buffer, "(%d**%d)", fac[i][0], fac[i][1]);
    strcat(result, buffer);
  }
  return result;
}
