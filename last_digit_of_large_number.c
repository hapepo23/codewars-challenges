/*
5 kyu
Last digit of a large number
https://www.codewars.com/kata/5511b2f550906349a70004e1
*/

#include <string.h>

int last_digit(const char* a, const char* b) {
  if (strcmp(b, "0") == 0)
    return 1;
  int base_last_digit = a[strlen(a) - 1] - '0';
  int exp_last_digit = b[strlen(b) - 1] - '0';
  int exp_last_2_digits = (strlen(b) == 1)
                              ? exp_last_digit
                              : (b[strlen(b) - 2] - '0') * 10 + exp_last_digit;
  int x = exp_last_2_digits % 4;
  int y = exp_last_digit % 2;
  switch (base_last_digit) {
    case 1:
    case 5:
    case 6:
      return base_last_digit;
    case 4:
    case 9:
      return y == 0 ? (10 - base_last_digit) : base_last_digit;
    case 2:
      return x == 0 ? 6 : (x == 1 ? 2 : (x == 2 ? 4 : 8));
    case 3:
      return x == 0 ? 1 : (x == 1 ? 3 : (x == 2 ? 9 : 7));
    case 7:
      return x == 0 ? 1 : (x == 1 ? 7 : (x == 2 ? 9 : 3));
    case 8:
      return x == 0 ? 6 : (x == 1 ? 8 : (x == 2 ? 4 : 2));
  }
  return 0;
}
