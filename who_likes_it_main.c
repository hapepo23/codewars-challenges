/*
6 kyu
Who likes it?
https://www.codewars.com/kata/5266876b8f4bf2da9b000362
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

char* likes(size_t n, const char* const names[n]);

static void do_test(size_t n,
                    const char* const names[n],
                    const char* expected) {
  char* actual = likes(n, names);
  printf("Names:\n");
  for (size_t i = 0; i < n; i++)
    printf("%ld: %s\n", i + 1, names[i]);
  printf("expected \"%s\"\nactual   \"%s\"\n%s\n\n", expected, actual,
         strcmp(expected, actual) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main(void) {
  { do_test(0, NULL, "no one likes this"); }
  {
    const char* const names[1] = {"Peter"};
    do_test(ARR_LEN(names), names, "Peter likes this");
  }
  {
    const char* const names[2] = {"Jacob", "Alex"};
    do_test(ARR_LEN(names), names, "Jacob and Alex like this");
  }
  {
    const char* const names[3] = {"Max", "John", "Mark"};
    do_test(ARR_LEN(names), names, "Max, John and Mark like this");
  }
  {
    const char* const names[4] = {"Alex", "Jacob", "Mark", "Max"};
    do_test(ARR_LEN(names), names, "Alex, Jacob and 2 others like this");
  }
  return 0;
}
