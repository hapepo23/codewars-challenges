/*
5 kyu
Square Matrix Multiplication
https://www.codewars.com/kata/5263a84ffcadb968b6000513
*/

#include <stdlib.h>

int** matrix_multiplication(const int* const a[], const int* const b[], int n) {
  int** result = (int**)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    result[i] = (int*)calloc(n, sizeof(int));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return result;
}
