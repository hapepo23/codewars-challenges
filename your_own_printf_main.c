/*
5 kyu
Write your own printf
https://www.codewars.com/kata/59480c92e3102df28f0000dd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define do_test(expected, format, ...)                 \
  do {                                                 \
    char* actual = mr_asprintf(format, ##__VA_ARGS__); \
    test_mr_asprintf(actual, expected, format);        \
    free(actual);                                      \
  } while (0)

char* mr_asprintf(const char* format, ...);

void test_mr_asprintf(char* actual, const char* expected, const char* format) {
  printf(
      "Format  : %s\n"
      "Actual  : %s\n"
      "Expected: %s\n%s\n\n",
      format, actual, expected, strcmp(actual, expected) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test("{Test}", "{{Test}");
  do_test("Gaius Julius Caesar Augustus Germanicus",
          "Gaius Julius Caesar Augustus Germanicus");
  do_test("Nickname: Caligula", "Nickname: {s}", "Caligula");
  do_test("Reign: 37 AD - 41 AD", "Reign: {i} AD - {i} AD", 37, 41);
  do_test("born: August 31, 12 in Antium", "born: {s} {i}, {i} in {s}",
          "August", 31, 12, "Antium");
  do_test("Roman emperor #3", "Roman emperor #{i}", 3);
  do_test("3 - 45 = -42", "{i} - {i} = {i}", 3, 45, 3 - 45);
  do_test("", "{s}", "");
  do_test("That's not a valid format spec: {d}",
          "That's not a valid format spec: {d}");
  return 0;
}
