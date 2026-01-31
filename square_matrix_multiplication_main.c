/*
5 kyu
Square Matrix Multiplication
https://www.codewars.com/kata/5263a84ffcadb968b6000513
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** matrix_multiplication(const int* const a[], const int* const b[], int n);

static void print_matrix(size_t n, const int* const matrix[n]) {
  printf("{");
  for (size_t row = 0; row < n; row++) {
    printf("\n    {");
    for (size_t col = 0; col < n; col++)
      printf("%d%s", matrix[row][col], (col == n - 1) ? "" : ", ");
    printf("}%s", (row == n - 1) ? "\n" : ",");
  }
  printf("}");
}

static bool equal_matrices(size_t n,
                           const int* const a[n],
                           const int* const b[n]) {
  for (size_t i = 0; i < n; i++)
    if (memcmp(a[i], b[i], n * sizeof **a))
      return false;
  return true;
}

static void do_test(size_t n,
                    const int* const a[n],
                    const int* const b[n],
                    const int* const expected[n]) {
  int** actual = matrix_multiplication(a, b, n);
  bool equal = equal_matrices(n, (const int**)actual, expected);
  printf("a = ");
  print_matrix(n, a);
  printf("\nb = ");
  print_matrix(n, b);
  printf("\nexpected = ");
  print_matrix(n, expected);
  printf("\nactual = ");
  print_matrix(n, (const int**)actual);
  printf("\nexpected == actual ? %s\n\n", equal ? "OK" : "FAIL");
  for (size_t i = 0; i < n; i++)
    free(actual[i]);
  free(actual);
}

int main(void) {
  do_test(1, (const int* [1]){(int[1]){2}}, (const int* [1]){(int[1]){3}},
          (const int* [1]){(int[1]){6}});
  do_test(2, (const int* [2]){(int[2]){1, 2}, (int[2]){3, 2}},
          (const int* [2]){(int[2]){3, 2}, (int[2]){1, 1}},
          (const int* [2]){(int[2]){5, 4}, (int[2]){11, 8}});
  do_test(
      3,
      (const int* [3]){
          (int[3]){1, 2, 3},
          (int[3]){3, 2, 1},
          (int[3]){2, 1, 3},
      },
      (const int* [3]){(int[3]){4, 5, 6}, (int[3]){6, 5, 4}, (int[3]){4, 6, 5}},
      (const int* [3]){(int[3]){28, 33, 29}, (int[3]){28, 31, 31},
                       (int[3]){26, 33, 31}});
  return 0;
}
