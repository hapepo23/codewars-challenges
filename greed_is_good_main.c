/*
5 kyu
Greed is Good
https://www.codewars.com/kata/5270d0d18625160ada0000e4
*/

#include <stdio.h>

int score(const int dice[5]);

static void do_test(const int dice[5], int expected) {
  int actual = score(dice);
  printf("input was: {%d %d %d %d %d}\nexpected: %d, got: %d\n%s\n\n", dice[0],
         dice[1], dice[2], dice[3], dice[4], expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  {
    const int dice[5] = {2, 3, 4, 6, 2};
    do_test(dice, 0);
  }
  {
    const int dice[5] = {4, 4, 4, 3, 3};
    do_test(dice, 400);
  }
  {
    const int dice[5] = {2, 4, 4, 5, 4};
    do_test(dice, 450);
  }
  {
    const int dice[5] = {5, 1, 3, 4, 1};
    do_test(dice, 250);
  }
  {
    const int dice[5] = {1, 1, 1, 3, 1};
    do_test(dice, 1100);
  }
  return 0;
}
