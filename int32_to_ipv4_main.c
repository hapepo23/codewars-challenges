/*
5 kyu
int32 to IPv4
https://www.codewars.com/kata/52e88b39ffb6ac53a400022e
*/

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

void uint32_to_ip(uint32_t ip, char* output);

static void do_test(uint32_t number, const char* expected) {
  char actual[16] = "@@@@@@@@@@@@@@@@";
  uint32_to_ip(number, actual);
  printf("for uint32 = %" PRIu32 "\nexpected: \"%s\"\nbut got: \"%s\"\n%s\n\n",
         number, expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(1234, "0.0.4.210");
  do_test(2154959208, "128.114.17.104");
  do_test(0, "0.0.0.0");
  do_test(UINT32_MAX, "255.255.255.255");
  do_test(2149583361, "128.32.10.1");
  do_test(1804289383, "107.139.69.103");
  return 0;
}
