/*
5 kyu
Land perimeter
https://www.codewars.com/kata/5839c48f0cf94640a20001d3
*/

#include <stdio.h>
#include <string.h>

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixed_test(land, expected) \
  do_test(ARR_LEN(land), ARR_LEN(*land), land, expected)

void land_perimeter(size_t rows,
                    size_t cols,
                    const char land[rows][cols],
                    char* result);

static void print_grid(size_t rows, size_t cols, const char grid[rows][cols]) {
  printf("{\n");
  for (size_t row = 0; row < rows; row++) {
    printf("\t{");
    for (size_t col = 0; col < cols; col++)
      printf("'%c'%s", grid[row][col], (col == cols - 1) ? "" : ", ");
    printf("}%s\n", (row == rows - 1) ? "" : ",");
  }
  printf("}\n");
}

static void do_test(size_t rows,
                    size_t cols,
                    const char land[rows][cols],
                    const char* expected) {
  char actual[64] = "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
  land_perimeter(rows, cols, land, actual);
  printf("for land %zux%zu:\n", rows, cols);
  print_grid(rows, cols, land);
  printf("expected:\n\"%s\"\nactual:\n\"%s\"\n-----\n", expected, actual);
}

int main(void) {
  fixed_test(((char[][6]){"OXOOOX", "OXOXOO", "XXOOOX", "OXXXOO", "OOXOOX",
                          "OXOOOO", "OOXOOX", "OOXOOO", "OXOOOO", "OXOOXX"}),
             "Total land perimeter: 60");
  fixed_test(((char[][5]){"OXOOO", "OOXXX", "OXXOO", "XOOOO", "XOOOO", "XXXOO",
                          "XOXOO", "OOOXO", "OXOOX", "XOOOO", "OOOXO"}),
             "Total land perimeter: 52");
  fixed_test(
      ((char[][8]){"XXXXXOOO", "OOXOOOOO", "OOOOOOXO", "XXXOOOXO", "OXOXXOOX"}),
      "Total land perimeter: 40");
  fixed_test(((char[][7]){"XOOOXOO", "OXOOOOO", "XOXOXOO", "OXOXXOO", "OOOOOXX",
                          "OOOXOXX", "XXXXOXO"}),
             "Total land perimeter: 54");
  fixed_test(((char[][6]){"OOOOXO", "XOXOOX", "XXOXOX", "XOXOOO", "OOOOOO",
                          "OOOXOO", "OOXXOO"}),
             "Total land perimeter: 40");
  fixed_test(((char[][1]){"X"}), "Total land perimeter: 4");
  return 0;
}
