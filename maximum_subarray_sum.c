/*
5 kyu
Maximum subarray sum
https://www.codewars.com/kata/54521e9ec8e60bc4de000d6c
*/

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSequence(const int array[], size_t n) {
  int result = 0;
  if (n > 0) {
    int max_sum = array[0];
    int current_sum = max_sum;
    for (size_t i = 1; i < n; i++) {
      current_sum = MAX(array[i], current_sum + array[i]);
      max_sum = MAX(max_sum, current_sum);
    }
    result = MAX(max_sum, 0);
  }
  return result;
}
