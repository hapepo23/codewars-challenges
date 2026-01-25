/*
5 kyu
https://www.codewars.com/kata/513e08acc600c94f01000001
*/

#include <stdio.h>

#define LIMIT_0_255(X) (X > 255 ? 255 : (X < 0 ? 0 : X))

void rgb(int r, int g, int b, char hex[6 + 1]) {
  sprintf(hex, "%02X%02X%02X", LIMIT_0_255(r), LIMIT_0_255(g), LIMIT_0_255(b));
}
