/*
5 kyu
ROT13
https://www.codewars.com/kata/52223df9e8f98c7aa7000062
*/

#include <ctype.h>

char* rot13(char* str_out, const char* str_in) {
  char* p = str_out;
  while (*str_in) {
    if (islower(*str_in))
      *p = 'a' + (*str_in - 'a' + 13) % 26;
    else if (isupper(*str_in))
      *p = 'A' + (*str_in - 'A' + 13) % 26;
    else
      *p = *str_in;
    str_in++;
    p++;
  }
  *p = '\0';
  return str_out;
}
