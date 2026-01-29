/*
5 kyu
Common Denominators
https://www.codewars.com/kata/54d7660d2daf68c619000d95
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long Fraction[2];

Fraction* convertFrac(const Fraction[], unsigned n);

static void printArray(size_t n, const Fraction array[n]) {
  printf("{");
  for (size_t i = 0; i < n; i++)
    printf("{%lld, %lld}%s", array[i][0], array[i][1],
           (i == n - 1) ? "" : ", ");
  printf("}");
}

static void dotest(size_t n,
                   const Fraction input[n],
                   const Fraction expected[n]) {
  Fraction* actual = convertFrac(input, n);
  const size_t mem_size = n * sizeof(*expected);
  printf("input    = ");
  printArray(n, input);
  printf("\nexpected = ");
  printArray(n, expected);
  printf("\nactual   = ");
  printArray(n, actual);
  printf("\n%s\n\n", memcmp(actual, expected, mem_size) == 0 ? "OK" : "FAIL");
  free(actual);
}

int main() {
  {
    long long data[3][2] = {{1, 2}, {1, 3}, {1, 4}};
    dotest(3, data, (Fraction[]){{6, 12}, {4, 12}, {3, 12}});
  }
  {
    long long data[3][2] = {{77, 130}, {84, 131}, {3, 4}};
    dotest(3, data,
           (Fraction[]){{20174, 34060}, {21840, 34060}, {25545, 34060}});
  }
  {
    long long data[4][2] = {{1, 1}, {3, 1}, {4, 1}, {5, 1}};
    dotest(4, data, (Fraction[]){{1, 1}, {3, 1}, {4, 1}, {5, 1}});
  }
  {
    long long data[2][2] = {{27115, 5262}, {87546, 11111111}};
    dotest(2, data,
           (Fraction[]){{301277774765, 58466666082}, {460667052, 58466666082}});
  }

  {
    long long data[3][2] = {{26, 52}, {76, 228}, {31, 124}};
    dotest(3, data, (Fraction[]){{6, 12}, {4, 12}, {3, 12}});
  }
  return 0;
}
