/*
5 kyu
String incrementer
https://www.codewars.com/kata/54a91a4883a7de5d7800009c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* incrementString(const char* str);

static void doTest(const char* str, const char* expected) {
  char* actual = incrementString(str);
  printf("Input    = \"%s\"\nExpected = \"%s\"\nReceived = \"%s\"\n%s\n\n", str,
         expected, actual, strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  doTest("foobar000", "foobar001");
  doTest("foobar999", "foobar1000");
  doTest("foobar001", "foobar002");
  doTest("foobar99", "foobar100");
  doTest("foobar099", "foobar100");
  doTest("foobar00999", "foobar01000");
  doTest("foo", "foo1");
  doTest("foobar001", "foobar002");
  doTest("foobar1", "foobar2");
  doTest("1", "2");
  doTest("009", "010");
  doTest("", "1");
  doTest("fo99obar99", "fo99obar100");
}
