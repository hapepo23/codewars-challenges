/*
5 kyu
Last digit of a large number
https://www.codewars.com/kata/5511b2f550906349a70004e1
*/

#include <stdio.h>

int last_digit(const char* a, const char* b);

static void do_test(const char* a, const char* b, int expected) {
  int actual = last_digit(a, b);
  printf(
      "a = %s\nb = %s\na^n actual last digit: %d\na^n expected last digit: "
      "%d\n%s\n\n",
      a, b, actual, expected, actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("4", "1", 4);
  do_test("4", "2", 6);
  do_test("9", "7", 9);
  do_test("10", "10000000000", 0);
  do_test("1606938044258990275541962092341162602522202993782792835301376",
          "20370359763344860862684456884093781610514683936659362506361404493543"
          "81299763336706183397376",
          6);
  do_test("3715290469715693021198967285016729344580685479654510946723",
          "68819615221552997273737174557165657483427362207517952651", 7);
  do_test("243", "0", 1);
  do_test("0", "94907", 0);
  return 0;
}