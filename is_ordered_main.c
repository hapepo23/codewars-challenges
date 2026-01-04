/*
7 kyu
Alphabetically ordered
https://www.codewars.com/kata/5a8059b1fd577709860000f6
*/

#include <stdbool.h>
#include <stdio.h>

bool is_ordered(const char* string);

static void do_test(const char* string, bool expected) {
  bool actual = is_ordered(string);
  printf("input was:\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", string,
         expected ? "true" : "false", actual ? "true" : "false");
}

int main(void) {
  do_test("", true);
  do_test("a", true);
  do_test("aaaaa", true);
  do_test("ba", false);
  do_test("ab", true);
  do_test("kata", false);
  do_test("ant", true);
  return 0;
}
