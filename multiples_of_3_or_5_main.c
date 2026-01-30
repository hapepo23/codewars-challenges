/*
6 kyu
Multiples of 3 or 5
https://www.codewars.com/kata/514b92a657cdc65150000006
*/

#include <stdio.h>

int solution(int number);

static void do_test(int number, int expected) {
  int submitted = solution(number);
  printf("n = %d, submitted = %d, expected = %d -> %s\n\n", number, submitted,
         expected, submitted == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(3, 0);
  do_test(4, 3);
  do_test(5, 3);
  do_test(6, 8);
  do_test(7, 14);
  do_test(10, 23);
  do_test(20, 78);
  return 0;
}
