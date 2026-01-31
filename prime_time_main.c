/*
5 kyu
(Ready for) Prime Time
https://www.codewars.com/kata/521ef596c106a935c0000519
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prime(unsigned m, size_t* length, unsigned primes[]);

static char* stringify_array(size_t len, const unsigned array[len]) {
  char* s = malloc(sizeof "{  }" + len * (20 + sizeof ", " - 1));
  char* p = s;
  p += sprintf(p, "{ ");
  for (size_t i = 0; i < len; i++)
    p += sprintf(p, "%u%s", array[i], (i == len - 1) ? "" : ", ");
  p += sprintf(p, " }");
  return realloc(s, p - s + 1);
}

static void tester(unsigned m,
                   size_t exp_len,
                   const unsigned expected[exp_len]) {
  const size_t mem_size = exp_len * sizeof *expected;
  unsigned* actual = malloc(mem_size);
  size_t act_len = 42;
  prime(m, &act_len, actual);
  char* str_exp = stringify_array(exp_len, expected);
  char* str_act = stringify_array(act_len, actual);
  printf("for m = %u\nexpected %s\ngot      %s\n%s\n\n", m, str_exp, str_act,
         strcmp(str_exp, str_act) == 0 ? "OK" : "FAIL");
  free(str_exp);
  free(str_act);
  free(actual);
}

int main(void) {
  {
    unsigned m = 0;
    const unsigned* expected = NULL;
    tester(m, 0, expected);
  }
  {
    unsigned m = 1;
    const unsigned* expected = NULL;
    tester(m, 0, expected);
  }
  {
    unsigned m = 2;
    const unsigned expected[1] = {2};
    tester(m, 1, expected);
  }
  {
    unsigned m = 5;
    const unsigned expected[3] = {2, 3, 5};
    tester(m, 3, expected);
  }
  {
    unsigned m = 10;
    const unsigned expected[4] = {2, 3, 5, 7};
    tester(m, 4, expected);
  }
  {
    unsigned m = 15;
    const unsigned expected[6] = {2, 3, 5, 7, 11, 13};
    tester(m, 6, expected);
  }
  {
    unsigned m = 25;
    const unsigned expected[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    tester(m, 9, expected);
  }
  {
    unsigned m = 35;
    const unsigned expected[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    tester(m, 11, expected);
  }
  {
    unsigned m = 50;
    const unsigned expected[15] = {2,  3,  5,  7,  11, 13, 17, 19,
                                   23, 29, 31, 37, 41, 43, 47};
    tester(m, 15, expected);
  }
  {
    unsigned m = 1000;
    const unsigned expected[168] = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
        47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
        109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
        191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
        269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
        353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
        439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
        523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
        617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
        709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
        811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
        907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    tester(m, 168, expected);
  }
  return 0;
}
