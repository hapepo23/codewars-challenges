/*
4 kyu
Sum of Intervals
https://www.codewars.com/kata/52b7ed099cdc285c300001cd
*/

#include <limits.h>
#include <stdio.h>

#define NLIM 0x10
#define FMT_INT (CHAR_BIT * sizeof(int) / 3 + 1)
#define FMT_ALIGN 0x2
#define FMT_INTVL ((FMT_INT << 1) + 4)
#define OUTPFALIGN ""
#define OUTPFLEN ((sizeof(OUTPFALIGN) + FMT_INTVL + FMT_ALIGN) * NLIM + 1)

struct interval {
  int first;
  int second;
};

int sum_intervals(const struct interval* v, size_t n);

static char* intvl_to_s(char* outpf, const struct interval* v, size_t n) {
  size_t pos = sprintf(outpf, "Intervals:");
  size_t i;
  for (i = 0ul; i < n; ++i)
    pos += sprintf(outpf + pos, "\n%s[%i, %i],", OUTPFALIGN, v[i].first,
                   v[i].second);
  if (i)
    --pos;
  return outpf;
}

void do_test(const struct interval* v, size_t n, int expected) {
  char outpf[OUTPFLEN];
  int actual = sum_intervals(v, n);
  printf(
      "%s\nActual  : %d\n"
      "Expected: %d\n%s\n\n",
      intvl_to_s(outpf, v, n), actual, expected,
      actual == expected ? "OK" : "FAIL");
}

int main(void) {
  do_test(
      (const struct interval[]){{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}},
      5ul, 19);
  do_test((const struct interval[]){{1, 5}}, 1ul, 4);
  do_test((const struct interval[]){{1, 5}, {6, 10}}, 2ul, 8);
  do_test((const struct interval[]){{-5, -1}, {1, 5}}, 2ul, 8);
  do_test((const struct interval[]){{-1000000000, 1000000000}}, 1ul,
          2000000000);
  do_test((const struct interval[]){{0, 20}, {-100000000, 10}, {30, 40}}, 3ul,
          100000030);
  return 0;
}
