/*
5 kyu
RGB To Hex Conversion
https://www.codewars.com/kata/513e08acc600c94f01000001
*/

#include <stdio.h>
#include <string.h>

void rgb(int r, int g, int b, char hex[6 + 1]);

static void do_test(int r, int g, int b, const char expected[6 + 1]) {
  char actual[6 + 1] = "@@@@@@@";
  rgb(r, g, b, actual);
  printf(
      "r = %d, g = %d, b = %d\nexpected \"%s\","
      " but got \"%s\"\n%s\n\n",
      r, g, b, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "ERROR");
}

int main(void) {
  do_test(0, 0, 0, "000000");
  do_test(1, 2, 3, "010203");
  do_test(255, 255, 255, "FFFFFF");
  do_test(254, 253, 252, "FEFDFC");
  do_test(-20, 275, 125, "00FF7D");
  return 0;
}
