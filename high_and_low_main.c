/*
7 kyu
Highest and Lowest
https://www.codewars.com/kata/554b4ac871d6813a03000035
*/

#include <stdio.h>

void high_and_low(const char* strnum, char* result);

static void do_test(const char* strnum, const char* expected) {
  char actual[128];
  high_and_low(strnum, actual);
  printf("input was:\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", strnum,
         expected, actual);
}

int main(void) {
  do_test("8 3 -5 42 -1 0 0 -9 4 7 4 -4", "42 -9");
  do_test("1 2 3", "3 1");
  do_test("42", "42 42");
  return 0;
}
