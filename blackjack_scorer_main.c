/*
5 kyu
Blackjack Scorer
https://www.codewars.com/kata/534ffb35edb1241eda0015fe
*/

#include <stdio.h>
#include <stdlib.h>

int score_hand(size_t n, const char cards[n]);

static char* hand_repr(size_t n, const char hand[n]) {
  char *str = malloc((sizeof "'A', " - 1) * n + sizeof "{  }"), *p = str;
  p += sprintf(p, "{ ");
  for (size_t i = 0; i < n; i++)
    p += sprintf(p, "'%c'%s", hand[i], (i == n - 1) ? "" : ", ");
  p += sprintf(p, " }");
  return str;
}

static void do_test(size_t n, const char hand[n], int expected) {
  char* cards = hand_repr(n, hand);
  int submitted = score_hand(n, hand);
  printf("For cards: %s\nExpected  : %d\nSubmitted : %d\n%s\n\n", cards,
         expected, submitted, expected == submitted ? "OK" : "ERROR");
  free(cards);
}

int main(void) {
  {
    const char cards[2] = {'2', '3'};
    do_test(2, cards, 5);
  }
  {
    const char cards[3] = {'7', '7', '8'};
    do_test(3, cards, 22);
  }
  {
    const char cards[3] = {'4', '7', '8'};
    do_test(3, cards, 19);
  }
  {
    const char cards[3] = {'K', 'T', 'Q'};
    do_test(3, cards, 30);
  }
  {
    const char cards[2] = {'A', '3'};
    do_test(2, cards, 14);
  }
  {
    const char cards[5] = {'A', '2', 'A', '9', '9'};
    do_test(5, cards, 22);
  }
  {
    const char cards[5] = {'A', 'A', 'A', '9', '9'};
    do_test(5, cards, 21);
  }
  {
    const char cards[5] = {'A', 'A', 'A', 'A', '9'};
    do_test(5, cards, 13);
  }
  {
    const char cards[4] = {'A', 'A', 'A', 'J'};
    do_test(4, cards, 13);
  }
  {
    const char cards[3] = {'8', 'A', 'A'};
    do_test(3, cards, 20);
  }
  {
    const char cards[4] = {'2', 'J', '5', 'A'};
    do_test(4, cards, 18);
  }
  return 0;
}
