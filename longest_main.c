/*
7 kyu
Two to One
https://www.codewars.com/kata/5656b6906de340bd1b0000ac
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* longest(const char* s1, const char* s2);

static void do_test(const char* s1, const char* s2, const char* expected) {
  char* actual = longest(s1, s2);
  printf("input was:\n\"%s\"\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", s1,
         s2, expected, actual);
  free(actual);
}

int main(void) {
  do_test("aretheyhere", "yestheyarehere", "aehrsty");
  do_test("loopingisfunbutdangerous", "lessdangerousthancoding",
          "abcdefghilnoprstu");
  do_test("inmanylanguages", "theresapairoffunctions", "acefghilmnoprstuy");
  do_test("lordsofthefallen", "gamekult", "adefghklmnorstu");
  do_test("codewars", "codewars", "acdeorsw");
  do_test("agenerationmustconfrontthelooming", "codewarrs",
          "acdefghilmnorstuw");
  return 0;
}
