/*
5 kyu
Mean Square Error
https://www.codewars.com/kata/51edd51599a189fe7f000015
*/

#include <stddef.h>

double mean_square_error(size_t n, const int a[n], const int b[n]) {
  double sum = 0.0;
  for (size_t i = 0; i < n; i++) {
    double diff = (double)a[i] - (double)b[i];
    sum += diff * diff;
  }
  return sum / (double)n;
}
