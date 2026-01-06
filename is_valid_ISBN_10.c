/*
5 kyu
ISBN-10 Validation
https://www.codewars.com/kata/51fc12de24a9d8cb0e000001
*/

#include <stdbool.h>
#include <string.h>

bool is_valid_ISBN_10(const char* ISBN) {
  if (strlen(ISBN) != 10)
    return false;
  for (unsigned int i = 0; i < 9; i++) {
    if (ISBN[i] < '0' || ISBN[i] > '9')
      return false;
  }
  if ((ISBN[9] < '0' || ISBN[9] > '9') && ISBN[9] != 'X')
    return false;
  unsigned int c = 0;
  for (unsigned int i = 0; i < 9; i++) {
    c += (i + 1) * ((unsigned)ISBN[i] - '0');
  }
  if (ISBN[9] == 'X')
    c += 100;
  else
    c += 10 * ((unsigned)ISBN[9] - '0');
  return (c % 11) == 0;
}
