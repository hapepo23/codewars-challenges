/*
5 kyu
Product of consecutive Fib numbers
https://www.codewars.com/kata/5541f58a944b85ce6d00006a
*/

#include <stdbool.h>
#include <stdlib.h>

typedef unsigned long long ull;

static void fib(ull n, ull* fibn, ull* fibnp1) {
  // calculates Fib(n) and Fib(n+1)
  // Fast doubling Fibonacci algorithm, see
  // https://www.nayuki.io/page/fast-fibonacci-algorithms
  if (n == 0ull) {
    *fibn = 0ull;
    *fibnp1 = 1ull;
  } else {
    ull a, b;
    fib(n / 2ull, &a, &b);
    ull c = a * (b * 2ull - a);
    ull d = a * a + b * b;
    if (n % 2ull == 0ull) {
      *fibn = c;
      *fibnp1 = d;
    } else {
      *fibn = d;
      *fibnp1 = c + d;
    }
  }
}

ull* productFib(ull prod) {
  bool notfin = true;
  ull fibn, fibp1, p;
  for (ull i = 0ull; notfin; i++) {
    fib(i, &fibn, &fibp1);
    p = fibn * fibp1;
    notfin = (p < prod);
  }
  ull* result = calloc(3, sizeof(ull));
  result[0] = fibn;
  result[1] = fibp1;
  result[2] = (p == prod);
  return result;
}
