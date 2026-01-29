/*
5 kyu
Common Denominators
https://www.codewars.com/kata/54d7660d2daf68c619000d95
*/

#include <stdlib.h>

typedef long long ll;
typedef ll Fraction[2];  // { numerator, denominator }

static ll greatest_common_divisor(ll m, ll n) {
  while (m > 0) {
    ll tmp = n % m;
    n = m;
    m = tmp;
  }
  return n;
}

static ll least_common_multiple(ll m, ll n) {
  ll x = m / greatest_common_divisor(m, n);
  return n * x;
}

Fraction* convertFrac(const Fraction fractions[], unsigned n) {
  Fraction* result = calloc(n, sizeof(*fractions));
  for (unsigned i = 0; i < n; i++) {
    ll div = greatest_common_divisor(fractions[i][0], fractions[i][1]);
    result[i][0] = fractions[i][0] / div;
    result[i][1] = fractions[i][1] / div;
  }
  ll lcm = result[0][1];
  for (unsigned i = 1; i < n; i++)
    lcm = least_common_multiple(lcm, result[i][1]);
  for (unsigned i = 0; i < n; i++) {
    result[i][0] = result[i][0] * lcm / result[i][1];
    result[i][1] = lcm;
  }
  return result;
}
