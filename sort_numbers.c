/*
7 kyu
Sort Numbers
https://www.codewars.com/kata/5174a4c0f2769dd8b1000003
*/

#include <stddef.h>
#include <stdlib.h>

static int compare(const void* a, const void* b) {
  return (*(int*)a > *(int*)b ? 1 : (*(int*)a == *(int*)b ? 0 : -1));
}

void sort_ascending(size_t length, int array[length]) {
  qsort(array, length, sizeof(int), compare);
}
