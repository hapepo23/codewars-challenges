/*
8 kyu
Do I get a bonus?
https://www.codewars.com/kata/56f6ad906b88de513f000d96
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

char* bonus_time(ull salary, bool bonus);

static void do_test(ull salary, bool bonus, const char* expected) {
  char* actual = bonus_time(salary, bonus);
  printf(
      "salary = %llu, bonus = %s\n"
      "Expected: \"%s\"\nActual  : \"%s\"\n\n",
      salary, bonus ? "true" : "false", expected, actual);
  free(actual);
}

int main(void) {
  do_test(10000, true, "$100000");
  do_test(25000, true, "$250000");
  do_test(10000, false, "$10000");
  do_test(60000, false, "$60000");
  do_test(2, true, "$20");
  do_test(78, false, "$78");
  do_test(67890, true, "$678900");
  return 0;
}
