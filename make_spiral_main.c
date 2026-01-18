/*
3 kyu
Make a spiral
https://www.codewars.com/kata/534e01fbbb17187c7e0000c6
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spiralize(unsigned n, int spiral[n][n]);

static void print_matrix(unsigned n, const int matrix[n][n]) {
  for (unsigned i = 0; i < n; i++) {
    for (unsigned j = 0; j < n; j++)
      printf("%d", matrix[i][j]);
    printf("\n");
  }
}

static void do_test(unsigned n, const int expected[n][n]) {
  int(*actual)[n][n] = memset(malloc(sizeof *actual), 5, sizeof *actual);
  spiralize(n, *actual);
  printf("nxn = %dx%d ...", n, n);
  puts("\nexpected:");
  print_matrix(n, expected);
  puts("but got:");
  print_matrix(n, *actual);
  printf("--> %s\n\n",
         memcmp(actual, expected, sizeof *actual) == 0 ? "OK" : "ERROR");
  free(actual);
}

int main(void) {
  do_test(2, (int[2][2]){{
                             1,
                             1,
                         },
                         {0, 1}});
  do_test(5, (int[5][5]){{1, 1, 1, 1, 1},
                         {0, 0, 0, 0, 1},
                         {1, 1, 1, 0, 1},
                         {1, 0, 0, 0, 1},
                         {1, 1, 1, 1, 1}});
  do_test(8, (int[8][8]){{1, 1, 1, 1, 1, 1, 1, 1},
                         {0, 0, 0, 0, 0, 0, 0, 1},
                         {1, 1, 1, 1, 1, 1, 0, 1},
                         {1, 0, 0, 0, 0, 1, 0, 1},
                         {1, 0, 1, 0, 0, 1, 0, 1},
                         {1, 0, 1, 1, 1, 1, 0, 1},
                         {1, 0, 0, 0, 0, 0, 0, 1},
                         {1, 1, 1, 1, 1, 1, 1, 1}});
  do_test(14, (int[14][14]){{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}});
  return 0;
}
