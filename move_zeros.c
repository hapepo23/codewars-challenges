/*
5 kyu
Moving Zeros To The End
https://www.codewars.com/kata/52597aa56021e91c93000cb0
*/

#include <stddef.h>
#include <string.h>

void move_zeros(size_t len, int arr[len]) {
  if (len == 0)
    return;
  size_t count = 0;
  size_t lm1 = len - 1;
  for (size_t i = 0; i < lm1 - count; i++) {
    while (arr[i] == 0 && count < lm1) {
      memmove(arr + i, arr + i + 1, (lm1 - i) * sizeof(int));
      arr[lm1] = 0;
      count++;
    }
  }
}
