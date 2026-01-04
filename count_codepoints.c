/*
7 kyu
Count of codepoints in a UTF-8 string
https://www.codewars.com/kata/68b8e7f8ce76e77dcfb77e8a
*/

#include <stddef.h>
#include <string.h>

size_t count_codepoints(const char* utf8) {
  size_t len = 0;
  while (*utf8) {
    if ((*utf8 & 0xC0) != 0x80)
      len++;
    utf8++;
  }
  return len;
}
