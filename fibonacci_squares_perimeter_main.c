/*
5 kyu
Perimeter of squares in a rectangle
https://www.codewars.com/kata/559a28007caad2ac4e000083
*/

#include <stdio.h>

typedef unsigned long long ull;

ull perimeter(int n);

static void dotest(int n, ull expected) {
  ull actual = perimeter(n);
  printf("for input = %d, expected %llu, but got %llu\n%s\n\n", n, expected,
         actual, expected == actual ? "OK" : "FAIL");
}

int main(void) {
  dotest(0, 4);
  dotest(5, 80);
  dotest(7, 216);
  dotest(20, 114624);
  dotest(30, 14098308);
  return 0;
}
