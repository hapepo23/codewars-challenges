/*
7 kyu
Anagram Detection
https://www.codewars.com/kata/529eef7a9194e0cbc1000255
*/

#include <stdbool.h>
#include <stdio.h>

bool is_anagram(const char* s1, const char* s2);

static void do_test(const char* s1, const char* s2, bool expected) {
  bool actual = is_anagram(s1, s2);
  printf("input was:\n\"%s\"\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", s1,
         s2, expected ? "true" : "false", actual ? "true" : "false");
}

int main(void) {
  do_test("abab", "cdcd", false);
  do_test("ac", "bb", false);
  do_test("aab", "abb", false);
  do_test("Creative", "Reactive", true);
  do_test("foefet", "toffee", true);
  do_test("Buckethead", "DeathCubeK", true);
  do_test("Twoo", "WooT", true);
  do_test("dumble", "bumble", false);
  do_test("ound", "round", false);
  do_test("apple", "pale", false);
  return 0;
}
