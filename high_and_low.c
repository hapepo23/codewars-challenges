/*
7 kyu
Highest and Lowest
https://www.codewars.com/kata/554b4ac871d6813a03000035
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void high_and_low(const char* strnum, char* result) {
  long int highest = INT32_MIN, lowest = INT32_MAX, number;
  char* succ = (char*)strnum;
  while (*succ) {
    number = strtol(succ, &succ, 10);
    if (number > highest)
      highest = number;
    if (number < lowest)
      lowest = number;
  }
  sprintf(result, "%ld %ld", highest, lowest);
}