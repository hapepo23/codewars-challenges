/*
5 kyu
Primes in numbers
https://www.codewars.com/kata/54d512e62a5e54c96200019e
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* factors(int n);

static void do_test(int n, const char* expected) {
  char* actual = factors(n);
  printf("for n = %d\nexpected: \"%s\"\nbut got:  \"%s\"\n%s\n\n", n, expected,
         actual, strcmp(expected, actual) == 0 ? "OK" : "ERROR");
  free(actual);
}

int main(void) {
  do_test(2, "(2)");
  do_test(1 << 30, "(2**30)");
  do_test(2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23,
          "(2)(3)(5)(7)(11)(13)(17)(19)(23)");
  do_test(7775460, "(2**2)(3**3)(5)(7)(11**2)(17)");
  do_test(7919, "(7919)");
  do_test(17 * 17 * 93 * 677, "(3)(17**2)(31)(677)");
  do_test(933555431, "(7537)(123863)");
  do_test(342217392, "(2**4)(3)(11)(43)(15073)");
  do_test(35791357, "(7)(5113051)");
  do_test(782611830, "(2)(3**2)(5)(7**2)(11)(13)(17)(73)");
  do_test(775878912, "(2**8)(3**4)(17)(31)(71)");
  do_test(483499306, "(2)(41**2)(143813)");
  return 0;
}
