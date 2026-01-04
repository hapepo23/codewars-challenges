/*
7 kyu
Consecutive Vowels in a String
https://www.codewars.com/kata/62a933d6d6deb7001093de16
*/

#include <stdio.h>

int get_the_vowels(const char* string);

static void do_test(const char* string, int expected) {
  int actual = get_the_vowels(string);
  printf("input was:\n\"%s\"\nexpected:\n\"%d\"\ngot:\n\"%d\"\n\n", string,
         expected, actual);
}

int main(void) {
  do_test("agrtertyfikfmroyrntbvsukldkfa", 6);
  do_test("", 0);
  do_test("uoiea", 1);
  do_test("aeiouaeiou", 10);
  do_test("erfaiekjudhyfimngukduo", 4);
  do_test("akfheujfkgiaaaofmmfkdfuaiiie", 7);
  return 0;
}
