/*
7 kyu
Vowel Count
https://www.codewars.com/kata/54ff3102c1bad923760001f3
*/

#include <stddef.h>
#include <stdio.h>

size_t get_count(const char* s);

static void do_test(const char* str, const size_t expected) {
  size_t actual = get_count(str);
  printf("input was:\n\"%s\"\nexpected:\n\"%ld\"\ngot:\n\"%ld\"\n\n", str,
         expected, actual);
}

int main(void) {
  do_test("abracadabra", 5);
  do_test("", 0);
  return 0;
}
