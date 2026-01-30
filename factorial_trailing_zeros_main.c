/*
5 kyu
Number of trailing zeros of N!
https://www.codewars.com/kata/52f787eb172a8b4ae1000a34
*/

#include <stdio.h>

long zeros(long n);

static void do_test(long n, long expected) {
  long actual = zeros(n);
  printf("For n = %ld\nExpected: %ld\nReceived: %ld\n%s\n\n", n, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test(0, 0);
  do_test(6, 1);
  do_test(14, 2);
  do_test(30, 7);
  do_test(1000, 249);
  do_test(100000, 24999);
  do_test(1000000000, 249999998);
  return 0;
}
