/*
5 kyu
Count IP Addresses
https://www.codewars.com/kata/526989a41034285187000de4
*/

#include <inttypes.h>
#include <stdio.h>

uint32_t ips_between(const char* start, const char* end);

static void do_test(const char* start, const char* end, uint32_t expected) {
  uint32_t actual = ips_between(start, end);
  printf("for (start = %s ~ end = %s)\nexpected %" PRIu32 " but got %" PRIu32
         "\n%s\n\n",
         start, end, expected, actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  do_test("10.0.0.0", "10.0.0.50", 50);
  do_test("20.0.0.10", "20.0.1.0", 246);
  do_test("0.0.0.0", "255.255.255.255", UINT32_MAX);
}
