/*
5 kyu
Blackjack Scorer
https://www.codewars.com/kata/534ffb35edb1241eda0015fe
*/

#include <ctype.h>
#include <stddef.h>

int score_hand(size_t n, const char cards[n]) {
  int result = 0;
  int containsA = 0;
  for (size_t i = 0; i < n; i++) {
    if (isdigit(cards[i]))
      result += cards[i] - '0';
    else {
      if (cards[i] == 'A') {
        result += 1;
        containsA += 1;
      } else
        result += 10;
    }
  }
  while (containsA && result <= 11) {
    result += 10;
    containsA--;
  }
  return result;
}
