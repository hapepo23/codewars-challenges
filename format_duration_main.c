/*
5 kyu
Human Readable Time
https://www.codewars.com/kata/52685f7382004e774f0001f7
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* formatDuration(int n);

static void do_test(int n, const char* expected) {
  char* actual = formatDuration(n);
  printf("input was:\n\"%d\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", n, expected,
         actual);
  free(actual);
}

int main(void) {
  do_test(0, "now");
  do_test(31536000, "1 year");
  do_test(31536001, "1 year and 1 second");
  do_test(31539600, "1 year and 1 hour");
  do_test(1, "1 second");
  do_test(3600, "1 hour");
  do_test(120, "2 minutes");
  do_test(62, "1 minute and 2 seconds");
  do_test(3662, "1 hour, 1 minute and 2 seconds");
  do_test(31626061, "1 year, 1 day, 1 hour, 1 minute and 1 second");
  return 0;
}
