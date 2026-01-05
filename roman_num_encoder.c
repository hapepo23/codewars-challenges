/*
6 kyu
Roman Numerals Encoder
https://www.codewars.com/kata/51b62bf6a9c58071c600001b
*/

#include <stdlib.h>
#include <string.h>

char* solution(int n) {
  char* result = calloc(100, sizeof(char));
  char* rnum[4][10] = {
      {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
      {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
      {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
      {"", "M", "MM", "MMM", "?", "?", "?", "?", "?", "?"}};
  int inum[4];
  inum[3] = n / 1000;
  int rem = n % 1000;
  inum[2] = rem / 100;
  rem = rem % 100;
  inum[1] = rem / 10;
  inum[0] = rem % 10;
  for (int pos = 3; pos >= 0; pos--) {
    strcat(result, rnum[pos][inum[pos]]);
  }
  return result;
}
