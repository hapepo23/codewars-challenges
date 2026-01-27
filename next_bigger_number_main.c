/*
4 kyu
Next bigger number with the same digits
https://www.codewars.com/kata/55983863da40caa2c900004e
*/

#include <stdio.h>

typedef long long ll;

ll next_bigger_number(ll n);

static void do_test(ll n, ll expected) {
  ll submitted = next_bigger_number(n);
  printf("Input = %lld\nSubmitted: %lld\nExpected:  %lld\n%s\n\n", n, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(12ll, 21ll);
  do_test(513ll, 531ll);
  do_test(2017ll, 2071ll);
  do_test(414ll, 441ll);
  do_test(144ll, 414ll);
  do_test(8223372036854775807ll, 8223372036854775870ll);
  do_test(9876543210ll, -1ll);
  do_test(111ll, -1ll);
  return 0;
}
