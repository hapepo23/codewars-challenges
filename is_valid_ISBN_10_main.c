/*
5 kyu
ISBN-10 Validation
https://www.codewars.com/kata/51fc12de24a9d8cb0e000001
*/

#include <stdbool.h>
#include <stdio.h>

bool is_valid_ISBN_10(const char* ISBN);

static void do_test(const char* ISBN, bool expected) {
  bool actual = is_valid_ISBN_10(ISBN);
  printf("input was: \"%s\"\nexpected: \"%s\", got: \"%s\"\n", ISBN,
         expected ? "true" : "false", actual ? "true" : "false");
}

int main(void) {
  do_test("1112223339", true);
  do_test("048665088X", true);
  do_test("1293000000", true);
  do_test("1234554321", true);
  do_test("1234512345", false);
  do_test("1293", false);
  do_test("X123456788", false);
  do_test("ABCDEFGHIJ", false);
  do_test("XXXXXXXXXX", false);
  do_test("048665088XZ", false);
  return 0;
}
