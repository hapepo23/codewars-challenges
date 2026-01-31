/*
5 kyu
Snakes and Ladders
https://www.codewars.com/kata/587136ba2eefcb92a9000027
*/

#include <stdio.h>
#include <string.h>

const char* snakes_ladders(int die1, int die2);

void do_test(int die1, int die2, const char* expected) {
  const char* actual;
  actual = snakes_ladders(die1, die2);
  printf(
      "Dies: %d %d\nexpected: %s\n"
      "actual  : %s -> %s\n\n",
      die1, die2, expected, actual,
      strcmp(expected, actual) == 0 ? "OK" : "FAIL");
}

int main(void) {
  do_test(1, 1, "Player 1 is on square 38");
  do_test(1, 5, "Player 1 is on square 44");
  do_test(6, 2, "Player 2 is on square 31");
  do_test(1, 1, "Player 1 is on square 25");
  do_test(1, 2, "Player 1 is on square 84");
  do_test(1, 2, "Player 2 is on square 34");
  do_test(2, 1, "Player 1 is on square 94");
  do_test(1, 2, "Player 2 is on square 37");
  do_test(6, 2, "Player 1 is on square 98");
  do_test(4, 6, "Player 2 is on square 47");
  do_test(1, 1, "Player 1 Wins!");
  do_test(6, 6, "Game over!");
  do_test(6, 6, "Game over!");
  return 0;
}
