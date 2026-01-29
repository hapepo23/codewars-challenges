/*
5 kyu
Mean Square Error
https://www.codewars.com/kata/51edd51599a189fe7f000015
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double mean_square_error(size_t n, const int a[n], const int b[n]);

static char* stringify_array(size_t n, const int array[n]) {
  char *s = malloc(sizeof "{  }" + n * (20 + sizeof ", " - 1)), *p = s;
  p += sprintf(p, "{ ");
  for (size_t i = 0; i < n; i++)
    p += sprintf(p, "%d%s", array[i], (i == n - 1) ? "" : ", ");
  p += sprintf(p, " }");
  return s;
}

static void do_test(size_t n,
                    const int arr_a[n],
                    const int arr_b[n],
                    double expected) {
  double submitted = mean_square_error(n, arr_a, arr_b);
  char* str_a = stringify_array(n, arr_a);
  char* str_b = stringify_array(n, arr_b);
  printf("arr_a = %s\narr_b = %s\nSubmitted: %.17g\nExpected:  %.17g\n%s\n\n",
         str_a, str_b, submitted, expected,
         fabs(submitted - expected) < 1e-6 ? "OK" : "FAIL");
  free(str_a);
  free(str_b);
}

int main(void) {
  {
    const int a[3] = {1, 2, 3};
    const int b[3] = {4, 5, 6};
    double expected = 9.0;
    do_test(3, a, b, expected);
  }
  {
    const int a[4] = {10, 20, 10, 2};
    const int b[4] = {10, 25, 5, -2};
    double expected = 16.5;
    do_test(4, a, b, expected);
  }
  {
    const int a[2] = {0, -1};
    const int b[2] = {-1, 0};
    double expected = 1.0;
    do_test(2, a, b, expected);
  }
  {
    const int a[2] = {10, 10};
    const int b[2] = {10, 10};
    double expected = 0.0;
    do_test(2, a, b, expected);
  }
  return 0;
}
