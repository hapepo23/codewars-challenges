/*
1 kyu
7×7 Skyscrapers
https://www.codewars.com/kata/5917a2205ffc30ec3a0000a8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** SolvePuzzle(int* clues);

static int clues[][28] = {{7, 0, 0, 0, 2, 2, 3, 0, 0, 3, 0, 0, 0, 0,
                           3, 0, 3, 0, 0, 5, 0, 0, 0, 0, 0, 5, 0, 4},
                          {0, 2, 3, 0, 2, 0, 0, 5, 0, 4, 5, 0, 4, 0,
                           0, 4, 2, 0, 0, 0, 6, 5, 2, 2, 2, 2, 4, 1},
                          {3, 3, 2, 1, 2, 2, 3, 4, 3, 2, 4, 1, 4, 2,
                           2, 4, 1, 4, 5, 3, 2, 3, 1, 4, 2, 5, 2, 3}};

int outcomes[][7][7] = {
    {{1, 5, 6, 7, 4, 3, 2},
     {2, 7, 4, 5, 3, 1, 6},
     {3, 4, 5, 6, 7, 2, 1},
     {4, 6, 3, 1, 2, 7, 5},
     {5, 3, 1, 2, 6, 4, 7},
     {6, 2, 7, 3, 1, 5, 4},
     {7, 1, 2, 4, 5, 6, 3}},
    {{7, 6, 2, 1, 5, 4, 3},
     {1, 3, 5, 4, 2, 7, 6},
     {6, 5, 4, 7, 3, 2, 1},
     {5, 1, 7, 6, 4, 3, 2},
     {4, 2, 1, 3, 7, 6, 5},
     {3, 7, 6, 2, 1, 5, 4},
     {2, 4, 3, 5, 6, 1, 7}},
    {{2, 1, 4, 7, 6, 5, 3},
     {6, 4, 7, 3, 5, 1, 2},
     {1, 2, 3, 6, 4, 7, 5},
     {5, 7, 6, 2, 3, 4, 1},
     {4, 3, 5, 1, 2, 6, 7},
     {7, 6, 2, 5, 1, 3, 4},
     {3, 5, 1, 4, 7, 2, 6}},
};

static void do_test(int testno, int clues[28], int expected[7][7]) {
  int** puzzle = SolvePuzzle(clues);
  int count = 0;
  for (int i = 0; i < 7; i++) {
    if (memcmp(puzzle[i], expected[i], 7 * sizeof(int)))
      count++;
    free(puzzle[i]);
  }
  printf("Test #%d ok: %s\n", testno, count ? "false" : "true");
  free(puzzle);
}

int main(void) {
  do_test(1, clues[0], outcomes[0]);
  do_test(2, clues[1], outcomes[1]);
  do_test(3, clues[2], outcomes[2]);
  return 0;
}
