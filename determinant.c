/*
4 kyu
Matrix Determinant
https://www.codewars.com/kata/52a382ee44408cea2500074c
*/

#include <stddef.h>
#include <stdlib.h>

static int* create_sub_matrix(size_t size, int* matrix, size_t col) {
  size_t newsize = size - 1;
  int* sub_matrix = (int*)malloc(newsize * newsize * sizeof(int));
  for (size_t r = 1; r < size; r++) {
    for (size_t c = 0; c < col; c++)
      sub_matrix[(r - 1) * newsize + c] = matrix[r * size + c];
    for (size_t c = col + 1; c < size; c++)
      sub_matrix[(r - 1) * newsize + c - 1] = matrix[r * size + c];
  }
  return sub_matrix;
}

int determinant(size_t size, int* matrix) {
  int result = 0;
  if (size == 1)
    result = matrix[0];
  else if (size == 2)
    result = matrix[0] * matrix[3] - matrix[2] * matrix[1];
  else if (size > 2) {
    for (size_t i = 0; i < size; i++) {
      int* sub_matrix = create_sub_matrix(size, matrix, i);
      int cofactor =
          (i % 2 == 0 ? 1 : -1) * matrix[i] * determinant(size - 1, sub_matrix);
      free(sub_matrix);
      result += cofactor;
    }
  }
  return result;
}
