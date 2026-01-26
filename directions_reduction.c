/*
5 kyu
Directions Reduction
https://www.codewars.com/kata/550f22f4d758534c1100025a
*/

#include <stdlib.h>

const char** dirReduc(const char* const array[],
                      int length_in,
                      int* length_out) {
  const char** reduced = malloc(length_in * sizeof *reduced);
  int hv[length_in][2];
  int n = -1;
  for (int i = 0; i < length_in; i++) {
    n++;
    hv[n][0] = 0;
    hv[n][1] = 0;
    switch (array[i][0]) {
      case 'N':
        hv[n][0] = 1;
        break;
      case 'S':
        hv[n][0] = -1;
        break;
      case 'W':
        hv[n][1] = 1;
        break;
      default:
        hv[n][1] = -1;
        break;
    }
    reduced[n] = array[i];
    if (n > 0 && ((hv[n][0] != 0 && hv[n - 1][0] != 0 &&
                   (hv[n][0] + hv[n - 1][0]) == 0) ||
                  (hv[n][1] != 0 && hv[n - 1][1] != 0 &&
                   (hv[n][1] + hv[n - 1][1]) == 0)))
      n -= 2;
  }
  *length_out = n + 1;
  return reduced;
}