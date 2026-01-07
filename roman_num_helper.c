/*
4 kyu
Roman Numerals Helper
https://www.codewars.com/kata/51b66044bce5799a7f000003
*/

#include <string.h>

unsigned from_roman(const char* roman) {
  int result = 0;
  const char* p = roman;
  while (*p) {
    const char* pp = p + 1;
    switch (*p) {
      case 'M':
        result += 1000;
        p++;
        break;
      case 'D':
        result += 500;
        p++;
        break;
      case 'L':
        result += 50;
        p++;
        break;
      case 'V':
        result += 5;
        p++;
        break;
      case 'C':
        if (*pp == 'M') {
          result += 900;
          p += 2;
        } else if (*pp == 'D') {
          result += 400;
          p += 2;
        } else {
          result += 100;
          p++;
        }
        break;
      case 'X':
        if (*pp == 'C') {
          result += 90;
          p += 2;
        } else if (*pp == 'L') {
          result += 40;
          p += 2;
        } else {
          result += 10;
          p++;
        }
        break;
      case 'I':
        if (*pp == 'X') {
          result += 9;
          p += 2;
        } else if (*pp == 'V') {
          result += 4;
          p += 2;
        } else {
          result += 1;
          p++;
        }
        break;
    }
  }
  return result;
}

void to_roman(unsigned number, char* roman) {
  char* rnum[4][10] = {
      {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
      {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
      {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
      {"", "M", "MM", "MMM", "MMMM", "?", "?", "?", "?", "?"}};
  unsigned inum[4];
  inum[3] = number / 1000;
  unsigned rem = number % 1000;
  inum[2] = rem / 100;
  rem = rem % 100;
  inum[1] = rem / 10;
  inum[0] = rem % 10;
  *roman = '\0';
  for (int pos = 3; pos >= 0; pos--) {
    strcat(roman, rnum[pos][inum[pos]]);
  }
}
