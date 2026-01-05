/*
5 kyu
Rotate an array matrix
https://www.codewars.com/kata/525a566985a9a47bc8000670
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum direction { CLOCKWISE, COUNTER_CLOCKWISE };

void rotate(size_t rows,
            size_t cols,
            const int matrix[rows][cols],
            enum direction direction,
            int rotated[cols][rows]);

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixed_test(direction, matrix, expected) \
  do_test(ARR_LEN(matrix), ARR_LEN(expected), matrix, direction, expected)

static const char* const names[] =
    {[CLOCKWISE] = "CLOCKWISE", [COUNTER_CLOCKWISE] = "COUNTER_CLOCKWISE"};

static void print_matrix(size_t rows,
                         size_t cols,
                         const int matrix[rows][cols]) {
  printf("{\n");
  for (size_t row = 0; row < rows; row++) {
    printf("\t{");
    for (size_t col = 0; col < cols; col++)
      printf("%d%s", matrix[row][col], (col == cols - 1) ? "" : ", ");
    printf("}\n");
  }
  printf("}\n");
}

static void do_test(size_t rows,
                    size_t cols,
                    const int input[rows][cols],
                    enum direction direction,
                    const int expected[cols][rows]) {
  int(*actual)[cols][rows] = malloc(sizeof *actual);
  rotate(rows, cols, input, direction, *actual);
  puts("matrix:");
  print_matrix(rows, cols, input);
  printf("rotation: %s\n", names[direction]);
  puts("expected:");
  print_matrix(cols, rows, expected);
  puts("got:");
  print_matrix(cols, rows, *actual);
  puts("---");
  free(actual);
}

int main(void) {
  fixed_test(CLOCKWISE,
             ((int[3][3]){
                 {1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
             }),
             ((int[3][3]){
                 {7, 4, 1},
                 {8, 5, 2},
                 {9, 6, 3},
             }));
  fixed_test(COUNTER_CLOCKWISE,
             ((int[3][3]){
                 {1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
             }),
             ((int[3][3]){
                 {3, 6, 9},
                 {2, 5, 8},
                 {1, 4, 7},
             }));
  fixed_test(CLOCKWISE,
             ((int[4][3]){
                 {1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
                 {10, 11, 12},
             }),
             ((int[3][4]){
                 {10, 7, 4, 1},
                 {11, 8, 5, 2},
                 {12, 9, 6, 3},
             }));
  fixed_test(COUNTER_CLOCKWISE,
             ((int[4][3]){
                 {1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
                 {10, 11, 12},
             }),
             ((int[3][4]){
                 {3, 6, 9, 12},
                 {2, 5, 8, 11},
                 {1, 4, 7, 10},
             }));
  fixed_test(CLOCKWISE,
             ((int[1][3]){
                 {1, 2, 3},
             }),
             ((int[3][1]){
                 {1},
                 {2},
                 {3},
             }));
  fixed_test(COUNTER_CLOCKWISE,
             ((int[1][3]){
                 {1, 2, 3},
             }),
             ((int[3][1]){
                 {3},
                 {2},
                 {1},
             }));
  fixed_test(CLOCKWISE,
             ((int[1][1]){
                 {1},
             }),
             ((int[1][1]){
                 {1},
             }));
  fixed_test(COUNTER_CLOCKWISE,
             ((int[1][1]){
                 {1},
             }),
             ((int[1][1]){
                 {1},
             }));
  return 0;
}
