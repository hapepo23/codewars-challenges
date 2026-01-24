/*
4 kyu
Rectangle Rotation
https://www.codewars.com/kata/5886e082a836a691340000c3
*/

#include <stdio.h>

typedef long long ll;

ll rectangle_rotation(int a, int b);

static void do_test(int a, int b, ll expected) {
  ll actual = rectangle_rotation(a, b);
  printf(
      "a x b   : %d x %d\n"
      "Expected: %lld\n"
      "Actual  : %lld\n%s\n\n",
      a, b, expected, actual, expected == actual ? "OK" : "ERROR");
}

int main(void) {
  do_test(6, 4, 23);
  do_test(30, 2, 65);
  do_test(8, 6, 49);
  do_test(16, 20, 333);
  return 0;
}
