/*
5 kyu
Land perimeter
https://www.codewars.com/kata/5839c48f0cf94640a20001d3
*/

#include <stddef.h>
#include <stdio.h>

void land_perimeter(size_t rows,
                    size_t cols,
                    const char land[rows][cols],
                    char* result) {
  int perimeter = 0;
  char last_column, before_after_rows = 'O';
  for (size_t i = 0; i < rows; i++) {
    last_column = 'O';
    for (size_t j = 0; j < cols; j++) {
      if (land[i][j] != last_column)
        perimeter++;
      last_column = land[i][j];
      if (i == 0 && land[i][j] != before_after_rows)
        perimeter++;
      if (i == rows - 1 && land[i][j] != before_after_rows)
        perimeter++;
      if (i > 0 && land[i][j] != land[i - 1][j])
        perimeter++;
    }
    if (last_column == 'X')
      perimeter++;
  }
  sprintf(result, "Total land perimeter: %d", perimeter);
}