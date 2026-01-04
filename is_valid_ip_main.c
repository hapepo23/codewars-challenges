/*
6 kyu
IP Validation
https://www.codewars.com/kata/515decfd9dcfc23bb6000006
*/

#include <stdbool.h>
#include <stdio.h>

bool is_valid_ip(const char* addr);

static void do_test(const char* addr, bool expected) {
  bool actual = is_valid_ip(addr);
  printf("input was: \"%s\"\nexpected: \"%s\", got: \"%s\"\n", addr,
         expected ? "true" : "false", actual ? "true" : "false");
}

int main(void) {
  do_test("0.0.0.0", true);
  do_test("255.255.255.255", true);
  do_test("0.11.222.11", true);
  do_test("0", false);                                       // not enough bytes
  do_test("1.2.99999999999999999999999999999999.4", false);  // integer overflow
  do_test("0.0.0", false);                                   // not enough bytes
  do_test(" 1.2.3.4", false);  // leading whitespace
  do_test("1. 2.3.4", false);  // middle whitespce
  do_test("1.2.3.4 ", false);  // trailing whitspace
  do_test(" ", false);
  do_test("0.0.0.0.0", false);        // too many bytes
  do_test("1.2.03.4", false);         // leading 0
  do_test("1.2.+3.4", false);         // + sign
  do_test("256.256.256.256", false);  // byte too large
  do_test("1.2.1000.4", false);       // byte too large
  do_test("4.-5.-6.7", false);        // negative bytes
  do_test("0.0.0.0abcdefg", false);
  do_test(".1.2.3.4", false);      // leading dot
  do_test("0.11.222.11.", false);  // trailing dot
  do_test("1.2..4", false);        // empty bytes
  do_test("...", false);
  do_test("abcdefg0.0.0.0", false);
  do_test("a.b.c.d", false);  // hex digits
  return 0;
}
