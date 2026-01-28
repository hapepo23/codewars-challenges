/*
5 kyu
String incrementer
https://www.codewars.com/kata/54a91a4883a7de5d7800009c
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* incrementString(const char* str) {
  int ltot = strlen(str);
  char* result = calloc(ltot + 2, sizeof(char));
  const char* p = str + ltot - 1;
  while (p >= str && isdigit(*p))
    p--;
  int lpref = p - str + 1;
  strncpy(result, str, lpref);
  sprintf(result + lpref, "%0*d", ltot - lpref, atoi(str + lpref) + 1);
  return result;
}
