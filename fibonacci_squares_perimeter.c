/*
5 kyu
Perimeter of squares in a rectangle
https://www.codewars.com/kata/559a28007caad2ac4e000083
*/

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

ull perimeter(int n) {
  ull fibn, fibnp1, sum = 0ull;
  for (ull i = 1ull; i <= ((ull)n + 1ull); i++) {
    fib((ull)i, &fibn, &fibnp1);
    sum += fibn * 4ull;
  }
  return sum;
}
