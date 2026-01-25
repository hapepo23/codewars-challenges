/*
5 kyu
Moving Zeros To The End
https://www.codewars.com/kata/52597aa56021e91c93000cb0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move_zeros(size_t len, int arr[len]);

void do_test(size_t len, int* arr, int* expected) {
  printf("Array before: ");
  for (size_t i = 0; i < len; i++)
    printf("%d ", arr[i]);
  puts("");
  move_zeros(len, arr);
  printf("Array after : ");
  for (size_t i = 0; i < len; i++)
    printf("%d ", arr[i]);
  puts("");
  printf("Expected    : ");
  for (size_t i = 0; i < len; i++)
    printf("%d ", expected[i]);
  puts("");
  printf("%s\n\n",
         memcmp(arr, expected, sizeof(int) * len) == 0 ? "OK" : "ERROR");
}

int main(void) {
  do_test(8, ((int[]){0, 0, 0, 0, 0, 0, 0, 1}),
          ((int[]){1, 0, 0, 0, 0, 0, 0, 0}));
  do_test(8, ((int[]){0, 1, 0, 2, 0, 3, 4, 5}),
          ((int[]){1, 2, 3, 4, 5, 0, 0, 0}));
  do_test(
      20, ((int[]){9, 0, 0, 9, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 9, 0, 0, 0, 0, 9}),
      ((int[]){9, 9, 1, 2, 1, 1, 3, 1, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
  do_test(2, ((int[]){0, 0}), ((int[]){0, 0}));
  do_test(2, ((int[]){1, 2}), ((int[]){1, 2}));
  do_test(2, ((int[]){0, 2}), ((int[]){2, 0}));
  do_test(2, ((int[]){2, 0}), ((int[]){2, 0}));
  do_test(1, ((int[]){0}), ((int[]){0}));
  do_test(0, ((int[]){}), ((int[]){}));
  return 0;
}
