/*
4 kyu
Counting Change Combinations
https://www.codewars.com/kata/541af676b589989aed0009e7
*/

#include <stdio.h>

int count_change(int money, int length, const int coins[length]);

static void do_test(int money,
                    int length,
                    const int coins[length],
                    int expected) {
  int actual = count_change(money, length, coins);
  printf("Money was: %d, expected count: %d, actual: %d\n%s\n\n", money,
         expected, actual, expected == actual ? "OK" : "ERROR");
}

int main(void) {
  int coins1[] = {1, 2};
  do_test(4, 2, coins1, 3);
  int coins2[] = {5, 2, 3};
  do_test(10, 3, coins2, 4);
  int coins3[] = {5, 7};
  do_test(11, 2, coins3, 0);
  int coins4[] = {3, 14, 8};
  do_test(98, 3, coins4, 19);
  int coins5[] = {3, 5, 9, 15};
  do_test(199, 4, coins5, 760);
  int coins6[] = {5, 10, 20, 50, 100, 200, 500};
  do_test(300, 7, coins6, 1022);
  int coins7[] = {5, 10, 20, 50, 100, 200, 500};
  do_test(301, 7, coins7, 0);
  int coins8[] = {2, 5, 10, 20, 50};
  do_test(419, 5, coins8, 18515);
  return 0;
}
