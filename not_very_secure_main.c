/*
5 kyu
Not very secure
https://www.codewars.com/kata/526dbd6c8c0eb53254000110
*/

#include <stdbool.h>
#include <stdio.h>

bool alphanumeric(const char* strin);

static void do_test(const char* str_in, bool expected) {
  bool submitted = alphanumeric(str_in);
  const char* ft[2] = {"false", "true"};
  printf("Input = %s\nSubmitted: %s\nExpected:  %s\n\n", str_in, ft[submitted],
         ft[expected]);
}

int main(void) {
  do_test("hello_world", false);
  do_test("PassW0rd", true);
  do_test("     ", false);
  do_test("a", true);
  do_test("", false);
  return 0;
}
