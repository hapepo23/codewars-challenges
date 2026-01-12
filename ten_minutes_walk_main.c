/*
6 kyu
Take a Ten Minutes Walk
https://www.codewars.com/kata/54da539698b8a2ad76000228
*/

#include <stdbool.h>
#include <stdio.h>

bool isValidWalk(const char* walk);

static void tester(const char* walk, bool expected) {
  bool submitted = isValidWalk(walk);
  static const char* s[2] = {"false", "true"};
  printf("For input \"%s\", expected: %s, submitted: %s -> %s\n", walk,
         s[expected], s[submitted], expected == submitted ? "ok" : "wrong");
}

int main(void) {
  tester("nsnsnsnsns", true);
  tester("nsnsnsnsnn", false);
  tester("wewewewewewe", false);
  tester("w", false);
  tester("nnnsnsnsns", false);
  tester("nnnsnsnsns", false);
  tester("nneeesswww", true);
  tester("eswwnneesw", true);
  return 0;
}
