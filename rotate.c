/*
5 kyu
Rotate an array matrix
https://www.codewars.com/kata/525a566985a9a47bc8000670
*/

#include <stddef.h>

enum direction { CLOCKWISE, COUNTER_CLOCKWISE };

void rotate(size_t rows,
            size_t cols,
            const int matrix[rows][cols],
            enum direction direction,
            int rotated[cols][rows]) {
  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      rotated[direction == CLOCKWISE ? c : cols - 1 - c]
             [direction == COUNTER_CLOCKWISE ? r : rows - 1 - r] = matrix[r][c];
    }
  }
}
