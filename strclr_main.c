/*
6 kyu
Backspaces in string
https://www.codewars.com/kata/5727bb0fe81185ae62000ae3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strclr(const char* s);

static void do_test(const char* s, const char* expected) {
  char* actual = strclr(s);
  printf("input was:\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", s, expected,
         actual);
  free(actual);
}

int main(void) {
  do_test("abc###cba", "cba");
  do_test("abc#d##c", "ac");
  do_test("abc####d##c#", "");
  do_test("#########", "");
  do_test("", "");
  return 0;
}
