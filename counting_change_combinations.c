/*
4 kyu
Counting Change Combinations
https://www.codewars.com/kata/541af676b589989aed0009e7
*/

#include <string.h>

#define MAX_AMOUNT 1000
#define MAX_COINS 100

int memo[MAX_AMOUNT + 1][MAX_COINS];

int countWays(int amount, int n, const int coins[n], int index) {
  if (amount == 0)
    return 1;
  if (amount < 0 || index == n)
    return 0;
  if (memo[amount][index] != -1)
    return memo[amount][index];
  int useCoin = countWays(amount - coins[index], n, coins, index);
  int skipCoin = countWays(amount, n, coins, index + 1);
  memo[amount][index] = useCoin + skipCoin;
  return memo[amount][index];
}

int count_change(int money, int n_coins, const int coins[n_coins]) {
  memset(memo, -1, sizeof(memo));
  return countWays(money, n_coins, coins, 0);
}
