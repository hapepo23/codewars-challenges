/*
4 kyu
Square into Squares. Protect trees!
https://www.codewars.com/kata/54eb33e5bc1a25440d000891
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10000

typedef long long ll;

ll sol[MAXN];
int sol_len = 0;

bool search(ll remaining, ll max_base) {
  if (remaining == 0)
    return true;
  for (ll k = max_base; k >= 1; k--) {
    ll sq = k * k;
    if (sq > remaining)
      continue;
    sol[sol_len++] = k;
    if (search(remaining - sq, k - 1))
      return true;
    sol_len--;
  }
  return false;
}

char* decompose(ll n) {
  ll target = n * n;
  sol_len = 0;
  char* result;
  if (!search(target, n - 1)) {
    result = calloc(3, sizeof(char));
    strcpy(result, "[]");
  } else {
    result = calloc(sol_len * 20, sizeof(char));
    result[0] = '[';
    for (ll i = sol_len - 1; i >= 0; i--) {
      char buf[20];
      sprintf(buf, "%lld,", sol[i]);
      strcat(result, buf);
    }
    result[strlen(result) - 1] = ']';
  }
  return result;
}
