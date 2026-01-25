/*
4 kyu
Sum of Intervals
https://www.codewars.com/kata/52b7ed099cdc285c300001cd
*/

#include <stdlib.h>

struct interval {
  int first;
  int second;
};

static int compare_intervals(const void* a, const void* b) {
  const struct interval* x = a;
  const struct interval* y = b;
  return x->first - y->first;
}

int sum_intervals(const struct interval* v, size_t n) {
  if (n == 0)
    return 0;
  struct interval* tmp = malloc(n * sizeof(*v));
  for (size_t i = 0; i < n; i++)
    tmp[i] = v[i];
  qsort(tmp, n, sizeof(*tmp), compare_intervals);
  int sum = 0;
  int cur_start = tmp[0].first;
  int cur_end = tmp[0].second;
  for (size_t i = 1; i < n; i++) {
    if (tmp[i].first <= cur_end) {
      if (tmp[i].second > cur_end)
        cur_end = tmp[i].second;
    } else {
      sum += cur_end - cur_start;
      cur_start = tmp[i].first;
      cur_end = tmp[i].second;
    }
  }
  sum += cur_end - cur_start;
  free(tmp);
  return sum;
}
