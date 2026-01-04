/*
7 kyu
Count of codepoints in a UTF-8 string
https://www.codewars.com/kata/68b8e7f8ce76e77dcfb77e8a
*/

#include <stddef.h>
#include <stdio.h>

size_t count_codepoints(const char* utf8);

static void do_test(const char* utf8, size_t expected) {
  size_t actual = count_codepoints(utf8);
  printf("input was:\n\"%s\"\nexpected:\n\"%ld\"\ngot:\n\"%ld\"\n\n", utf8,
         expected, actual);
}

int main(void) {
  do_test(u8"", 0);
  do_test(u8"Aÿ♠🙉", 4);
  do_test(u8"é", 1);  // (actual é character)
  do_test(u8"é", 2);  // (e + combining acute accent)
  do_test(u8"㐷©∏!重", 5);
  return 0;
}
