/*
4 kyu
Square into Squares. Protect trees!
https://www.codewars.com/kata/54eb33e5bc1a25440d000891
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

char* decompose(ll n);

static void do_test(ll n, const char* reference) {
  char* actual = decompose(n);
  printf("for n = %lld:\nexpected: \"%s\",\nbut got : \"%s\"\n%s\n\n", n,
         reference, actual, strcmp(reference, actual) == 0 ? "OK" : "ERROR");
  free(actual);
}

int main(void) {
  do_test(123456789, "[1,2,5,7,123,15713,123456788]");
  do_test(338350, "[1,2,7,31,822,338349]");
  do_test(50, "[1,3,5,8,49]");
  do_test(44, "[2,3,5,7,43]");
  do_test(625, "[2,5,8,34,624]");
  do_test(2, "[]");
  return 0;
}
