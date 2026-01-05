/*
6 kyu
Roman Numerals Encoder
https://www.codewars.com/kata/51b62bf6a9c58071c600001b
*/

#include <stdio.h>
#include <stdlib.h>

char* solution(int n);

static void do_test(int n, const char* expected) {
  char* actual = solution(n);
  printf("input was:\n\"%d\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", n, expected,
         actual);
  free(actual);
}

int main(void) {
  do_test(1, "I");
  do_test(4, "IV");
  do_test(1000, "M");
  do_test(1990, "MCMXC");
  do_test(2007, "MMVII");
  do_test(2, "II");
  do_test(3, "III");
  do_test(5, "V");
  do_test(9, "IX");
  do_test(10, "X");
  do_test(11, "XI");
  do_test(15, "XV");
  do_test(19, "XIX");
  do_test(22, "XXII");
  do_test(1001, "MI");
  do_test(2008, "MMVIII");
  do_test(3999, "MMMCMXCIX");
  return 0;
}
