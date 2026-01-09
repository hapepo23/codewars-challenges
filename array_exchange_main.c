/*
6 kyu
Array Exchange
https://www.codewars.com/kata/5353212e5ee40d4694001114
*/

#include <stdio.h>
#include <string.h>

#define NLIM 16

void strxchg(char* s1, char* s2);

static void do_test(const char* s1,
                    const char* s2,
                    const char* e1,
                    const char* e2) {
  char a1[NLIM];
  char a2[NLIM];
  strcpy(a1, s1);
  strcpy(a2, s2);
  strxchg(a1, a2);
  printf(
      "Test OK = %s\n"
      "[Input]   \n    S1: [%s]\n    S2: [%s]\n"
      "[Expected]\n    S1: [%s]\n    S2: [%s]\n"
      "[Actual]  \n    S1: [%s]\n    S2: [%s]\n-------\n",
      (strcmp(a1, e1) == 0 && strcmp(a2, e2) == 0) ? "True" : "False", s1, s2,
      e1, e2, a1, a2);
}

int main(void) {
  do_test((const char[]){'1', '2', '3', '4', '5', '6', '7', '\0'},
          (const char[]){'a', 'b', 'c', '\0'},
          (const char[]){'c', 'b', 'a', '\0'},
          (const char[]){'7', '6', '5', '4', '3', '2', '1', '\0'});
  do_test((const char[]){'c', 'b', 'a', '\0'},
          (const char[]){'7', '6', '5', '4', '3', '2', '1', '\0'},
          (const char[]){'1', '2', '3', '4', '5', '6', '7', '\0'},
          (const char[]){'a', 'b', 'c', '\0'});
  return 0;
}
