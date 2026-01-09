/*
7 kyu
Deodorant Evaporator
https://www.codewars.com/kata/5506b230a11c0aeab3000c1f
*/

#include <stdio.h>

int evaporator(double content, double evap_per_day, double threshold);

static void doTest(double content,
                   double evap_per_day,
                   double threshold,
                   int expected) {
  int actual = evaporator(content, evap_per_day, threshold);
  printf(
      "evap_per_day = %.17g\n"
      "threshold    = %.17g\n"
      "expected %d, got %d\n----\n",
      evap_per_day, threshold, expected, actual);
}

int main(void) {
  doTest(10, 10, 10, 22);
  doTest(10, 10, 5, 29);
  doTest(100, 5, 5, 59);
  doTest(50, 12, 1, 37);
  doTest(47.5, 8, 8, 31);
  doTest(100, 1, 1, 459);
  doTest(10, 1, 1, 459);
  doTest(100, 1, 5, 299);
  return 0;
}
