/*
4 kyu
Large Factorials
https://www.codewars.com/kata/557f6437bf8dcdd135000010
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* factorial(int n);

static void do_test(int n, const char* expected) {
  char* actual = factorial(n);
  printf(
      "n = %d\n"
      "n! expected  : %s\n"
      "n! calculated: %s\n"
      "%s\n\n",
      n, expected, actual, strcmp(expected, actual) == 0 ? "OK" : "ERROR");
  free(actual);
}

int main(void) {
  do_test(-1, "");
  do_test(0, "1");
  do_test(1, "1");
  do_test(5, "120");
  do_test(9, "362880");
  do_test(15, "1307674368000");
  do_test(
      53,
      "4274883284060025564298013753389399649690343788366813724672000000000000");
  return 0;
}
