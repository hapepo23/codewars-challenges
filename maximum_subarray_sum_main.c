/*
5 kyu
Maximum subarray sum
https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c
*/

#include <stddef.h>
#include <stdio.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof *(array))

int maxSequence(const int array[], size_t n);

static void printArray(size_t length, const int array[length]) {
  printf("{ ");
  for (size_t i = 0; i < length; i++)
    printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
  printf(" }");
}

static void doTest(size_t n, const int array[n], int expected) {
  const int actual = maxSequence(array, n);
  printf("array = ");
  printArray(n, array);
  printf("\n");
  printf("expected %d but got %d\n%s\n\n", expected, actual,
         expected == actual ? "OK" : "FAIL");
}

int main(void) {
  doTest(0, NULL, 0);
  {
    const int array[] = {111};
    doTest(ARRAY_LENGTH(array), array, 111);
  }
  {
    const int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    doTest(ARRAY_LENGTH(array), array, 6);
  }
  {
    const int array[] = {-2, -1, -3, -4, -1, -2, -1, -5, -4};
    doTest(ARRAY_LENGTH(array), array, 0);
  }
  {
    const int array[] = {7,  4,   11,  -11, 39,  36,  10, -6,
                         37, -10, -32, 44,  -26, -34, 43, 43};
    doTest(ARRAY_LENGTH(array), array, 155);
  }
  return 0;
}
