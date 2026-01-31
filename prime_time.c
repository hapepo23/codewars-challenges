/*
5 kyu
(Ready for) Prime Time
https://www.codewars.com/kata/521ef596c106a935c0000519
*/

#include <stddef.h>
#include <string.h>

void prime(unsigned m, size_t* z, unsigned primes[]) {
  *z = 0;
  if (m < 2)
    return;
  unsigned size = (m + 1) / 2;
  unsigned char is_composite[size];
  memset(is_composite, 0, size);
  primes[(*z)++] = 2;
  for (unsigned i = 3; i <= m; i += 2) {
    if (!is_composite[i >> 1]) {
      primes[(*z)++] = i;
      if ((unsigned long long)i * i <= m) {
        for (unsigned j = i * i; j <= m; j += i << 1)
          is_composite[j >> 1] = 1;
      }
    }
  }
}
