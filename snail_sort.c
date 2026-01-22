/*
4 kyu
Snail
https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1
*/

#include <stdlib.h>

static void do_round(size_t size,
                     size_t round_size,
                     const int** matrix,
                     size_t startrow,
                     size_t startcol,
                     int* output) {
  if (round_size == 1)
    output[0] = matrix[startrow][startcol];
  else {
    size_t o = 0;
    for (size_t c = 0; c < round_size - 1; c++)
      output[o++] = matrix[startrow][startcol + c];
    for (size_t r = 0; r < round_size - 1; r++)
      output[o++] = matrix[startrow + r][startcol + round_size - 1];
    for (size_t c = round_size - 1; c > 0; c--)
      output[o++] = matrix[startrow + round_size - 1][startcol + c];
    for (size_t r = round_size - 1; r > 0; r--)
      output[o++] = matrix[startrow + r][startcol];
    if (round_size > 2)
      do_round(size, round_size - 2, matrix, startrow + 1, startcol + 1,
               output + o);
  }
}

int* snail(size_t* outsz, const int** mx, size_t rows, size_t cols) {
  size_t size = rows * cols;
  *outsz = size;
  if (size == 0)
    return NULL;
  int* result = calloc(size, sizeof(int));
  do_round(rows, rows, mx, 0, 0, result);
  return result;
}
