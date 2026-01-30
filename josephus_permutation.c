/*
5 kyu
Josephus Permutation
https://www.codewars.com/kata/5550d638a99ddb113e0000a2
*/

#include <stddef.h>

void josephus_permutation(size_t n,
                          int permuted[n],
                          const int array[n],
                          size_t k) {
  int temp[n];
  size_t remaining = n;
  size_t index = 0;
  for (size_t i = 0; i < n; i++)
    temp[i] = array[i];
  for (size_t out = 0; out < n; out++) {
    index = (index + k - 1) % remaining;
    permuted[out] = temp[index];
    for (size_t j = index; j + 1 < remaining; j++)
      temp[j] = temp[j + 1];
    remaining--;
  }
}
