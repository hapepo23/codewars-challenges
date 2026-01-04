/*
8 kyu
Do I get a bonus?
https://www.codewars.com/kata/56f6ad906b88de513f000d96
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* bonus_time(unsigned long long int salary, bool bonus) {
  unsigned long long int result = salary * (bonus ? 10LLU : 1LLU);
  char* result_string = calloc(30, sizeof(char));
  sprintf(result_string, "$%llu", result);
  return result_string;
}
