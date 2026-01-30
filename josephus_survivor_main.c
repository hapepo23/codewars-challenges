/*
5 kyu
Josephus Survivor
https://www.codewars.com/kata/555624b601231dc7a400017a
*/

#include <stdio.h>

int josephus_survivor(int n, int k);

void tester(int n, int k, int exp) {
  int actual = josephus_survivor(n, k);
  printf("n = %d, k = %d\nActual: %i, Expected: %i\n%s\n\n", n, k, actual, exp,
         actual == exp ? "OK" : "FAIL");
}

int main(void) {
  tester(7, 3, 4);
  tester(11, 19, 10);
  tester(1, 300, 1);
  tester(14, 2, 13);
  tester(100, 1, 100);
  return 0;
}
