/*
6 kyu
Find the odd int
https://www.codewars.com/kata/54da5a58ea159efa38000836
*/

#include <stdio.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(expected, array) do_test(ARR_LEN(array), array, expected)

int find_odd(size_t length, const int array[length]);

static void print_array(size_t length, const int array[length]) {
  printf("{");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf("}");
}

static void do_test(size_t length, const int array[length], int expected) {
  int actual = find_odd(length, array);
  printf("For array = ");
  print_array(length, array);
  printf(" expected %d, but got %d. %s\n", expected, actual,
         (expected == actual) ? "OK." : "WRONG.");
}

int main(void) {
  fixed_test(
      5, ((int[]){20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5}));
  fixed_test(-1, ((int[]){1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}));
  fixed_test(5, ((int[]){20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5}));
  fixed_test(10, ((int[]){10}));
  fixed_test(10, ((int[]){1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}));
  fixed_test(1, ((int[]){5, 4, 3, 2, 1, 5, 4, 3, 2, 10, 10}));
  return 0;
}
