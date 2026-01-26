/*
5 kyu
Product of consecutive Fib numbers
https://www.codewars.com/kata/5541f58a944b85ce6d00006a
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

ull* productFib(ull prod);

static void do_test(ull product, const ull expected[3]) {
  static const size_t mem_size = 3 * sizeof *expected;
  ull* actual = productFib(product);
  printf(
      "for product %llu\n"
      "expected { %llu, %llu, %llu }\n"
      "but got  { %llu, %llu, %llu }\n%s\n\n",
      product, expected[0], expected[1], expected[2], actual[0], actual[1],
      actual[2], memcmp(actual, expected, mem_size) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  do_test(0, (ull[3]){0, 1, true});
  do_test(1, (ull[3]){1, 1, true});
  do_test(2, (ull[3]){1, 2, true});
  do_test(3, (ull[3]){2, 3, false});
  do_test(4, (ull[3]){2, 3, false});
  do_test(5, (ull[3]){2, 3, false});
  do_test(6, (ull[3]){2, 3, true});
  do_test(7, (ull[3]){3, 5, false});
  do_test(105, (ull[3]){13, 21, false});
  do_test(2563195080744681828ull, (ull[3]){1836311903, 2971215073, false});
  do_test(5456077604922913920ull, (ull[3]){2971215073, 4807526976, false});
  return 0;
}
