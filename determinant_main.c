/*
4 kyu
Matrix Determinant
https://www.codewars.com/kata/52a382ee44408cea2500074c
*/

#include <stdio.h>

int determinant(size_t size, const int matrix[size][size]);

static void do_test(size_t size, const int matrix[size][size], int expected) {
  int submitted = determinant(size, matrix);
  char mtx_str[(9 * size + 5) * size + 2];
  size_t position = sprintf(mtx_str, "{\n");
  for (size_t y = 0; y < size; y++) {
    position += sprintf(mtx_str + position, "  {");
    for (size_t x = 0; x < size; x++) {
      position += sprintf(mtx_str + position, "%d%s", matrix[y][x],
                          x < size - 1 ? ", " : "");
    }
    position += sprintf(mtx_str + position, "}%s\n", y < size - 1 ? "," : "");
  }
  position += sprintf(mtx_str + position, "}");
  printf("matrix = %s\nSubmitted: %d\nExpected:  %d\n%s\n\n", mtx_str,
         submitted, expected, submitted == expected ? "OK" : "ERROR");
}

int main(void) {
  {
    const int matrix[1][1] = {{5}};
    do_test(1, matrix, 5);
  }
  {
    const int matrix[2][2] = {{4, 6}, {3, 8}};
    do_test(2, matrix, 14);
  }
  {
    const int matrix[3][3] = {{2, 4, 2}, {3, 1, 1}, {1, 2, 0}};
    do_test(3, matrix, 10);
  }
  {
    const int matrix[4][4] = {
        {2, 3, 7, 1},
        {7, 1, 9, 8},
        {8, 6, 1, 4},
        {0, 1, 4, 2},
    };
    do_test(4, matrix, 681);
  }
  {
    const int matrix[6][6] = {
        {1, 2, 5, -7, 5, 3}, {7, -4, 6, 3, 9, 11},   {22, -16, 4, 7, 8, 1},
        {-8, 0, 9, 5, 8, 1}, {77, -6, -5, 1, 23, 3}, {9, 6, -7, 3, 4, 5},
    };
    do_test(6, matrix, -3487464);
  }
  return 0;
}
