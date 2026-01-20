/*
7 kyu
Sort Numbers
https://www.codewars.com/kata/5174a4c0f2769dd8b1000003
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))
#define fixed_test(array, expected) do_test(ARR_LEN(array), array, expected)

void sort_ascending(size_t length, int array[length]);

static void print_array(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void do_test(size_t length,
                    const int input[length],
                    const int expected[length]) {
  if (length == 0) {
    int* const actual = NULL;
    sort_ascending(length, actual);
    printf("input: 0, output: %p\nOK\n\n", actual);
    return;
  }
  const size_t mem_size = length * sizeof *expected;
  int* const actual = memcpy(malloc(mem_size), input, mem_size);
  sort_ascending(length, actual);
  printf("input:    ");
  print_array(length, input);
  printf("\nexpected: ");
  print_array(length, expected);
  printf("\nactual:   ");
  print_array(length, actual);
  printf("\n");
  printf("%s\n\n", memcmp(actual, expected, mem_size) == 0 ? "OK" : "FAILED");
  free(actual);
}

int main(void) {
  do_test(0, NULL, NULL);
  fixed_test(((int[]){1, 2, 3, 10, 5}), ((int[]){1, 2, 3, 5, 10}));
  fixed_test(((int[]){-8, 22, 3, 16, -30}), ((int[]){-30, -8, 3, 16, 22}));
  fixed_test(((int[]){666}), ((int[]){666}));
  fixed_test(((int[]){INT_MAX, 0}), ((int[]){0, INT_MAX}));
  fixed_test(((int[]){5, 5, 0, 0, 4, -6}), ((int[]){-6, 0, 0, 4, 5, 5}));
  fixed_test(((int[]){INT_MIN, INT_MAX, 0, 1 << 15}),
             ((int[]){INT_MIN, 0, 1 << 15, INT_MAX}));
  fixed_test(((int[]){INT_MIN + 1, INT_MIN, INT_MAX, INT_MAX - 1, 0, 1 << 15,
                      (1 << 15) - 1}),
             ((int[]){INT_MIN, INT_MIN + 1, 0, (1 << 15) - 1, 1 << 15,
                      INT_MAX - 1, INT_MAX}));
  fixed_test(((int[]){-(1 << 20), (1 << 20), INT_MIN, INT_MAX, 0}),
             ((int[]){INT_MIN, -(1 << 20), 0, (1 << 20), INT_MAX}));
  return 0;
}
