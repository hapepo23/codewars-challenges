/*
6 kyu
Take a Ten Minutes Walk
https://www.codewars.com/kata/54da539698b8a2ad76000228
*/

#include <stdbool.h>
#include <string.h>

bool isValidWalk(const char* walk) {
  bool result = false;
  if (strlen(walk) == 10) {
    const char* p = walk;
    int ns = 0, ew = 0;
    while (*p) {
      switch (*p) {
        case 'n':
          ns++;
          break;
        case 's':
          ns--;
          break;
        case 'e':
          ew++;
          break;
        case 'w':
          ew--;
          break;
      }
      p++;
    }
    result = (ns == 0 && ew == 0);
  }
  return result;
}
