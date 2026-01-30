/*
5 kyu
Merged String Checker
https://www.codewars.com/kata/54c9fcad28ec4c6e680011aa
*/

#include <stdbool.h>
#include <stdio.h>

bool is_merge(const char* s, const char* part1, const char* part2);

static void do_test(const char* s,
                    const char* part1,
                    const char* part2,
                    bool expected) {
  bool actual = is_merge(s, part1, part2);
  printf(
      "Expected %s for s = \"%s\"\npart1 = \"%s\"\npart2 = \"%s\"\nActual: %s "
      "-> %s\n\n",
      expected ? "TRUE" : "FALSE", s, part1, part2, actual ? "TRUE" : "FALSE",
      actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test("codewars", "code", "wars", true);
  do_test("codewars", "wars", "code", true);
  do_test("codewars", "codew", "wars", false);
  do_test("codewars", "code", "warss", false);
  do_test("codewars", "code", "code", false);
  do_test("codewars", "codewars", "", true);
  do_test("codewars", "", "codewars", true);
  do_test("codewars", "oea", "cdwrs", true);
  do_test("acab", "ab", "ac", true);
  do_test("acab", "ac", "ab", true);
  do_test("acab", "aa", "cb", true);
  do_test("acab", "cb", "aa", true);
  do_test("acab", "ca", "ba", false);
  do_test("acab", "bc", "aa", false);
  do_test("acab", "cb", "aaa", false);
  do_test("", "", "", true);
  do_test(
      "At a job interview you are challenged to write an algorithm to check if "
      "a given string can be formed from two other strings",
      "Aaoieieouaeaeeoieaaoioeiaieiaeoeoooei",
      "t  jb ntrvw y r chllngd t wrt n lgrthm t chck f  gvn strng cn b frmd "
      "frm tw thr strngs",
      true);
  return 0;
}
