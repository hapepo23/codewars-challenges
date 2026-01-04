/*
6 kyu
Your order, please
https://www.codewars.com/kata/55c45be3b2079eccff00010f
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* order_words(char* ordered, const char* words);

static void do_test(const char* input, const char* expected) {
  size_t size = 1 + strlen(input);
  char* user_string = memset(malloc(size), '@', size);
  char* actual = order_words(user_string, input);
  printf("input was:\n\"%s\"\nexpected:\n\"%s\"\ngot:\n\"%s\"\n\n", input,
         expected, actual);
  free(user_string);
}

int main(void) {
  do_test("is2 Thi1s T4est 3a", "Thi1s is2 3a T4est");
  do_test("4of Fo1r pe6ople g3ood th5e the2",
          "Fo1r the2 g3ood 4of th5e pe6ople");
  do_test("d4o dru7nken sh2all w5ith s8ailor wha1t 3we a6",
          "wha1t sh2all 3we d4o w5ith a6 dru7nken s8ailor");
  do_test("", "");
  do_test("3 6 4 2 8 7 5 1 9", "1 2 3 4 5 6 7 8 9");
  return 0;
}
